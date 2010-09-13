/* 
 * mace.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2007, Charles Killian, Dejan Kostic, Ryan Braud, James W. Anderson, John Fisher-Ogden, Calvin Hubble, Duy Nguyen, Justin Burke, David Oppenheimer, Amin Vahdat, Adolfo Rodriguez, Sooraj Bhat
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

#ifndef _MACE_H
#define _MACE_H

/**
 * \file mace.h
 * \brief declares BaseMaceService
 */

#include "Scheduler.h"

/**
 * \brief Base class for all generated Mace services.
 *
 * Provides the agentlock shared by all services, and a virtual method to allow
 * deferred actions to occur.
 */
class BaseMaceService 
{

public:
  //Agent Stuff
  static pthread_mutex_t synclock;  ///< The "agent lock", held when executing nearly any code in a service.  Recursive to allow recursive calls.
  static bool _printLower;

  //   static void Lock();
  //   static void Unlock();

  virtual void processDeferred() {} ///< Implemented by each service to process deferral queues, when directionality won't allow a call to be made immediately.

  BaseMaceService();
  virtual ~BaseMaceService() {}
};

namespace mace {

class AgentLock
{
  private:
    class ThreadSpecific {
      public:
        ThreadSpecific();
        ~ThreadSpecific();

        static ThreadSpecific* init();

        static int getCurrentMode() { return init()->currentMode; }
        static void setCurrentMode(int newMode) { init()->currentMode = newMode; }
        static int getMyTicket() { return init()->myTicketNum; }
        static void setMyTicket(uint64_t ticketId) { init()->myTicketNum = ticketId; }

        int currentMode;
        uint64_t myTicketNum;
        pthread_cond_t threadCond;

      private:
        static void initKey();

      private:
        static pthread_key_t pkey;
        static pthread_once_t keyOnce;
        
    }; // ThreadSpecific

  public:
    static const int WRITE_MODE = 1;
    static const int READ_MODE = 0;
    static const int NONE_MODE = -1;

  private:
    static pthread_mutex_t _agent_ticketbooth;
    static uint64_t now_serving;
    static int numReaders;
    static int numWriters;
    static std::map<uint64_t, pthread_cond_t*> conditionVariables; // Support for per-thread CVs, which gives per ticket CV support. Note: can just use the front of the queue to avoid lookups 

    ThreadSpecific* const threadSpecific;
    const int requestedMode;
    const int priorMode;
    uint64_t myTicketNum;

  public:
    AgentLock(int requestedMode = WRITE_MODE) : threadSpecific(ThreadSpecific::init()), requestedMode(requestedMode), priorMode(threadSpecific->currentMode), myTicketNum(threadSpecific->myTicketNum) {
      ADD_SELECTORS("AgentLock::(constructor)");
      macedbg(1) << "STARTING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

      if (priorMode == NONE_MODE) {
        // do what's needed
        if (requestedMode == NONE_MODE) {
          //Do nothing.
        }
        else {
          ASSERTMSG(requestedMode == READ_MODE || requestedMode == WRITE_MODE, "Invalid mode requested!");

          ScopedLock sl(_agent_ticketbooth);

          if (myTicketNum == std::numeric_limits<uint64_t>::max()) {
            myTicketNum = getNewTicket();
            macewarn << "Ticket not acquired - acquiring new ticket.  Ticket: "  << myTicketNum << Log::endl;
          }

          if (myTicketNum < now_serving) {
            //Ticket already used!  Need to acquire new ticket.
            uint64_t oldTicket = myTicketNum;
            myTicketNum = getNewTicket();
            macewarn << "Ticket already used - acquiring new ticket.  Sometimes possible event interleaving!  This time tickets are: "  << oldTicket << " and " << myTicketNum << Log::endl;
          }

          if (myTicketNum > now_serving ||
               ( requestedMode == READ_MODE && (numWriters != 0) ) ||
               ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
             ) {
            macedbg(1) << "Storing condition variable " << &(threadSpecific->threadCond) << " for ticket " << myTicketNum << Log::endl;
            conditionVariables[myTicketNum] = &(threadSpecific->threadCond);
          }

          while (myTicketNum > now_serving ||
                  ( requestedMode == READ_MODE && (numWriters != 0) ) ||
                  ( requestedMode == WRITE_MODE && (numReaders != 0 || numWriters != 0) )
                ) {
            macedbg(1) << "Waiting for my turn on cv " << &(threadSpecific->threadCond) << ".  myTicketNum " << myTicketNum << " now_serving " << now_serving << " requestedMode " << requestedMode << " numWriters " << numWriters << " numReaders " << numReaders << Log::endl;
            pthread_cond_wait(&(threadSpecific->threadCond), &_agent_ticketbooth);
          }

          macedbg(1) << "Ticket " << myTicketNum << " being served!" << Log::endl;

          //If we added our cv to the map, it should be the front, since all earlier tickets have been served.
          if (conditionVariables.begin() != conditionVariables.end() && conditionVariables.begin()->first == myTicketNum) {
            macedbg(1) << "Erasing our cv from the map." << Log::endl;
            conditionVariables.erase(conditionVariables.begin());
          }
          else if (conditionVariables.begin() != conditionVariables.end()) {
            macedbg(1) << "FYI, first cv in map is for ticket " << conditionVariables.begin()->first << Log::endl;
          }

          ASSERT(myTicketNum == now_serving); //Remove once working.

          now_serving++;

          if (requestedMode == READ_MODE) {
            //Acquire read lock
            ASSERT(numWriters == 0);
            numReaders++;
            ThreadSpecific::setCurrentMode(READ_MODE);
            if (conditionVariables.begin() != conditionVariables.end() && conditionVariables.begin()->first == now_serving) {
              macedbg(1) << "Now signalling ticket number " << now_serving << " (my ticket is " << myTicketNum << " )" << Log::endl;
              pthread_cond_broadcast(conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
            }
            else {
              ASSERTMSG(conditionVariables.begin() == conditionVariables.end() || conditionVariables.begin()->first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
            }
          }
          else if (requestedMode == WRITE_MODE) {
            //Acquire write lock
            ASSERT(numReaders == 0);
            ASSERT(numWriters == 0);
            ThreadSpecific::setCurrentMode(WRITE_MODE);
            numWriters = 1;
          }
        }
      }
      else if (priorMode == READ_MODE) {
        ASSERTMSG(requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid Context Transition: Tried to enter WRITE_MODE (or an unknown mode) from READ_MODE!");
      }
      else if (priorMode == WRITE_MODE) {
        ASSERTMSG(requestedMode == WRITE_MODE || requestedMode == READ_MODE || requestedMode == NONE_MODE, "Invalid requestedMode!");
      }
      else {
        ABORT("Unknown priorMode!");
      }
      macedbg(1) << "CONTINUING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << Log::endl;

    }
    ~AgentLock() {
      ADD_SELECTORS("AgentLock::(destructor)");
      int runningMode = ThreadSpecific::getCurrentMode();
      macedbg(1) << "ENDING.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
      if (priorMode == NONE_MODE && runningMode != NONE_MODE) {
        macedbg(1) << "Downgrading to NONE_MODE" << Log::endl;
        downgrade(NONE_MODE);
      }
      macedbg(1) << "ENDED.  priorMode " << priorMode << " requestedMode " << requestedMode << " myTicketNum " << myTicketNum << " runningMode " << runningMode << Log::endl;
    }

    static void downgrade(int newMode) {
      ADD_SELECTORS("AgentLock::downgrade");
      int runningMode = ThreadSpecific::getCurrentMode();
      uint64_t myTicketNum = ThreadSpecific::getMyTicket();
      macedbg(1) << "Downgrade requested. myTicketNum " << myTicketNum << " runningMode " << runningMode << " newMode " << newMode << Log::endl;
      if (newMode == NONE_MODE && runningMode != NONE_MODE) {
        //GlobalCommit::commit();  //Commit before or after lock?
        macedbg(1) << "Commiting ticket " << myTicketNum << Log::endl;
        ScopedLock sl(_agent_ticketbooth);
        if (runningMode == READ_MODE) {
          ASSERT(numReaders > 0 && numWriters == 0);
          numReaders--;
        }
        else if (runningMode == WRITE_MODE) {
          ASSERT(numReaders == 0 && numWriters == 1);
          numWriters=0;
        }
        else {
          ABORT("Invalid running mode!");
        }
        macedbg(1) << "After lock release - numReaders " << numReaders << " numWriters " << numWriters << Log::endl;
        ThreadSpecific::setCurrentMode(NONE_MODE);
        if (conditionVariables.begin() != conditionVariables.end() && conditionVariables.begin()->first == now_serving) {
          macedbg(1) << "Signalling CV " << conditionVariables.begin()->second << " for ticket " << now_serving << Log::endl;
          pthread_cond_broadcast(conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(conditionVariables.begin() == conditionVariables.end() || conditionVariables.begin()->first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
        macedbg(1) << "Downgrade to NONE_MODE complete" << Log::endl;
      }
      else if (newMode == READ_MODE && runningMode == WRITE_MODE) {
        macedbg(1) << "Downgrade to READ_MODE reqested" << Log::endl;
        ScopedLock sl(_agent_ticketbooth);
        ASSERT(numWriters == 1 && numReaders == 0);
        ASSERT(now_serving == myTicketNum + 1); // We were in exclusive mode, and holding the lock, so we should still be the one being served...
        // Delay committing until end.
        numWriters = 0;
        numReaders = 1;
        ThreadSpecific::setCurrentMode(READ_MODE);
        if (conditionVariables.begin() != conditionVariables.end() && conditionVariables.begin()->first == now_serving) {
          macedbg(1) << "Signalling CV " << conditionVariables.begin()->second << " for ticket " << now_serving << Log::endl;
          pthread_cond_broadcast(conditionVariables.begin()->second); // only signal if this is a reader -- writers should signal on commit only.
        }
        else {
          ASSERTMSG(conditionVariables.begin() == conditionVariables.end() || conditionVariables.begin()->first > now_serving, "conditionVariables map contains CV for ticket already served!!!");
        }
      }
      else {
        macewarn << "Why was downgrade called?  Current mode is: " << runningMode << " and mode requested is: " << newMode << Log::endl;
      }
      macedbg(1) << "Downgrade exiting" << Log::endl;
    }

  //Temporary stubs (unless Hyo wants to use these instead)
  private:
    static pthread_mutex_t ticketMutex;
    static uint64_t nextTicketNumber;

  public:
    static uint64_t getNewTicket() {
      ADD_SELECTORS("AgentLock::getNewTicket");
      //Needs error checking that prior ticket is committed?
      ScopedLock sl(ticketMutex);
      ThreadSpecific::setMyTicket(nextTicketNumber);
      macedbg(1) << "Ticket " << nextTicketNumber << " sold!" << Log::endl;
      return nextTicketNumber++;
    }
    static uint64_t getMyTicket() {
      //Needs error checking that this thread already has a valid ticket?
      return ThreadSpecific::getMyTicket();
    }
}; //AgentLock

}

#endif // _MACE_H
