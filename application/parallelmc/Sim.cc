/* 
 * Sim.cc : part of the Mace toolkit for building distributed systems
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
#include "Sim.h"

int Sim::runningNode = 0;
bool Sim::gusto = false;
bool Sim::useGusto = false;
bool Sim::gustoReq = false;
bool Sim::isLive = false;
bool Sim::isSafe = true;
unsigned Sim::step = 0;
unsigned Sim::maxStep = 0;
int Sim::numNodes = 0;
std::string** Sim::logPrefixes = NULL;
MaceKey** Sim::keys = NULL;
std::string* Sim::nodeString = NULL;
bool Sim::inited = false;
unsigned Sim::phaseNum = 0;
unsigned Sim::pathCount = 0;
unsigned Sim::cumulativePathCount = 0;
unsigned Sim::uniqueStateCount = 0;
unsigned Sim::cumulativeUniqueStateCount = 0;
unsigned Sim::countTMS = 0;
unsigned Sim::cumulativeTmsCount = 0;
unsigned Sim::countOOE = 0;
unsigned Sim::cumulativeOoeCount = 0;
unsigned Sim::countSC = 0;
unsigned Sim::cumulativeScCount = 0;
unsigned Sim::countDuplicate = 0;
unsigned Sim::cumulativeDuplicateCount = 0;
unsigned Sim::liveCount = 0;
unsigned Sim::cumulativeLiveCount = 0;
mace::deque<unsigned> Sim::simStepsDuplicate;
mace::deque<unsigned> Sim::randStepsDuplicate;
mace::deque<unsigned> Sim::simStepsTMS;
mace::deque<unsigned> Sim::randStepsTMS;
mace::deque<unsigned> Sim::simStepsOOE;
mace::deque<unsigned> Sim::randStepsOOE;
mace::deque<unsigned> Sim::simStepsSC;
mace::deque<unsigned> Sim::randStepsSC;
uint64_t Sim::startTime;
uint64_t Sim::lastPhaseEnd;
