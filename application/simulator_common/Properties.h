/* 
 * Properties.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2011, Charles Killian, James W. Anderson
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
#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "SimCommon.h"
#include "m_map.h"

namespace macemc {

class TestProperties {
  public:
    virtual bool testSafetyProperties(mace::string& description) = 0;
    virtual bool testLivenessProperties(mace::string& description) = 0;
    virtual ~TestProperties() {}
};

template<typename Service>
class SpecificTestProperties : public TestProperties {
  typedef mace::map<int, Service const *, mace::SoftState> _NodeMap_;
  private:
    _NodeMap_ serviceNodes;
  public:
    SpecificTestProperties(const _NodeMap_& nodes) : serviceNodes(nodes) {
      ASSERT(nodes.size());
    }

    bool testSafetyProperties(mace::string& description) {
      return Service::checkSafetyProperties(description, serviceNodes);
    }
    bool testLivenessProperties(mace::string& description) {
      return Service::checkLivenessProperties(description, serviceNodes);
    }
};

class SimulatorEmptyProperty : public TestProperties {
public:
  SimulatorEmptyProperty(SimCommon& sim) : sim(sim) { }
  bool testSafetyProperties(mace::string& description) { return true; }
  bool testLivenessProperties(mace::string& description) {
    if (sim.hasEventsWaiting()) {
      return true;
    }
    description = "SimulatorNotEmpty";
    return false;
  }
private:
  SimCommon& sim;
};

}
#endif // PROPERTIES_H
