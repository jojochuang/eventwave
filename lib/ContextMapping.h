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
    ContextMapping ():defaultAddress (SockUtil::NULL_MACEADDR),
      head (SockUtil::NULL_MACEADDR), mapped (false)
    {
      // empty initialization
    }
    ContextMapping (const mace::MaceAddr & vhead,
		    const mace::map < mace::MaceAddr,
		    mace::list < mace::string > >&mkctxmapping)
    {
      ADD_SELECTORS ("ContextMapping::(constructor)");
      init (vhead, mkctxmapping);

      mapped = true;
    }
    void setDefaultAddress (const MaceAddr & addr)
    {
      defaultAddress = addr;
      head = addr;
    }
    void loadMapping (const mace::map < mace::MaceAddr,
		      mace::list < mace::string > >&mkctxmapping)
    {
      ADD_SELECTORS ("ContextMapping::loadMapping");
      ScopedLock sl (alock);
      for (mace::map < mace::MaceAddr,
	   mace::list < mace::string > >::const_iterator mit =
	   mkctxmapping.begin (); mit != mkctxmapping.end (); mit++)
	{
	  for (mace::list < mace::string >::const_iterator lit =
	       mit->second.begin (); lit != mit->second.end (); lit++)
	    {
	      if (lit->compare (headContext) == 0)
		{
		  head = mit->first;
		}
	      else
		{
		  mapping[*lit] = mit->first;
		}
	    }
	  nodes.insert (mit->first);
	}

      mapped = true;
    }

    void init (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr,
	       mace::list < mace::string > >&mkctxmapping)
    {
      ADD_SELECTORS ("ContextMapping::init");
      ScopedLock sl (alock);
      head = vhead;
      for (mace::map < mace::MaceAddr,
	   mace::list < mace::string > >::const_iterator mit =
	   mkctxmapping.begin (); mit != mkctxmapping.end (); mit++)
	{
	  for (mace::list < mace::string >::const_iterator lit =
	       mit->second.begin (); lit != mit->second.end (); lit++)
	    {
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
    mace::MaceAddr getNodeByContext (const mace::string & contextName)
    {
      ADD_SELECTORS ("ContextMapping::getNodeByContext");
      if (!mapped)
	{
	  return defaultAddress;
	}
      ScopedLock sl (alock);

      if (mapping.find (contextName) == mapping.end ())
	{
	  // complain
	  maceerr << "can't find the node for context name '" << contextName
	    << "'" << Log::endl;
	  for (mace::map < mace::string, mace::MaceAddr >::iterator mapit =
	       mapping.begin (); mapit != mapping.end (); mapit++)
	    {
	      maceerr << "'" << mapit->first << "' mapped to " << mapit->
		second << Log::endl;
	    }
	  return SockUtil::NULL_MACEADDR;
	}
      else
	{
	  return mapping[contextName];
	}
    }
    // chuangw: assuming this is called by head node
    bool accessedContext (const mace::string & contextName)
    {
      //ADD_SELECTORS("ContextMapping::hasContext");
      ScopedLock sl (alock);

      if (accessedContexts.find (contextName) == accessedContexts.end ())
	{
	  accessedContexts.insert (contextName);
	  return false;
	}
      return true;
    }
    // FIXME: update --> add/delete/replace?
    // chuangw: currently assuming the mapping is persistent, not changing after initialization.
    bool updateMapping (const mace::MaceAddr & oldNode,
			const mace::MaceAddr & newNode)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      for (mace::map < mace::string, mace::MaceAddr >::iterator mit =
	   mapping.begin (); mit != mapping.end (); mit++)
	{
	  if (mit->second == oldNode)
	    {
	      mit->second = newNode;
	    }
	}

      nodes.insert (newNode);
      return true;

    }
    bool updateMapping (const mace::MaceAddr & node,
			const mace::list < mace::string > &contexts)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      for (mace::list < mace::string >::const_iterator lit =
	   contexts.begin (); lit != contexts.end (); lit++)
	{
	  mapping[*lit] = node;
	}
      nodes.insert (node);
      return true;

    }
    bool updateMapping (const mace::MaceAddr & node,
			const mace::string & context)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      mapping[context] = node;
      nodes.insert (node);
      return true;

    }
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
    std::set < MaceAddr >& getAllNodes ()
    {
      return nodes;
    }

    static void updateVirtualNodes (const uint32_t nodeid,
				    const MaceAddr & addr)
    {
      ScopedLock sl (hlock);
      virtualNodes[nodeid] = addr;
    }

    static const MaceAddr & lookupVirtualNode (const uint32_t nodeid)
    {
      ScopedLock sl (hlock);
      return virtualNodes[nodeid];
    }

    // chuangw: TODO: work on this....
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

    static mace::string & getHeadContext ()
    {
      return headContext;
    }
    static MaceKey & getVirtualNodeMaceKey ()
    {
      return vnodeMaceKey;
    }
    static void setVirtualNodeMaceKey (const MaceKey & addr)
    {
      vnodeMaceKey = addr;
    }

    static void setInitialMapping (const mace::map < mace::string,
				   mace::map < MaceAddr ,
				   mace::list < mace::string > > >&mapping)
    {
      initialMapping = mapping;
    }

    static mace::map < MaceAddr ,
      mace::list < mace::string >
      >&getInitialMapping (const mace::string & serviceName)
    {
      return initialMapping[serviceName];
    }

  protected:

  private:
    MaceAddr defaultAddress;

    static mace::string headContext;
    static pthread_mutex_t alock;
    static pthread_mutex_t hlock;
    mace::map < mace::string, mace::MaceAddr > mapping;

    mace::set < mace::string > accessedContexts;

    std::set < mace::MaceAddr > nodes;
    mace::MaceAddr head;

    static ContextDAGEntry *DAGhead;

    bool mapped;

    static std::map < uint32_t, MaceAddr > virtualNodes;
    static mace::MaceKey vnodeMaceKey;

    static mace::map < mace::string, mace::map < MaceAddr,
      mace::list < mace::string > > >initialMapping;
  };

}
#endif // CONTEXTMAPPING_H
