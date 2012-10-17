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
#include "HighLevelEvent.h"
#include <utility>
#include <deque>
#include "Serializable.h"
#include "Printable.h"
#include "mace.h"

namespace mace
{

  /*class ContextDAGEntry
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

  };*/

  class ContextMapping: public PrintPrintable, public Serializable
  {
  /*TODO: perhaps inherit from Printable to make debugging easier? */
  public:
    ContextMapping ()  {
      // empty initialization
    }
    ContextMapping (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ADD_SELECTORS ("ContextMapping::(constructor)");
      //init (vhead, mkctxmapping);
      //mapped = true;
    }
    // override assignment operator
    ContextMapping& operator=(const ContextMapping& orig){
      ASSERTMSG( this != &orig, "Self assignment is forbidden!" );
      mapping = orig.mapping;
      nodes = orig.nodes;
      return *this;
    }
    ContextMapping (const mace::ContextMapping& orig) { // copy constructor
      *this = orig ;
    }
    ~ContextMapping(){
      VersionContextMap::const_iterator snapshotVer = versionMap.begin();
      while (snapshotVer != versionMap.end()) {
        delete( snapshotVer->second );
        snapshotVer++;
      }
    }
    void print(std::ostream& out) const;
    void printNode(PrintNode& pr, const std::string& name) const;

    virtual void serialize(std::string& str) const{
        mace::serialize( str, &mapping );
        mace::serialize( str, &nodes );
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;

        serializedByteSize += mace::deserialize( is, &mapping   );
        serializedByteSize += mace::deserialize( is, &nodes   );

        return serializedByteSize;
    }
    void setDefaultAddress (const MaceAddr & addr) {
      head = addr;
      //nodes.insert( addr );
    }
    /* public interface of snapshot() */
    void snapshot(const uint64_t& ver) const{
        ASSERTMSG(  mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE,
        "context snapshotting must be protected by process-wide AgentLock!" );
        mace::ContextMapping* _ctx = new mace::ContextMapping(*this); // make a copy
        snapshot( ver, _ctx );
        ThreadStructure::setEventContextMappingVersion(ver);
    }
    void snapshot() const{
        const uint64_t& ver = ThreadStructure::myEvent().getEventID();
        snapshot( ver );
    }
    bool hasSnapshot(const uint64_t ver) const;
    void snapshotInsert(const uint64_t& ver, const mace::ContextMapping& snapshotMap) const{
        mace::ContextMapping* _ctx = new mace::ContextMapping( snapshotMap ); // make a copy
        snapshot( ver, _ctx );
    }
    void snapshotRelease(const uint64_t& ver) const{ // clean up when event commits
      ADD_SELECTORS("ContextMapping::snapshotRelease");
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
          if (lit->compare (headContext) == 0) { // special case: head node
            head = mit->first;
            nodes[ head ] ++;
          } else {
            defaultMapping[ *lit ] = mit->first;
          }
        }
      }
    }

#ifdef _USE_INIT_CONTEXTMAPPING
    void init (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr,
	       mace::list < mace::string > >&mkctxmapping)
    {
      // obsolete it 
      /*ScopedLock sl (alock);
      ADD_SELECTORS ("ContextMapping::init");
      head = vhead;
      for (mace::map < mace::MaceAddr, mace::list < mace::string > >::const_iterator mit = mkctxmapping.begin (); mit != mkctxmapping.end (); mit++) {
        for (mace::list < mace::string >::const_iterator lit = mit->second.begin (); lit != mit->second.end (); lit++) {
            mapping[*lit].first = mit->first;
            //insertMapping( *lit, mit->first );
        }
        nodes.insert (mit->first);
      }*/
    }
#endif

    const mace::ContextMapping& getSnapshot() const{
      // assuming the caller of this method applies a mutex.
      ADD_SELECTORS ("ContextMapping::getSnapshot");
      const uint64_t lastWrite = ThreadStructure::getEventContextMappingVersion();
      VersionContextMap::const_iterator i = versionMap.begin();
      while (i != versionMap.end()) {
        if (i->first == lastWrite) {
          break;
        }
        i++;
      }
      if (i == versionMap.end()) {
        Log::err() << "Error reading from snapshot " << lastWrite << " event " << ThreadStructure::myEvent().eventID << Log::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
        maceerr<< "Additional Information: " << ThreadStructure::myEvent() << Log::endl;
        VersionContextMap::const_iterator snapshotVer = versionMap.begin();
        maceerr<< "Available context snapshot version: ";
        while (snapshotVer != versionMap.end()) {
          maceerr<< snapshotVer->first <<" ";
          snapshotVer++;
        }
        maceerr<<Log::endl;
      }
      macedbg(1)<<"Read from snapshot version: "<< lastWrite <<Log::endl;
      return *(i->second);
    }
    const mace::MaceAddr getNodeByContext (const mace::ContextMapping& snapshotMapping, const mace::string & contextName) const
    {
      return snapshotMapping._getNodeByContext( contextName );
    }
    const mace::MaceAddr getNodeByContext (const mace::string & contextName) const
    {
      ScopedLock sl (alock);
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getNodeByContext( contextName );
    }
    // TODO: declare as a static method...
    const mace::set<mace::string>& getChildContexts (const mace::ContextMapping& snapshotMapping, const mace::string & contextID) const
    {
      return snapshotMapping._getChildContexts( contextID );
    }

    const mace::set<mace::string>& getChildContexts (const mace::string & contextID) const
    {
      ScopedLock sl (alock);
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getChildContexts( contextID );
    }
    static const mace::set<mace::string> getSubTreeContexts (const mace::ContextMapping& snapshotMapping, const mace::string & contextID) 
    {
      mace::set<mace::string> offsprings;
      const mace::set<mace::string>& childContexts = snapshotMapping._getChildContexts( contextID );
      offsprings.insert( contextID );
      for( mace::set<mace::string>::const_iterator childIt = childContexts.begin(); childIt != childContexts.end(); childIt ++ ){
        const mace::set< mace::string > subtree = getSubTreeContexts( snapshotMapping, *childIt );
        offsprings.insert( subtree.begin(), subtree.end() );
      }
      
      return offsprings;
    }
    bool updateMapping (const mace::MaceAddr & oldNode,
			const mace::MaceAddr & newNode)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");

      uint32_t contexts = 0;
      for (mace::map < mace::string, ContextMapEntry >::iterator mit = mapping.begin (); mit != mapping.end (); mit++) {
        if (mit->second.first == oldNode) {
            mit->second.first = newNode;
            contexts++;
        }
      }
      // XXX: head node??
      nodes[ newNode ] = contexts;
      if( oldNode != head ){
        nodes.erase( oldNode );
      }
      return true;

    }
    template< class T > 
    bool updateMapping (const mace::MaceAddr & node, const T& contexts)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");

      typename T::const_iterator lit;
      for ( lit = contexts.begin (); lit != contexts.end (); lit++) {
        updateMapping( node, *lit );
      }
      return true;

    }
    bool updateMapping (const mace::MaceAddr & node, const mace::string & context)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");

      ContextMapType::iterator it = mapping.find( context );
      bool newNode = false;
      if( nodes.find( node ) == nodes.end() ){
        newNode = true;
      }

      if( it != mapping.end() ){ // the context already exists
        mace::MaceAddr oldNode = it->second.first;
        // XXX: head node??
        if( --nodes[ oldNode ] == 0 && oldNode != head){
          nodes.erase( oldNode );
        }
      }
      nodes[ node ] ++;

      insertMapping( context, node );
      return newNode;


    }
    // create a new mapping for a context not mapped before.
    const std::pair< mace::MaceAddr, bool> newMapping( const mace::string& contextID ){
      ADD_SELECTORS ("ContextMapping::newMapping");
      ASSERTMSG( mace::AgentLock::getCurrentMode() == mace::AgentLock::WRITE_MODE, "must be protected by AgentLock::WRITE_MODE!" );
      // heuristic 1: if a default mapping is defined, use it.
      mace::map< mace::string , mace::MaceAddr >::const_iterator dmIt = defaultMapping.find( contextID );
      if( dmIt != defaultMapping.end() ){
        const mace::MaceAddr addr = dmIt->second;
        defaultMapping.erase( contextID );
        bool newNode = updateMapping( addr, contextID );
        return std::pair< mace::MaceAddr, bool>(addr, newNode);
      }

      // heuristic 2: map the context to the same node as its parent context
      if( contextID.empty() ){ // Special case: global context map to head node
        const mace::MaceAddr headAddr = getHead();
        ASSERTMSG( headAddr != SockUtil::NULL_MACEADDR, "Head node address is NULL_MACEADDR!" );
        bool newNode = updateMapping( headAddr, contextID );
        return std::pair< mace::MaceAddr, bool>(headAddr, newNode);
      }

      // find parent context id
      mace::string parent = getParentContextID( contextID );
      // chuangw: this helper method is called before a new snapshot is created. 
      // it should use the old snapshot to find out the parent context mapping.
      //
      // chuangw: use the latest version of mapping
      const mace::MaceAddr parentAddr = getNodeByContext(*this, parent);
      ASSERTMSG( parentAddr != SockUtil::NULL_MACEADDR, "Parent node address is NULL_MACEADDR!" );
      bool newNode = updateMapping( parentAddr, contextID );
      return std::pair< mace::MaceAddr, bool>(parentAddr, newNode);

    }

    void printMapping ()
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._printMapping(  );
    }
    // chuangw: assuming head does not migrate... so no need to get the snapshot
    const mace::MaceAddr & getHead ()
    {
      ADD_SELECTORS ("ContextMapping::getHead");
      // XXX: head is static variable, so supposedly should use mutex lock to prevent race-condition.
      // However, the current system does not assume head node can change/fail, so head should remain the same and there's no need to protect it.
      return head;
    }
    /*static void setHead (const mace::MaceAddr & h)
    {
      ADD_SELECTORS ("ContextMapping::setHead");
      ScopedLock sl (alock);
      head = h;
    }*/
    const mace::map < MaceAddr, uint32_t >& getAllNodes ()
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getAllNodes(  );
    }

    // this method modifies the latest context mapping.
    static void updateVirtualNodes (const uint32_t nodeid, const MaceAddr & addr)
    {
      ScopedLock sl (alock);
      virtualNodes[nodeid] = addr;
    }

    // chuangw: not used??
    static const MaceAddr & lookupVirtualNode (const uint32_t nodeid)
    {
      ScopedLock sl (alock);
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
      //mapped = true;
    }

    static mace::map < MaceAddr , mace::list < mace::string > >&getInitialMapping (const mace::string & serviceName)
    {
      return initialMapping[serviceName];
    }
  private:
    mace::string getParentContextID( const mace::string& contextID ){
      mace::string parent;
      size_t lastDelimiter = contextID.find_last_of("." );
      if( lastDelimiter == mace::string::npos ){
        parent = ""; // global context
      }else{
        parent = contextID.substr(0, lastDelimiter );
      }
      return parent;
    }
    void insertMapping(const mace::string& contextID, const mace::MaceAddr& addr){
      mapping[ contextID ].first = addr;
      // add an entry into the parent context 
      if( !contextID.empty() ){ // if not global context
        mace::string parent = getParentContextID( contextID );
        mapping[ parent ].second.insert( contextID );
      }
    }
    void snapshot(const uint64_t& ver, mace::ContextMapping* _ctx) const{
      ADD_SELECTORS("ContextMapping::snapshot");
      macedbg(1) << "Snapshotting version " << ver << " mapping: " << *_ctx << Log::endl;
      if ( !(  versionMap.empty() || versionMap.back().first < ver ) ){
        maceerr<< "versionMap.empty() = " << versionMap.empty() << "\n";
        maceerr<< "versionMap.back().first = " << versionMap.back().first << ", ver = " << ver << "\n";
        for( VersionContextMap::iterator vit = versionMap.begin(); vit != versionMap.end(); vit ++ ){
          maceerr<< "version: " << vit->first << ", snapshot = " << *( vit->second ) << "\n";
        }
        maceerr<< Log::endl;

        ASSERT( versionMap.empty() || versionMap.back().first < ver );
      }
      versionMap.push_back( std::make_pair(ver, _ctx) );
    }
    const mace::MaceAddr _getNodeByContext (const mace::string & contextName) const
    {
      ADD_SELECTORS ("ContextMapping::getNodeByContext");
      /*if (!mapped) {
        return defaultAddress;
      }*/
      ContextMapType::const_iterator mapit = mapping.find (contextName);
      if ( mapit == mapping.end ()) {
        // complain
        maceerr << "can't find the node for context name '" << contextName << "'" << Log::endl;
        for (ContextMapType::const_iterator mapit = mapping.begin (); mapit != mapping.end (); mapit++) {
           // maceerr << "'" << mapit->first << "' mapped to " << mapit-> second << Log::endl;
        }
        return SockUtil::NULL_MACEADDR;
      } else {
        return mapit->second.first;
      }
    }
    const mace::set< mace::string >& _getChildContexts (const mace::string& contextID) const
    {
      ADD_SELECTORS ("ContextMapping::getChildContexts");
    
      ContextMapType::const_iterator mapit = mapping.find (contextID);
      if ( mapit == mapping.end ()) {
        maceerr<<"context "<< contextID <<" is not found"<<Log::endl;
      }
      macedbg(1)<< "Child Contexts of ["<<contextID<< "] : "<< mapit->second.second<<Log::endl;
      return mapit->second.second;
      
    }
    void _printMapping () const
    {
      ADD_SELECTORS ("ContextMapping::printMapping");

      for ( ContextMapType::const_iterator mapIt = mapping.begin (); mapIt != mapping.end (); mapIt++) {
          macedbg(1) << mapIt->first <<" -> " << mapIt->second << Log::endl;
      }
    }
    const mace::map < MaceAddr, uint32_t >& _getAllNodes () const
    {
      return nodes;
    }

protected:
    typedef std::deque<std::pair<uint64_t, const mace::ContextMapping* > > VersionContextMap;
    mutable VersionContextMap versionMap;

  private:
    typedef mace::pair< mace::MaceAddr, mace::set<mace::string> > ContextMapEntry;
    typedef mace::map < mace::string,  ContextMapEntry> ContextMapType;

    mace::map<mace::string, mace::MaceAddr > defaultMapping; ///< User defined mapping. This should only be accessed by head node. Therefore it is not serialized
    ContextMapType mapping; ///< The mapping between contexts to physical node address
    mace::map < mace::MaceAddr, uint32_t > nodes; ///< TODO: maintain a counter of contexts on this node. When it decrements to zero, remove the node from node set.

    static const mace::string headContext;
    static pthread_mutex_t alock; ///< This mutex is used to protect static variables -- considering to drop it because process-wide sharing should use AgentLock instead.
    static mace::MaceAddr head;
    static std::map < uint32_t, MaceAddr > virtualNodes;
    static mace::MaceKey vnodeMaceKey; ///< The local logical node MaceKey
    static mace::map < mace::string, mace::map < MaceAddr, mace::list < mace::string > > >initialMapping;
  };

}

#endif // CONTEXTMAPPING_H
