/* 
 * ContextMapping.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Wei-Chiu Chuang
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the names of the contributors, nor their associated universities 
 *      or organizations may be used to endorse or promote products derived from
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

#ifndef CONTEXTMAPPING_H
#define CONTEXTMAPPING_H
/**
 * \file ContextMapping.h
 * \brief declares the ContextMapping class for mapping context to physical nodes.
 */

//NOTE: This part of building block for fullcontext Mace language.
#include "MaceKey.h"
#include "m_map.h"
#include "mvector.h"
#include "mlist.h"
#include "mace-macros.h"
#include "Util.h"
#include "SockUtil.h"
#include "ThreadStructure.h"
#include <utility>
#include <deque>

namespace mace
{

  class ContextDAGEntry
  {
  public:
    mace::string contextID;
    ContextDAGEntry *peer;
    ContextDAGEntry *children;

      ContextDAGEntry ():contextID ()
    {
      //contextID = 0;
      peer = NULL;
      children = NULL;

    }

  };

  class ContextMapping
  {
  public:
    ContextMapping ():defaultAddress (SockUtil::NULL_MACEADDR), head (SockUtil::NULL_MACEADDR) {
      // empty initialization
    }
    ContextMapping (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ADD_SELECTORS ("ContextMapping::(constructor)");
      init (vhead, mkctxmapping);
      mapped = true;
    }
    ContextMapping (const mace::ContextMapping& orig) { // copy constructor
      // XXX: not tested.
      defaultAddress = orig.defaultAddress;
      mapping = orig.mapping;
      accessedContexts = orig.accessedContexts;
      nodes = orig.nodes;
      head = orig.head;
      mapped = orig.mapped;
      virtualNodes = orig.virtualNodes;
      vnodeMaceKey = orig.vnodeMaceKey;
      //initialMapping = orig.initialMapping;  //initialMapping is used only at initialization

    }
    void setDefaultAddress (const MaceAddr & addr) {
      defaultAddress = addr;
      head = addr;
    }
    /* public interface of snapshot() */
    void snapshot(const uint64_t& ver) const{
        mace::ContextMapping* _ctx = new mace::ContextMapping(*this); // make a copy
        snapshot( ver, _ctx );
    }
    void snapshotRelease(const uint64_t& ver) const{ // clean up when event commits
      ADD_SELECTORS("ContextBaseClass::snapshotRelease");
      while( !versionMap.empty() && versionMap.front().first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.front().first << " for service " << this << " value " << versionMap.front().second << Log::endl;
        delete versionMap.front().second;
        versionMap.pop_front();
      }
    }

    void loadMapping (const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ScopedLock sl (alock);
      ADD_SELECTORS ("ContextMapping::loadMapping");
      for (mace::map < mace::MaceAddr, mace::list < mace::string > >::const_iterator mit = mkctxmapping.begin (); mit != mkctxmapping.end (); mit++) {
        for (mace::list < mace::string >::const_iterator lit = mit->second.begin (); lit != mit->second.end (); lit++) {
          if (lit->compare (headContext) == 0) {
            head = mit->first;
          } else {
            mapping[*lit] = mit->first;
          }
        }
        nodes.insert (mit->first);
      }
    }

    void init (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr,
	       mace::list < mace::string > >&mkctxmapping)
    {
      ScopedLock sl (alock);
      ADD_SELECTORS ("ContextMapping::init");
      head = vhead;
      for (mace::map < mace::MaceAddr, mace::list < mace::string > >::const_iterator mit = mkctxmapping.begin (); mit != mkctxmapping.end (); mit++) {
        for (mace::list < mace::string >::const_iterator lit = mit->second.begin (); lit != mit->second.end (); lit++) {
            mapping[*lit] = mit->first;
        }
        nodes.insert (mit->first);
      }
    }
    /*void printAll(){
       ADD_SELECTORS("ContextMapping::printAll");
       maceout<<"Number of mappings: "<< mapping.size()  <<Log::endl;
       for( mace::map< mace::string, mace::MaceAddr >::iterator mapit=mapping.begin(); mapit!=mapping.end(); mapit++){
       maceout<< "'"<<mapit->first <<"' mapped to " << mapit->second<<Log::endl;
       }
       } */

    const mace::MaceAddr getNodeByContext (const mace::string & contextName)
    {
      ScopedLock sl (alock);
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getNodeByContext( contextName );
    }
    // chuangw: assuming this is called by head node
    // This method checks whether the context has been accessed before or not.
    bool accessedContext (const mace::string & contextName)
    {
      ScopedLock sl (alock);
      if (accessedContexts.find (contextName) == accessedContexts.end ()) {
        accessedContexts.insert (contextName);
        return false;
      }
      return true;
    }
    bool updateMapping (const mace::MaceAddr & oldNode,
			const mace::MaceAddr & newNode)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      for (mace::map < mace::string, mace::MaceAddr >::iterator mit = mapping.begin (); mit != mapping.end (); mit++) {
        if (mit->second == oldNode) {
            mit->second = newNode;
        }
      }
      nodes.insert (newNode);
      return true;

    }
    bool updateMapping (const mace::MaceAddr & node, const mace::list < mace::string >& contexts)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      for (mace::list < mace::string >::const_iterator lit = contexts.begin (); lit != contexts.end (); lit++) {
          mapping[*lit] = node;
      }
      nodes.insert (node);
      return true;

    }
    bool updateMapping (const mace::MaceAddr & node, const mace::string & context)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      mapping[context] = node;
      nodes.insert (node);
      return true;

    }
    void printMapping ()
    {
      ScopedLock sl (alock);
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._printMapping(  );
    }
    // chuangw: assuming head does not migrate... so no need to get the snapshot
    mace::MaceAddr & getHead ()
    {
      ADD_SELECTORS ("ContextMapping::getHead");
      ScopedLock sl (hlock);
      return head;
    }
    void setHead (mace::MaceAddr & h)
    {
      ADD_SELECTORS ("ContextMapping::setHead");
      ScopedLock sl (hlock);
      head = h;
    }
    const std::set < MaceAddr >& getAllNodes ()
    {
      ScopedLock sl (alock);
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getAllNodes(  );
      return nodes;
    }

    // this method modifies the latest context mapping.
    static void updateVirtualNodes (const uint32_t nodeid, const MaceAddr & addr)
    {
      ScopedLock sl (hlock);
      virtualNodes[nodeid] = addr;
    }

    // chuangw: not used??
    static const MaceAddr & lookupVirtualNode (const uint32_t nodeid)
    {
      ScopedLock sl (hlock);
      return virtualNodes[nodeid];
    }

    // the representative name for head context does not change.
    static const mace::string & getHeadContext ()
    {
      return headContext;
    }
    
    // virtual node mace key, after assigned, does not change
    static MaceKey & getVirtualNodeMaceKey ()
    {
      return vnodeMaceKey;
    }
    static void setVirtualNodeMaceKey (const MaceKey & addr)
    {
      vnodeMaceKey = addr;
    }

    static void setInitialMapping (const mace::map < mace::string, mace::map < MaceAddr , mace::list < mace::string > > >&mapping)
    {
      initialMapping = mapping;
      mapped = true;
    }

    static mace::map < MaceAddr , mace::list < mace::string > >&getInitialMapping (const mace::string & serviceName)
    {
      return initialMapping[serviceName];
    }
  private:
    void snapshot(const uint64_t& ver, mace::ContextMapping* _ctx) const{
      ADD_SELECTORS("ContextBaseClass::snapshot");
      macedbg(1) << "Snapshotting version " << ver << " for this " << this << " value " << _ctx << Log::endl;
      ASSERT( versionMap.empty() || versionMap.back().first < ver );
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    const mace::ContextMapping& getSnapshot(){
      // assuming the caller of this method applies a mutex.
      //uint64_t ver = ThreadStructure::myEvent();
      // TODO: find the latest version of context mapping.
      // the head node, knowning the type of the events, can decide the last write-mode mapping of event .
      // Only context-mapping update events and migration events are events that writes to context mapping.
      // Others are just read-only.
      const uint64_t lastWrite = ThreadStructure::getLastWriteContextMappingVersion();
      VersionContextMap::const_iterator i = versionMap.begin();
      while (i != versionMap.end()) {
        if (i->first == lastWrite) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << lastWrite << " ticket " << ThreadStructure::myTicket() << Log::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      return *(i->second);
    }
    const mace::MaceAddr _getNodeByContext (const mace::string & contextName) const
    {
      ADD_SELECTORS ("ContextMapping::getNodeByContext");
      if (!mapped) {
        return defaultAddress;
      }
      mace::map < mace::string, mace::MaceAddr >::const_iterator mapit = mapping.find (contextName);
      if ( mapit == mapping.end ()) {
        // complain
        maceerr << "can't find the node for context name '" << contextName << "'" << Log::endl;
        for (mace::map < mace::string, mace::MaceAddr >::const_iterator mapit = mapping.begin (); mapit != mapping.end (); mapit++) {
            maceerr << "'" << mapit->first << "' mapped to " << mapit-> second << Log::endl;
        }
        return SockUtil::NULL_MACEADDR;
      } else {
        return mapit->second;
      }
    }
    void _printMapping () const
    {
      ADD_SELECTORS ("ContextMapping::printMapping");

      for ( mace::map < mace::string, mace::MaceAddr >::const_iterator mapIt = mapping.begin (); mapIt != mapping.end (); mapIt++) {
          macedbg(1) << mapIt->first <<" -> " << mapIt->second << Log::endl;
      }
    }
    const std::set < MaceAddr >& _getAllNodes () const
    {
      return nodes;
    }

protected:
    typedef std::deque<std::pair<uint64_t, const mace::ContextMapping* > > VersionContextMap;
    mutable VersionContextMap versionMap;

  private:
    MaceAddr defaultAddress;

    static const mace::string headContext;
    static pthread_mutex_t alock;
    static pthread_mutex_t hlock;
    mace::map < mace::string, mace::MaceAddr > mapping;

    mace::set < mace::string > accessedContexts;

    std::set < mace::MaceAddr > nodes;
    mace::MaceAddr head;

    //static ContextDAGEntry *DAGhead;

    static bool mapped;

    static std::map < uint32_t, MaceAddr > virtualNodes;
    static mace::MaceKey vnodeMaceKey;

    static mace::map < mace::string, mace::map < MaceAddr, mace::list < mace::string > > >initialMapping;
  };

}

    // chuangw: Probably obsolete code
    /*      static mace::string getStartContext(mace::vector<mace::string>& allContextIDs){
       mace::string startContextID = searchDAGforStart(allContextIDs);
       return startContextID;
       }

       static mace::string searchDAGforStart(std::vector<mace::string>& array){
       mace::string startContextID;
       std::vector<uint8_t> flags( array.size() );
       startContextID = searchDAG(array, flags, DAGhead);
       return startContextID;
       }

       static mace::string searchDAG(std::vector<mace::string>& array, std::vector<uint8_t>& flags,  ContextDAGEntry* entry){
       if(entry==NULL){
       return "";
       }

       int len = flags.size();//flags.length;
       std::vector<uint8_t> flagsbk( len );
       for(int i=0; i<len; i++){
       flagsbk[i] = flags[i];
       }

       mace::string str = searchDAG(array, flags, entry->children);

       for(unsigned int i=0; i<array.size(); i++){
       if(array[i] == entry->contextID){
       flags[i]=true;
       break;                                                               
       }
       }

       if(str != ""){
       return str;
       }

       unsigned int count = 0;
       for(unsigned int i=0; i<flags.size(); i++){
       if(flags[i]){
       count ++;
       }else{
       break;
       }
       }
       if(count == array.size() ){
       str = entry->contextID;
       return str;
       }

       str = searchDAG(array, flagsbk, entry->peer);
       for(int i=0; i<len; i++){
       if(flagsbk[i]){
       flags[i] = true;
       }
       }
       return str;
       }
     */
#endif // CONTEXTMAPPING_H
