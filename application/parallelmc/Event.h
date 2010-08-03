/* 
 * Event.h : part of the Mace toolkit for building distributed systems
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
#ifndef __EVENT_H
#define __EVENT_H

#include "mpair.h"
#include "mvector.h"

struct Event : public mace::PrintPrintable {
  public:
    enum EventType { APPLICATION, NETWORK, SCHEDULER };

  public:
    int node;
    EventType type;
    mace::string desc;
  
    mace::vector<intptr_t, mace::SoftState> simulatorVector;
    mace::vector<intptr_t, mace::SoftState> subVector;

    const char* getType(EventType t) const {
      switch (t) {
        case APPLICATION:
          return "APPLICATION";
        case NETWORK:
          return "NETWORK";
        case SCHEDULER:
          return "SCHEDULER";
        default:
          ASSERT(0);
      }
      return NULL;
    }
    void print(std::ostream& out) const {
      out << "Event(node="<<node<<",desc="<<desc<<",type="<<getType(type)<<",simulatorVector="<<simulatorVector<<",subVector="<<subVector<<")";
    }

};

typedef mace::printpair<Event, unsigned> EventWeight;
class EventList : public mace::vector<EventWeight, mace::SoftState> {
  public:
    typedef Event key_type;
    typedef unsigned mapped_type;

    void print(std::ostream& out) const {
      unsigned weight = 0;
      unsigned position = 0;
      for(EventList::const_iterator i = this->begin(); i != this->end(); i++) {
        out << "Item " << position << "[" << weight << "," << (weight+i->second) << "): " << i->first << " wt: " << i->second << std::endl;
        position++;
        weight += i->second;
      }
    }
};

#endif //__EVENT_H
