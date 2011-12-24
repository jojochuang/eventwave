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
#include "mlist.h"
class ContextMapping {
public:
    ContextMapping(){
        // empty initialization
    }
    ContextMapping( const mace::map< mace::MaceKey, mace::list< mace::string > >& mapping ){
        ScopedLock sl(alock);
        this->mapping = mapping;
    }
    static mace::MaceKey getNodeByContext(const mace::string& contextName){
        ScopedLock sl(alock);
        
        mace::MaceKey fake;
        return fake;
    }
    // FIXME: update --> add/delete/replace?
    // chuangw: currently assuming the mapping is persistent, not changing after initialization.
    static bool updateMapping(const mace::MaceKey& node, const mace::list<mace::string>& contexts){
        ScopedLock sl(alock);
        return true;

    }
    static mace::MaceKey& getHead(){
        ScopedLock sl(hlock);
        return head;
    }
    static void setHead(mace::MaceKey& h){
        ScopedLock sl(hlock);
        head = h;
    }
protected:
    
private:
    static pthread_mutex_t alock;
    static pthread_mutex_t hlock;
    mace::map< mace::MaceKey, mace::list< mace::string > > mapping;
    static mace::MaceKey head;
};

#endif // CONTEXTMAPPING_H
