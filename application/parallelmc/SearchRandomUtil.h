/* 
 * SearchRandomUtil.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, Charles Killian, James W. Anderson
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    * Neither the names of Duke University nor The University of
 *      California, San Diego, nor the names of the authors or contributors
 *      may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ----END-OF-LEGAL-STUFF---- */
#ifndef _SEARCH_RANDOM_UTIL_
#define _SEARCH_RANDOM_UTIL_

#include <fstream>
#include <sstream>

#include <pthread.h>

#include "MCMessage.h"
#include "MCMessagePrefixCount.h"
#include "MCMessagePrefixReply.h"
#include "MCMessagePrefixRequest.h"
#include "mvector.h"
#include "params.h"
#include "PrefixTree.h"
#include "Printable.h"
#include "StateCommunicator.h"
#include "SimRandomUtil.h"
#include "Simulator.h"

class SearchRandomUtil : public SimRandomUtil {
protected:
  UIntList currentSelections;
  UIntList currentOutOf;
  UIntList* pathPrefix;
  UIntList* pathPrefixOutOf;
  pthread_mutex_t prefixMutex;


  std::vector<unsigned> depths;

  std::vector<UIntList*> assignedPrefixes;
  std::vector<UIntList*> assignedBounds;
  uint currentPrefix;

  int depthIncrement;
  std::vector<int> doneEarly; //True when every path searched at this prefix at this depth so far finished before the depth.
  bool verbose;
  macemc::PrefixTree prefixTree;
  bool logPrefixes;
  bool hasPrefix;

  SearchRandomUtil(bool v = true) : currentSelections(), currentOutOf(), pathPrefix(NULL), pathPrefixOutOf(NULL), depths(), assignedPrefixes(), assignedBounds(), currentPrefix(0), depthIncrement(params::get<int>("SEARCH_DEPTH", 5)), doneEarly(), verbose(v), prefixTree(), logPrefixes(false), hasPrefix(false)
    {
      pthread_mutex_init(&prefixMutex, NULL);
    }

  void sendPrefixRequestToRelay() {
    macemc::MCMessagePrefixRequest *prefix_request_msg;
    macemc::StateCommunicator<macemc::MCMessage> *communicator = macemc::__Simulator__::getCommunicator();
    unsigned nodeRank = macemc::__Simulator__::getNodeRank();

    prefix_request_msg = new macemc::MCMessagePrefixRequest(nodeRank, macemc::__Simulator__::getProcessRank(), nodeRank, 0, 1);
    
    Log::log("prefixes") << "Sending request for a prefix to relay" << Log::endl;

    communicator->put(prefix_request_msg, ENDPOINT_WORKER);
    communicator->deliver(ENDPOINT_WORKER);
  }

  void sendPrefixCountToRelay() {
    macemc::MCMessagePrefixCount *prefix_count_msg;
    macemc::StateCommunicator<macemc::MCMessage> *communicator = macemc::__Simulator__::getCommunicator();

    prefix_count_msg = new macemc::MCMessagePrefixCount(macemc::__Simulator__::getNodeRank(), 
                                                        macemc::__Simulator__::getProcessRank(),
                                                        assignedPrefixes.size());

    Log::log("prefixes") << "Sending new prefix count to relay" << Log::endl;
    communicator->put(prefix_count_msg, ENDPOINT_WORKER);
    communicator->deliver(ENDPOINT_WORKER);
  }

  /*
    Removes the prefix at a given position and readjusts the current prefix pointer 
    appropriately.

    NOTE: prefixMutex lock MUST be held during this method's invocation!
    FIXME: We're not deleting prefixes we remove
   */
  void removePrefixAtIndex(uint index, bool requestPrefix) {
    uint oldSize = assignedPrefixes.size();

    ASSERT(index < oldSize);

    depths.erase(depths.begin() + index);
    assignedPrefixes.erase(assignedPrefixes.begin() + index);
    assignedBounds.erase(assignedBounds.begin() + index);
    doneEarly.erase(doneEarly.begin() + index);

    // Readjust current prefix position

    if (index < currentPrefix) {
      currentPrefix--;
    } else if (index == currentPrefix && index == oldSize - 1) {
      currentPrefix = 0;
    }
    pathPrefix = assignedPrefixes[currentPrefix];
    pathPrefixOutOf = assignedPrefixes[currentPrefix];
    
    ASSERT(assignedPrefixes.size() == oldSize - 1);

    sendPrefixCountToRelay();

    // Count on higher layers to ask for a prefix if you're out of prefixes.
    // (Prevents missing new prefix signal)
    if (requestPrefix && assignedPrefixes.size() > 0) {
      sendPrefixRequestToRelay();
    }
  }

public:  
  void addPathPrefix(UIntList& path, int prefixDepth) {
    UIntList *assignedPrefix = new UIntList(path);
    UIntList *assignedBound = new UIntList();

    Log::log("Time") << TimeUtil::time() << Log::endl;

    hasPrefix = true;

    uint prefixSize = assignedPrefix->size();
    assignedBound->resize(prefixSize);

    for (uint i = 0; i < prefixSize; i++) {
      (*assignedBound)[i] = (*assignedPrefix)[i] + 1;
    }

    pthread_mutex_lock(&prefixMutex);

    if (assignedPrefixes.size() == 0) {
      depths.resize(0);
      pathPrefix = assignedPrefix;
      pathPrefixOutOf = assignedBound;

      currentSelections = *pathPrefix;
      currentOutOf = *pathPrefixOutOf;
    }

    assignedPrefixes.push_back(assignedPrefix);
    assignedBounds.push_back(assignedBound);
    depths.push_back(prefixDepth);
    doneEarly.push_back(0);

    pthread_mutex_unlock(&prefixMutex);

    sendPrefixCountToRelay();
  }

  // Get a path prefix from the list of prefixes. If you only have one prefix left,
  // reject the request by setting depth to 0 and returning an empty prefix
  UIntList *getPathPrefix(int& depth) {
    UIntList *pathPtr = NULL;

    pthread_mutex_lock(&prefixMutex);

    uint numPrefixes = assignedPrefixes.size();

    if (numPrefixes > 1) {
      uint prefixIndexToGet = (currentPrefix + 1) % numPrefixes;

      pathPtr = assignedPrefixes[prefixIndexToGet];
      depth = depths[prefixIndexToGet];
      removePrefixAtIndex(prefixIndexToGet, false);
    } else {
      depth = 0;
      pathPtr = new UIntList();
    }

    pthread_mutex_unlock(&prefixMutex);

    return pathPtr;
  }

  unsigned numPrefixes() {
    return prefixTree.numPrefixes();
  }

  void prefixes(PrefixList& prefixList) {
    prefixTree.prefixes(prefixList);
  }

  void enablePrefixLogging() {
    logPrefixes = true;
  }

  void disablePrefixLogging() {
    logPrefixes = false;
  }

  unsigned randIntImplSub(unsigned max) {
    pthread_mutex_lock(&prefixMutex);

    unsigned depth = depths[currentPrefix];
    ADD_SELECTORS("SearchRandomUtil::randInt");
    ASSERT(max > 0);
    macedbg(0) << " depth=" << depth << " currentSelections.size()=" << currentSelections.size() << " currentOutOf.size()=" << currentOutOf.size() << Log::endl;
    ASSERT(depth != 0);

    unsigned offset = _pathInts.size();

    unsigned prefixSize = pathPrefix->size();
    unsigned outOfSize  = pathPrefixOutOf->size();

    if(offset < depth) {
      if(offset >= currentOutOf.size()) {
        if (hasPrefix && offset < outOfSize) {
          unsigned prefixMax = (*pathPrefixOutOf)[offset];

          currentOutOf.push_back(prefixMax <= max ? prefixMax : max);
        } else {
          currentOutOf.push_back(max);
        }

        if(offset >= currentSelections.size()) {
          if (hasPrefix && offset < prefixSize) {
            unsigned prefixVal = (*pathPrefix)[offset];

            currentSelections.push_back(prefixVal < max ? prefixVal : max - 1);
          } else {
            currentSelections.push_back(0);
          }
        }
      }
      macedbg(0) << "currentSelections[offset]=" << currentSelections[offset] << " currentOutOf[offset]="<<currentOutOf[offset] << " offset " << offset << Log::endl;

      if (currentSelections[offset] >= max) {
        Log::log("prefixes") << "About to fail assertion: currentSelections: " << currentSelections << ", currentOutOf: " << currentOutOf << ", offset: " << offset << ", max: " << max << Log::endl;
      }
      ASSERT(currentSelections[offset] < max);
      
      
      if(max != currentOutOf[offset] && (!hasPrefix || offset >= prefixSize)) {
        maceerr << "max: " << max << " currentOutOf[ " << offset << " ]: " << currentOutOf[offset] << Log::endl;
        ASSERT(max == currentOutOf[offset]);
      }
    
      if(_pathInts.size() == depth - 1) { 

        doneEarly[currentPrefix] = 0; 
      }
      if (logPrefixes) {
        Log::log("prefixPushed") << "Adding " << currentSelections << " " << currentOutOf << Log::endl;
        prefixTree.addPrefix(currentSelections, currentOutOf);
      }

      pthread_mutex_unlock(&prefixMutex);
      return currentSelections[offset];
    }

    doneEarly[currentPrefix] = 0;

    if (logPrefixes) {
      Log::log("prefixPushed") << "Adding " << currentSelections << " " << currentOutOf << Log::endl;
      prefixTree.addPrefix(currentSelections, currentOutOf);
    }

    pthread_mutex_unlock(&prefixMutex);
    return max;
  }
  void setNext(const UIntList& selections) {
    pthread_mutex_lock(&prefixMutex);

    unsigned depth = depths.size() < (unsigned) currentPrefix ? 1 : depths[currentPrefix];
    currentSelections = selections;
    while(depth < currentSelections.size()) { depth += depthIncrement; }

    depths[currentPrefix] = depth;
    currentOutOf.resize(0);

    pthread_mutex_unlock(&prefixMutex);
  }

  bool hasNextSub(bool isLive) {
    ADD_FUNC_SELECTORS;

    bool retVal = false;

    pthread_mutex_lock(&prefixMutex);

    if (assignedPrefixes.size() == 0) {
      Log::log("prefixes") << "Out of assigned prefixes" << Log::endl;
    } else {
      ASSERT(depths.size() > (unsigned) currentPrefix);

      unsigned depth = depths[currentPrefix];
      static unsigned maxSearchDepth = params::get("MAX_SEARCH_DEPTH", UINT_MAX);
      for(uint i = 0; i < depth && i < _pathInts.size(); i++) {
        if(currentSelections[i] + 1 < currentOutOf[i]) { retVal = true; }
      }

      if (!retVal) {
        bool killCurrentPrefix = false;
        std::string killReason;

        Log::log("prefixes") << "Assigned prefixes: [ ";
        for (uint i = 0; i < assignedPrefixes.size(); i++) {
          Log::log("prefixes") << *assignedPrefixes[i] << " ";
        }
        Log::log("prefixes") << "]" << Log::endl;

        Log::log("prefixes") << "doneEarly: [ ";
        for (uint i = 0; i < doneEarly.size(); i++) {
          Log::log("prefixes") << doneEarly[i] << " ";
        }
        Log::log("prefixes") << "]" << Log::endl;
        
        if (doneEarly[currentPrefix] > 1) {
          killReason = "done early";
          killCurrentPrefix = true;
        }

        if (depths[currentPrefix] > maxSearchDepth) {
          killReason = "exceeded max depth";
          killCurrentPrefix = true;
        }

        if (killCurrentPrefix) {
          Log::log("prefixes") << "Prefix " << currentPrefix << " of " << doneEarly.size() << " " << killReason << "; descheduling" << Log::endl;
          delete assignedPrefixes[currentPrefix];
          delete assignedBounds[currentPrefix];
          removePrefixAtIndex(currentPrefix, true);
        }

        if (assignedPrefixes.size() == 0) {
          Log::log("prefixes") << "Out of assigned prefixes" << Log::endl;
        } else {
          retVal = true;
        }
      }
    }
    pthread_mutex_unlock(&prefixMutex);

    return retVal;
  }

  bool nextSub() { //advance to the next search sequence, returns true when the depth increases
    ADD_SELECTORS("SearchRandomUtil::next");

    pthread_mutex_lock(&prefixMutex);

    ASSERT(depths.size() > (unsigned) currentPrefix);
    unsigned depth = depths[currentPrefix];

    bool ret = false;
    if(currentOutOf.size() != 0) { 
      int newDepth = std::min((size_t)depth, _pathInts.size()); 
      for(; newDepth > 0; newDepth--) {
        currentSelections[newDepth-1]++;
        if(currentSelections[newDepth-1] < currentOutOf[newDepth-1]) { break; }
      }
      currentSelections.resize(newDepth);
      currentOutOf.resize(newDepth);
      if(newDepth == 0) {
        if (doneEarly[currentPrefix] > 1) {
          Log::log("SearchRandomUtil::next") << "Search is complete early for prefix " << currentPrefix << "!" << Log::endl;
          removePrefixAtIndex(currentPrefix, true);
        } else {
//        ASSERT(doneEarly[currentPrefix] <= 1 /*failed assertion means search is done!*/);
          doneEarly[currentPrefix]++;
          
          depths[currentPrefix] += depthIncrement;
          currentPrefix = (currentPrefix + 1) % assignedPrefixes.size();
        }
        if (depths.size() > (unsigned) currentPrefix) {
          depth = depths[currentPrefix];
          
          pathPrefix = assignedPrefixes[currentPrefix];
          pathPrefixOutOf = assignedBounds[currentPrefix];
          
          currentSelections.reserve(depth);
          currentOutOf.reserve(depth);
          maceout << "Searching up to depths of " << depth << ", " << (Sim::getPathNum()-1) << " paths searched so far." << Log::endl;
          maceout << "Prefix is now at index " << currentPrefix << ": " << *pathPrefix << " out of " << *pathPrefixOutOf << Log::endl;
          phase = "SearchRandom:depth "+boost::lexical_cast<std::string>(depth);
        } else {
          Log::log("SearchRandomUtil::next") << "No more prefixes to search!" << Log::endl;
        }

        ret = true;
      }
    }
    resetGustoToggles();
    addGustoToggle(depth+_prefix.size());

    pthread_mutex_unlock(&prefixMutex);

    return ret;
  }
  void print(std::ostream& out) const {
    pthread_mutex_lock(const_cast<pthread_mutex_t*>(&prefixMutex));
    out << "Path<sdepth=" << depths[currentPrefix] << ">";
    SimRandomUtil::print(out);
    out << " search sequence " << currentSelections;
    if(verbose) {
      out << " Out Of " << currentOutOf;
    }
    pthread_mutex_unlock(const_cast<pthread_mutex_t*>(&prefixMutex));
  }
  bool implementsPrintPath() { return true; }
  
  bool pathIsDone() {
    pthread_mutex_lock(&prefixMutex);
    bool isDone = _pathInts.size() == depths[currentPrefix];
    pthread_mutex_unlock(&prefixMutex);
    return isDone;
  }
  
  void dumpState() {}

  int testSearchDepth() { 
    pthread_mutex_lock(&prefixMutex);
    int retVal = 0;

    if(_pathInts.size() >= currentOutOf.size()) {
      if(_randomInts.empty()) {
        retVal = 0;
      } else {
        retVal = 1;
      }
    } else if(pathDepth() < _prefix.size()) {
      retVal = -2;
    } else {
      retVal = -1;
    }
    pthread_mutex_unlock(&prefixMutex);
    return retVal;
  }

  static SearchRandomUtil* SetInstance() { 
    ADD_SELECTORS("SearchRandomUtil::SetInstance");
    SearchRandomUtil* t = NULL; 
    if(_inst == NULL) { 
      _inst = t = new SearchRandomUtil(); 
      if(params::containsKey("RANDOM_UTIL_PREFIX_FILE")) {
        std::ifstream in(params::get<std::string>("RANDOM_UTIL_PREFIX_FILE").c_str());
        UIntList initial;
        uint a;
        in >> a;
        while(!in.eof()) {
          macedbg(1) << "Pushing back " << a << " onto initial." << Log::endl;
          initial.push_back(a);
          in >> a;
        }
        macedbg(0) << "initial.size: " << initial.size() << " initial: " << initial << Log::endl;
        t->setPrefix(initial);
      }
      if(params::containsKey("RANDOM_UTIL_START_SEARCH")) {
        std::string s = params::get<std::string>("RANDOM_UTIL_START_SEARCH");
        std::istringstream in(s);
        UIntList initial;
        uint a;
        while(!in.eof()) {
          in >> a;
          initial.push_back(a);
        }
        std::cout << "read RANDOM_UTIL_START_SEARCH=" << initial
                  << " a='" << a << "'" << std::endl;
        t->setNext(initial);
      }
    }
    return t;
  }
};

#endif 
