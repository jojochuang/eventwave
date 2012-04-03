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

namespace mace{

class ContextDAGEntry {
public:
		mace::string contextID;
		ContextDAGEntry* peer;
		ContextDAGEntry* children;
		
		ContextDAGEntry(): contextID(){
				//contextID = 0;
				peer = NULL;
				children = NULL;
				
		}

};

class ContextMapping {
public:
    ContextMapping(){
        // empty initialization
    }
    ContextMapping(const mace::MaceKey& vhead, const mace::map< mace::MaceKey, mace::list< mace::string > >& mkctxmapping ){
        ADD_SELECTORS("ContextMapping::(constructor)");
        init( vhead, mkctxmapping );
    }
    static void init(const mace::MaceKey& vhead, const mace::map< mace::MaceKey, mace::list< mace::string > >& mkctxmapping ){
        ADD_SELECTORS("ContextMapping::init");
        ScopedLock sl(alock);
        head = vhead;
        for( mace::map< mace::MaceKey, mace::list< mace::string > >::const_iterator mit = mkctxmapping.begin(); mit!=mkctxmapping.end();mit++){
            for( mace::list<mace::string>::const_iterator lit=mit->second.begin(); lit!=mit->second.end(); lit++ ){
                mapping[ *lit ] = mit->first;
            }
            nodes.insert( mit->first );
        }
    }
    static mace::MaceKey getNodeByContext(const mace::string& contextName){
        ADD_SELECTORS("ContextMapping::getNodeByContext");
        ScopedLock sl(alock);
        
        if( mapping.find( contextName ) == mapping.end() ){
            // complain
            maceerr<<"can't find the node for context name '"<< contextName <<"'"<<Log::endl;
            for( mace::map< mace::string, mace::MaceKey >::iterator mapit=mapping.begin(); mapit!=mapping.end(); mapit++){
                maceerr<< "'"<<mapit->first <<"' mapped to " << mapit->second<<Log::endl;
            }
           return mace::MaceKey::null;
        }else{
            return mapping[ contextName ];
        }
    }
    // FIXME: update --> add/delete/replace?
    // chuangw: currently assuming the mapping is persistent, not changing after initialization.
    static bool updateMapping(const mace::MaceKey& node, const mace::list<mace::string>& contexts){
        ADD_SELECTORS("ContextMapping::updateMapping");
        ScopedLock sl(alock);

        for( mace::list< mace::string >::const_iterator lit= contexts.begin(); lit != contexts.end(); lit++ ){
            mapping[ *lit ] = node;
        }
        nodes.insert( node );
        return true;

    }
    static mace::MaceKey& getHead(){
        ADD_SELECTORS("ContextMapping::getHead");
        ScopedLock sl(hlock);
        return head;
    }
    static void setHead(mace::MaceKey& h){
        ADD_SELECTORS("ContextMapping::setHead");
        ScopedLock sl(hlock);
        head = h;
    }
    static std::set<MaceKey> getAllNodes(){
        return nodes;
    }

		static mace::string getStartContext(mace::vector<mace::string>& allContextIDs){
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

		static mace::string getHeadContext(){
				return "headContextID";
		}

protected:
    
private:
    static pthread_mutex_t alock;
    static pthread_mutex_t hlock;
    //mace::map< mace::MaceKey, mace::list< mace::string > > mapping;
    static mace::map< mace::string, mace::MaceKey > mapping;
    static std::set<MaceKey> nodes;
    static mace::MaceKey head;

		static ContextDAGEntry* DAGhead;
};

}
#endif // CONTEXTMAPPING_H
