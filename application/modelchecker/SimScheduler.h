/* 
 * SimScheduler.h : part of the Mace toolkit for building distributed systems
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
#ifndef _SIM_SCHED__H_
#define _SIM_SCHED__H_

#include "Sim.h"
#include "m_map.h"
#include "hash_string.h"
#include "mvector.h"
#include "Iterator.h"
#include "MaceTypes.h"
#include "Util.h"
#include "mace-macros.h"
#include "Scheduler.h"
#include "SimulatorTransport.h"
#include "ReceiveDataHandler.h"

// typedef mace::vector<TimerHandler*> TimerList;
typedef mace::vector<EventWeight, mace::SoftState> TimerList;

class SimScheduler : public Sim, public Scheduler {
  protected:
    static SimScheduler* _sim_inst;
    TimerList scheduledTimers;
    SimScheduler() : Sim(), Scheduler() { }
    void runSchedulerThread() {}
  public:
    uint32_t hashState() const { return 0; }
    void print(std::ostream& out) const {
//       out << std::endl;
//       for (TimerList::const_iterator i = scheduledTimers.begin();
// 	   i != scheduledTimers.end(); i++) {
// 	const EventWeight& e = *i;
// 	out << e.first.node << ": " << e.first.desc << std::endl;
//       }
    }
    void reset() {
      scheduledTimers.clear();
    }
    uint64_t schedule(TimerHandler& timer, uint64_t time, bool abs = false) {
      ADD_FUNC_SELECTORS;
      if (!abs) {
        time += TimeUtil::timeu();
      }
      int current = getCurrentNode();
      EventWeight ew;
      ew.first.node = current;
      ew.first.type = Event::SCHEDULER;
      ew.first.simulatorVector.push_back((intptr_t)(&timer));
      ew.first.desc = timer.getDescription();
      ew.second = 1;
      maceout << "Scheduling timer " << &timer << " for node " << current << Log::endl;
      scheduledTimers.push_back(ew);
      return time;
    }
    void cancel(TimerHandler& timer) {
      TimerList::iterator i;
      for(i = scheduledTimers.begin(); i != scheduledTimers.end(); i++) {
        if(i->first.simulatorVector[0] == (intptr_t)(&timer)) {
          break;
        }
      }
      if(i != scheduledTimers.end()) {
        scheduledTimers.erase(i);
      }
    }
    bool isSimulated() { return true; }

    void eventsWaiting(EventList& ev) const {
      ADD_SELECTORS("SimScheduler::eventWaiting");
      ev.insert(ev.end(), scheduledTimers.begin(), scheduledTimers.end());
      maceout << "Scheduler returning " << scheduledTimers.size() << " events" << Log::endl;
    }
    std::string simulateEvent(const Event& e) {
      ADD_FUNC_SELECTORS;
      maceLog("simulating timer for node %d\n", e.node);
      TimerList::iterator pos;
      for(pos = scheduledTimers.begin(); pos != scheduledTimers.end(); pos++) {
        if(e.simulatorVector[0] == pos->first.simulatorVector[0]) { break; }
      }
      if(pos != scheduledTimers.end()) {
        scheduledTimers.erase(pos);
      }
      else {
        ABORT("Firing a timer that isn't scheduled?");
      }
      TimerHandler* timer = (TimerHandler*)e.simulatorVector[0];
      timer->fire();
      std::ostringstream r;
      r << timer->getDescription() << "(" << timer->getId() << ")";
      return r.str();
    }
    static SimScheduler& Instance() { 
      if(_sim_inst == NULL) {
        _sim_inst = new SimScheduler();
      }
      if(scheduler == NULL) {
        scheduler = _sim_inst;
      }
      return *_sim_inst; 
    } 
    virtual ~SimScheduler() { }
};

#endif
