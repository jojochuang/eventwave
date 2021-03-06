/* 
 * ContextMapping.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2013, Wei-Chiu Chuang
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

#include "MaceKey.h"
#include "m_map.h"
#include "mvector.h"
#include "mlist.h"
#include "mace-macros.h"
#include "Util.h"
#include "SockUtil.h"
#include "ThreadStructure.h"
#include "Event.h"
#include <utility>
#include <deque>
#include "Serializable.h"
#include "Printable.h"
#include "mace.h"
#include "ContextLock.h"

/**
 * \file ContextMapping.h
 * \brief declares the ContextMapping class and ContextEventRecord class.
 */
namespace mace
{
  /**
   * \brief Context record at head node
   *
   * */
  class ContextEventRecord {
  // TODO: make event record to be integer array
    class ContextNode;
    typedef mace::vector< ContextNode*, mace::SoftState > ContextNodeType;
    typedef mace::list< ContextNode*, mace::SoftState>  ChildContextNodeType;
    typedef mace::hash_map< mace::string, uint64_t > ContextNameIDType;
  public:
    ContextEventRecord(){
      contexts.push_back(  new ContextNode("(head)", 0, 1 ) );
    }
    ~ContextEventRecord(){
      for( ContextNodeType::iterator cnIt = contexts.begin(); cnIt != contexts.end(); cnIt++ ){
        delete *cnIt; 
      }
    }

    /// record a new context in the head node.
    /// \todo now that contexts can be deleted, new context id will be generated differently.
    void createContextEntry( const mace::string& contextName, const uint32_t contextID, const uint64_t firstEventID ){
      ADD_SELECTORS ("ContextEventRecord::createContext");
      // TODO: mutex lock?
      ASSERTMSG( contexts.size() == contextID , "The newly added context id doesn't match the expected value!" );
      ContextNode* node = new ContextNode(contextName, contextID, firstEventID );
      contexts.push_back( node );

      contextNameToID[ contextName ] = contextID;

      if( ! isGlobalContext( contextName ) ){
        // update the parent context node
        ContextNode* parent = getParentContextNode( contextName);
        ASSERT( parent != node );
        parent->childContexts.push_back( node );
      }
    }
    
    /**
     * update the now_serving number of the context.
     * Returns the last now_serving number
     * */
    void updateContext( const mace::string& contextName, const uint64_t newEventID, mace::Event::EventSkipRecordType& childContextSkipIDs ){
      ADD_SELECTORS ("ContextEventRecord::updateContext");
      uint32_t contextID = findContextIDByName( contextName );

      updateContext( contextID, newEventID, childContextSkipIDs );
    }
    //TODO: WC: transform the recursion into iteration.
     void updateContext( const uint32_t contextID, const uint64_t newEventID, mace::Event::EventSkipRecordType& childContextSkipIDs ){
      ADD_SELECTORS ("ContextEventRecord::updateContext");

      ContextNode* node = contexts[ contextID ];
      uint64_t last_now_serving = node->current_now_serving;
      node->current_now_serving = newEventID;

      //childContextSkipIDs[ contextID ] = last_now_serving;
      /*childContextSkipIDs.insert( childContextSkipIDs.begin(),
        mace::pair<uint32_t,uint64_t>( contextID, last_now_serving ) );*/
      childContextSkipIDs.set( contextID, last_now_serving );

      if( !node->childContexts.empty() ){
        childContextSkipIDs.initChildSkipRecord();
        ChildContextNodeType::iterator childCtxIt;
        for( childCtxIt = node->childContexts.begin(); childCtxIt != node->childContexts.end(); childCtxIt++ ){
          ContextNode* const childContextNode = *childCtxIt;
          const uint32_t childContextID = childContextNode->contextID;
          ASSERT( node != childContextNode ); // a context can not be its parent/child
          updateChildContext( childContextNode, last_now_serving, newEventID, childContextSkipIDs[childContextID] );
        }
      }

    }
    void updateChildContext( ContextNode* node, const uint64_t pastEventID, const uint64_t newEventID, mace::Event::EventSkipRecordType& childContextSkipIDs ){
      ADD_SELECTORS ("ContextEventRecord::updateChildContext");
      ASSERTMSG( node != NULL, "The context id does not exist!" );

      uint64_t last_now_serving = node->current_now_serving;
      node->current_now_serving = newEventID;

        // chuangw: This might happen if an event starts at this child context after the parent context was visited last time
       // otherwise: the last event accessing this child context was the same one that visited the parent.
      if( last_now_serving > pastEventID ){
        //childContextSkipIDs[ node->contextID ] = last_now_serving;
        childContextSkipIDs.set(  node->contextID , last_now_serving );
      }else{
        childContextSkipIDs.set(  node->contextID , 0 );
      }
      // so implicitly, if skip id of a context is not found, runtime should search for the skip id of the parent context, and so on so forth.

      if( !node->childContexts.empty() ){
        childContextSkipIDs.initChildSkipRecord();
        ChildContextNodeType::iterator childCtxIt;
        for( childCtxIt = node->childContexts.begin(); childCtxIt != node->childContexts.end(); childCtxIt++ ){
          //updateChildContext( *childCtxIt, last_now_serving, newEventID, childContextSkipIDs );
          ContextNode* const childContextNode = *childCtxIt;
          const uint32_t childContextID = childContextNode->contextID;
          ASSERT( node != childContextNode ); // a context can not be its parent/child
          updateChildContext( childContextNode, last_now_serving, newEventID, childContextSkipIDs[childContextID] );
        }
      }
    }
    void deleteContextEntry( mace::string const& contextName, uint32_t contextID, uint64_t eventID ){
      delete contexts[ contextID ];
      contextNameToID.erase( contextName );

    }
    
  protected:
  private:
    /**
     * \brief Internal structure to store a context record 
     *
     * */
    class ContextNode{
    public:
      ContextNode( const mace::string& contextName, const uint32_t contextID, const uint64_t firstEventID ):
        contextName( contextName ), contextID( contextID ), 
        /*last_now_serving( firstEventID ), */current_now_serving( firstEventID){
      }
      mace::string contextName;
      uint32_t contextID;
      //uint64_t last_now_serving;
      uint64_t current_now_serving;
      ChildContextNodeType childContexts;
    };

    ContextNameIDType contextNameToID;
    ContextNodeType contexts;

    inline bool isGlobalContext(const mace::string& contextID){
      return contextID.empty();
    }

    /* internal translation from contextName (string) to contextID (integer)
     * internally everything is recorded using the contextID for efficiency. 
     * To communicate with the external interface,
     * the transation from name to id is necessary.
     * */
    inline uint32_t findContextIDByName(const mace::string& contextName){
      ContextNameIDType::iterator ctxIDIt = contextNameToID.find( contextName );
      ASSERT( ctxIDIt != contextNameToID.end() );
      return ctxIDIt->second;
    }

    ContextNode* getParentContextNode(const mace::string& childContextID){
      ADD_SELECTORS ("ContextEventRecord::getParentContextNode");
      // find the parent context
      mace::string parent;
      ASSERTMSG( !childContextID.empty(), "global context does not have parent!" );

      size_t lastDelimiter = childContextID.find_last_of("." );
      if( lastDelimiter == mace::string::npos ){
        parent = ""; // global context
      }else{
        parent = childContextID.substr(0, lastDelimiter );
      }
      uint32_t parentID = findContextIDByName( parent );

      ASSERTMSG( parentID < contexts.size(), "Parent ID not found in contexts!"  );

      return contexts[ parentID ];

    }
  };


    class ContextMapEntry: public PrintPrintable, public Serializable{
    public:
      mace::MaceAddr addr;
      mace::set< uint32_t > child;
      mace::string name;
      uint32_t parent;

      ContextMapEntry() {} // default constructor required by mace::hash_map
      ContextMapEntry( const mace::MaceAddr& addr, const mace::set< uint32_t >& child, const mace::string& name, const uint32_t parent ):
        addr( addr ), child( child ), name( name ), parent( parent ){
      }

      void print(std::ostream& out) const;
      void printNode(PrintNode& pr, const std::string& name) const;

      virtual void serialize(std::string& str) const{
        mace::serialize( str, &addr );
        mace::serialize( str, &child );
        mace::serialize( str, &name );
        mace::serialize( str, &parent );
      }
      virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;
        serializedByteSize += mace::deserialize( is, &addr   );
        serializedByteSize += mace::deserialize( is, &child   );
        serializedByteSize += mace::deserialize( is, &name   );
        serializedByteSize += mace::deserialize( is, &parent   );
      
        return serializedByteSize;
      }
    };


  /** 
   * \brief maps context to node or vice versa
   *
   * Each context service has its context mapping. Whenever a new context is added, or when a context is migrated to a new node,
   * head node creates a new mapping version.
   * */
  class ContextMapping: public PrintPrintable, public Serializable
  {
  public:
    ContextMapping () : nContexts(0) {
      // empty initialization
    }
    ContextMapping (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ADD_SELECTORS ("ContextMapping::(constructor)");
    }
    /// override assignment operator
    ContextMapping& operator=(const ContextMapping& orig){
      ScopedLock sl (alock);
      ASSERTMSG( this != &orig, "Self assignment is forbidden!" );
      head = orig.head;
      mapping = orig.mapping;
      nodes = orig.nodes;
      nContexts = orig.nContexts;
      nameIDMap = orig.nameIDMap;
      return *this;
    }
    /// copy constructor
    ContextMapping (const mace::ContextMapping& orig) { 
      *this = orig ;
    }
    // destructor
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
        mace::serialize( str, &head );
        mace::serialize( str, &mapping );
        mace::serialize( str, &nodes );
        mace::serialize( str, &nContexts );
        mace::serialize( str, &nameIDMap );
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;

        serializedByteSize += mace::deserialize( is, &head   );
        serializedByteSize += mace::deserialize( is, &mapping   );
        serializedByteSize += mace::deserialize( is, &nodes   );
        serializedByteSize += mace::deserialize( is, &nContexts   );
        serializedByteSize += mace::deserialize( is, &nameIDMap   );

        return serializedByteSize;
    }
    void setDefaultAddress (const MaceAddr & addr) {
      ScopedLock sl (alock);
      head = addr;
    }
    /// public interface of snapshot()
    const mace::ContextMapping* snapshot(const uint64_t& ver) const{
        mace::ContextMapping* _ctx = new mace::ContextMapping(*this); // make a copy
        snapshot( ver, _ctx );
        ThreadStructure::setEventContextMappingVersion(ver);

        return _ctx;
    }
    /// create a read-only snapshot using the current event ticket as the version number
    /// @return mace::ContextMapping* the created snapshot object
    const mace::ContextMapping* snapshot() const{
        const uint64_t& ver = ThreadStructure::myEvent().getEventID();
        return snapshot( ver );
    }
    /// returns true if there is a snapshot with version equals current event ticket number
    bool hasSnapshot() const{
      return hasSnapshot( ThreadStructure::myEvent().getEventID() );
    }
    /// returns true if there is a snapshot with version equals ver
    /// @param ver the snapshot version number
    bool hasSnapshot(const uint64_t ver) const;
    /// insert a context mapping snapshot.
    void snapshotInsert(const uint64_t& ver, const mace::ContextMapping& snapshotMap) const{
        mace::ContextMapping* _ctx = new mace::ContextMapping( snapshotMap ); // make a copy
        snapshot( ver, _ctx );
    }
    /// remove a context mapping snapshot.
    void snapshotRelease(const uint64_t& ver) const{ // clean up when event commits
      ADD_SELECTORS("ContextMapping::snapshotRelease");
      ScopedLock sl( alock );
      while( !versionMap.empty() && versionMap.begin()->first < ver ){
        macedbg(1) << "Deleting snapshot version " << versionMap.begin()->first << " for service " << this << " value " << versionMap.begin()->second << Log::endl;
        delete versionMap.begin()->second;
        versionMap.erase( versionMap.begin() );
      }
    }

    void loadMapping (const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ScopedLock sl (alock);
      ADD_SELECTORS ("ContextMapping::loadMapping");
      for (mace::map < mace::MaceAddr, mace::list < mace::string > >::const_iterator mit = mkctxmapping.begin (); mit != mkctxmapping.end (); mit++) {
        for (mace::list < mace::string >::const_iterator lit = mit->second.begin (); lit != mit->second.end (); lit++) {
          if (lit->compare ( headContextName ) == 0) { // special case: head node
            head = mit->first;
            nodes[ head ] ++;
          } else {
            defaultMapping[ *lit ] = mit->first;
          }
        }
      }
    }

    /// return a snapshot context mapping object
    const mace::ContextMapping& getSnapshot(const uint64_t lastWrite) const{
      // assuming the caller of this method applies a mutex.
      ADD_SELECTORS ("ContextMapping::getSnapshot");
      ScopedLock sl (alock);
      VersionContextMap::const_iterator i = versionMap.find( lastWrite );
      if (i == versionMap.end()) {
        // TODO: perhaps the context mapping has not arrived yet.
        // block waiting
        pthread_cond_t cond;
        pthread_cond_init( &cond, NULL );
        snapshotWaitingThreads[ lastWrite ].insert( &cond );
        macedbg(1)<< "The context map snapshot version "<< lastWrite <<" has not arrived yet. wait for it"<< Log::endl;
        pthread_cond_wait( &cond, &alock );
        pthread_cond_destroy( &cond );
        i = versionMap.find( lastWrite );
        ASSERT( i != versionMap.end() );
      }
      sl.unlock();
      macedbg(1)<<"Read from snapshot version: "<< lastWrite <<Log::endl;
      return *(i->second);
    }
    /// return a snapshot context mapping object of version equals the current event ticket
    const mace::ContextMapping& getSnapshot() const{
      // assuming the caller of this method applies a mutex.
      ADD_SELECTORS ("ContextMapping::getSnapshot");
      const uint64_t lastWrite = ThreadStructure::getEventContextMappingVersion();
      return getSnapshot( lastWrite );
    }
    /// find in the given snapshot object, the node corresponding to a context, using the canonical name of the context
    static const mace::MaceAddr& getNodeByContext (const mace::ContextMapping& snapshotMapping, const mace::string & contextName)
    {
      const uint32_t contextID = snapshotMapping.findIDByName( contextName );
      return snapshotMapping._getNodeByContext( contextID );
    }
    /// find in the given snapshot object, the node corresponding to a context, using the numberical id of the context
    static const mace::MaceAddr& getNodeByContext (const mace::ContextMapping& snapshotMapping, const uint32_t contextID)
    {
      return snapshotMapping._getNodeByContext( contextID );
    }
    const mace::MaceAddr& getNodeByContext (const mace::string & contextName) const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      const uint32_t contextID = ctxmapSnapshot.findIDByName( contextName );
      return ctxmapSnapshot._getNodeByContext( contextID );
    }
    const bool hasContext (const mace::string & contextName) const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._hasContext( contextName );
    }
    const bool hasContext ( uint64_t const& version, const mace::string & contextName) const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot( version );
      return ctxmapSnapshot._hasContext( contextName );
    }

    /* this is another version of findIDByName, but upon unknown context name, instead of abort, it returns zero 
     * */
    static uint32_t hasContext2 ( const mace::ContextMapping& snapshotMapping, const mace::string & contextName)
    {
      mace::hash_map< mace::string, uint32_t >::const_iterator mit = snapshotMapping.nameIDMap.find( contextName );
      if( mit == snapshotMapping.nameIDMap.end() ){
        return 0;
      }
      return mit->second;
    }
    
    static const mace::set<uint32_t>& getChildContexts (const mace::ContextMapping& snapshotMapping, const mace::string & contextName)
    {
      const uint32_t contextID = snapshotMapping.findIDByName( contextName );
      return snapshotMapping._getChildContexts( contextID );
    }
    static const mace::set<uint32_t>& getChildContexts (const mace::ContextMapping& snapshotMapping, const uint32_t contextID)
    {
      return snapshotMapping._getChildContexts( contextID );
    }

    const mace::set<uint32_t>& getChildContexts (const mace::string & contextName) const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      const uint32_t contextID = ctxmapSnapshot.findIDByName( contextName );
      return ctxmapSnapshot._getChildContexts( contextID );
    }
    const mace::set<uint32_t>& getChildContexts (const uint32_t contextID) const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._getChildContexts( contextID );
    }
    static const mace::map<uint32_t, mace::string> getSubTreeContexts (const mace::ContextMapping& snapshotMapping, const mace::string & contextName) 
    {
      const uint32_t contextID = snapshotMapping.findIDByName( contextName );

      return getSubTreeContexts( snapshotMapping, contextID );
    }
    static const mace::map<uint32_t, mace::string> getSubTreeContexts (const mace::ContextMapping& snapshotMapping, const uint32_t contextID)
    {
      ContextMapType::const_iterator mit = snapshotMapping.mapping.find( contextID );
      ASSERT( mit != snapshotMapping.mapping.end() );
      mace::map<uint32_t, mace::string> offsprings;
      const mace::set< uint32_t >& childContexts = snapshotMapping._getChildContexts( contextID );
      offsprings[ contextID ] = mit->second.name;
      /* chuangw: recursion....maybe slow. I'll worry about the efficiency later */
      for( mace::set< uint32_t >::const_iterator childIt = childContexts.begin(); childIt != childContexts.end(); childIt ++ ){
        const mace::map< uint32_t, mace::string > subtree = snapshotMapping.getSubTreeContexts( snapshotMapping, *childIt );
        offsprings.insert( subtree.begin(), subtree.end() );
      }
      
      return offsprings;
    }
    bool updateMapping (const mace::MaceAddr & oldNode,
			const mace::MaceAddr & newNode)
    {
      ADD_SELECTORS ("ContextMapping::updateMapping");

      ScopedLock sl (alock);
      uint32_t contexts = 0;
      for ( ContextMapType::iterator mit = mapping.begin (); mit != mapping.end (); mit++) {
        if (mit->second.addr == oldNode) {
            mit->second.addr = newNode;
            contexts++;
        }
      }
      // XXX: head node??
      nodes[ newNode ] = contexts;
      if( oldNode != head ){
        nodes.erase( oldNode );
      }
      // FIXME: what is newNode already exist in the logical node?
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
    std::pair< bool , uint32_t> updateMapping (const mace::MaceAddr & node, const mace::string & context){
      ADD_SELECTORS ("ContextMapping::updateMapping");
      ScopedLock sl (alock);

      if( _hasContext( context ) ){
        const uint32_t contextID = findIDByName( context );
        mace::MaceAddr oldNode = mapping[ contextID ].addr;
        // XXX: head node??
        if( --nodes[ oldNode ] == 0 && oldNode != head){
          nodes.erase( oldNode );
        }
        mapping[ contextID ].addr = node;
      }else{

        insertMapping( context, node );
      }

      bool newNode = false;
      if( nodes.find( node ) == nodes.end() ){
        newNode = true;
      }

      nodes[ node ] ++;

      return std::pair< bool, uint32_t >( newNode, nContexts );
    }
    // create a new mapping for a context not mapped before.
    // @return a pair of the MaceAddr as well as the numbercal ID of the context
    const std::pair< mace::MaceAddr, uint32_t> newMapping( const mace::string& contextID ){
      ADD_SELECTORS ("ContextMapping::newMapping");
      /*if(  mace::AgentLock::getCurrentMode() != mace::AgentLock::WRITE_MODE ){
        ABORT("must be protected by head-node write lock!" );
      }*/
      // heuristic 1: if a default mapping is defined, use it.
      mace::map< mace::string , mace::MaceAddr >::const_iterator dmIt = defaultMapping.find( contextID );
      if( dmIt != defaultMapping.end() ){
        const mace::MaceAddr addr = dmIt->second;
        defaultMapping.erase( contextID );
        std::pair<bool, uint32_t> newNode = updateMapping( addr, contextID );
        return std::pair< mace::MaceAddr, uint32_t>(addr, newNode.second);
      }

      // heuristic 2: map the context to the same node as its parent context
      if( contextID.empty() ){ // Special case: global context map to head node
        const mace::MaceAddr& headAddr = ContextMapping::getHead( *this ); // find head addr in the latest mapping
        ASSERTMSG( headAddr != SockUtil::NULL_MACEADDR, "Head node address is NULL_MACEADDR!" );
        std::pair<bool, uint32_t> newNode = updateMapping( headAddr, contextID );
        return std::pair< mace::MaceAddr, uint32_t>(headAddr, newNode.second);
      }

      // find parent context id
      mace::string parent = getParentContextName( contextID );
      // chuangw: this helper method is called before a new snapshot is created. 
      // it should use the old snapshot to find out the parent context mapping.
      //
      // chuangw: use the latest version of mapping
      const mace::MaceAddr& parentAddr = getNodeByContext(*this, parent);
      ASSERTMSG( parentAddr != SockUtil::NULL_MACEADDR, "Parent node address is NULL_MACEADDR!" );
      std::pair<bool, uint32_t> newNode = updateMapping( parentAddr, contextID );
      return std::pair< mace::MaceAddr, uint32_t>(parentAddr, newNode.second);

    }
    mace::MaceAddr removeMapping( mace::string const& contextName ){
      const uint32_t contextID = findIDByName( contextName );
      nContexts --;

      mace::MaceAddr nodeAddr = _getNodeByContext( contextID );
      //mace::map < mace::MaceAddr, uint32_t >::iterator mit = mapping.find( nodeAddr );
      ContextMapType::iterator mit = mapping.find( contextID );

      ContextMapEntry & entry = mit->second;
      ASSERT( entry.child.empty() ); // must not have child context
      mapping.erase( mit );

      mace::map < mace::MaceAddr, uint32_t >::iterator nodeIt = nodes.find( nodeAddr );
      if( --nodeIt->second  == 0 ){
        nodes.erase( nodeIt );
      }


      nameIDMap.erase( contextName );

      return nodeAddr;
    }
    void newHead( const MaceAddr& newHeadAddr ){
      head = newHeadAddr;
    }

    void printMapping () const
    {
      const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      return ctxmapSnapshot._printMapping(  );
    }
    
    const mace::MaceAddr & getHead () const
    {
      //ADD_SELECTORS ("ContextMapping::getHead");
      //const mace::ContextMapping& ctxmapSnapshot = getSnapshot();
      //return ctxmapSnapshot._getHead(  );
      return _getHead();
    }
    static const mace::MaceAddr & getHead (const mace::ContextMapping& ctxmapSnapshot)
    {
      return ctxmapSnapshot._getHead(  );
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
    static const mace::map < MaceAddr, uint32_t >& getAllNodes (const mace::ContextMapping& ctxmapSnapshot)
    {
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
    static const mace::string& getHeadContext ()
    {
      return headContextName;
    }
    static const uint32_t getHeadContextID ()
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
    }

    static mace::map < MaceAddr , mace::list < mace::string > >&getInitialMapping (const mace::string & serviceName)
    {
      return initialMapping[serviceName];
    }

    static mace::map < mace::string, mace::map < MaceAddr, mace::list < mace::string > > >&getInitialMapping ()
    {
      return initialMapping;
    }
    static const mace::string& getNameByID( const mace::ContextMapping& snapshotMapping, const uint32_t contextID ){
      ContextMapType::const_iterator it = snapshotMapping.mapping.find( contextID );
      ASSERT( it != snapshotMapping.mapping.end() );
      return it->second.name;
    }
    const uint32_t findIDByName( const mace::string& contextName ) const {
      mace::hash_map< mace::string, uint32_t >::const_iterator mit = nameIDMap.find( contextName );
      if( mit == nameIDMap.end() ){
        ADD_SELECTORS ("ContextMapping::findIDByName");
        maceerr<<"context '" << contextName << "' is not found!"<<Log::endl;
        ABORT("context not found");
      }
      return mit->second;
    }
    const uint32_t getParentContextID( const uint32_t contextID ) const{
      ContextMapType::const_iterator it = mapping.find( contextID );
      ASSERT( it != mapping.end() );

      // XXX: global context does not have parent
      
      return it->second.parent;
    }
    void getContextsOfNode(mace::MaceAddr const& nodeAddr, mace::list<mace::string >& contextNames) const{  // chuangw: inefficient traversal... 

      for( ContextMapType::const_iterator mIt = mapping.begin(); mIt != mapping.end(); mIt ++ ){
        if( mIt->second.addr == nodeAddr ){
          mace::string contextName = mace::ContextMapping::getNameByID( *this, mIt->first );
          contextNames.push_back( contextName );
        }

      }
    }
    
    static void getAncestorContextID( const mace::ContextMapping& snapshotMapping, const uint32_t contextID, mace::set< uint32_t >& ancestorContextIDs ){
      uint32_t traverseID = contextID;
      while( traverseID !=  1 ){ // global context is assumed to be the first context.
        uint32_t parent = snapshotMapping.getParentContextID( traverseID );
        std::pair<mace::set< uint32_t >::iterator, bool> result = ancestorContextIDs.insert( parent );
        traverseID = parent;
        if( result.second == false ){ // Optimization: if this ancestor is already in the set, its ancestor must also be in the set already.
          break;
        }
      }
    }
    static const uint32_t HEAD_CONTEXT_ID = 0;
  private:
    mace::string getParentContextName( const mace::string& contextID )const {
      mace::string parent;
      size_t lastDelimiter = contextID.find_last_of("." );
      if( lastDelimiter == mace::string::npos ){
        parent = ""; // global context
      }else{
        parent = contextID.substr(0, lastDelimiter );
      }
      return parent;
    }
    // add a new context entry into mapping
    void insertMapping(const mace::string& contextName, const mace::MaceAddr& addr){
      ASSERT( !_hasContext( contextName ) );
      nContexts++;
      // add an entry into the parent context 
      if( contextName.empty() ){ // if not global context
        mapping[ nContexts ].parent = 0;
      }else{
        const mace::string parentName = getParentContextName( contextName );
        const uint32_t parentID = findIDByName( parentName );
        mapping[ parentID ].child.insert( nContexts );

        mapping[ nContexts ].parent = parentID;
      }
      mapping[ nContexts ].addr = addr;
      mapping[ nContexts ].name = contextName;

      nameIDMap[ contextName ] = nContexts;
    }
    void snapshot(const uint64_t& ver, mace::ContextMapping* _ctx) const{
      ADD_SELECTORS("ContextMapping::snapshot");
      macedbg(1) << "Snapshotting version " << ver << " mapping: " << *_ctx << Log::endl;
      ScopedLock sl (alock);
      versionMap.insert( std::make_pair(ver, _ctx) );

      std::map< uint64_t, std::set< pthread_cond_t* > >::iterator condSetIt = snapshotWaitingThreads.find( ver );
      if( condSetIt != snapshotWaitingThreads.end() ){
        for( std::set< pthread_cond_t* >::iterator condIt = condSetIt->second.begin(); condIt != condSetIt->second.end(); condIt++ ){
          pthread_cond_signal( *condIt );
        }
        snapshotWaitingThreads.erase( condSetIt );

      }
    }
    const mace::MaceAddr& _getNodeByContext (const uint32_t contextID) const
    {
      ADD_SELECTORS ("ContextMapping::getNodeByContext");
      ContextMapType::const_iterator it = mapping.find( contextID );
      ASSERTMSG( it != mapping.end(), "can't find corresponding context!");
      
      return it->second.addr;
    }
    const bool _hasContext (const mace::string & contextName) const
    {
      ADD_SELECTORS ("ContextMapping::hasContext");
      return nameIDMap.count( contextName ) == 1;
    }
    const mace::set< uint32_t >& _getChildContexts (const uint32_t contextID) const
    {
      ADD_SELECTORS ("ContextMapping::getChildContexts");
      ContextMapType::const_iterator it = mapping.find( contextID );
      ASSERTMSG( it != mapping.end(), "can't find corresponding context!");
      
      return it->second.child;
    }
    void _printMapping () const
    {
      ADD_SELECTORS ("ContextMapping::printMapping");

      for ( ContextMapType::const_iterator mapIt = mapping.begin (); mapIt != mapping.end (); mapIt++) {
          macedbg(1) << mapIt->first <<" -> " << mapIt->second << Log::endl;
      }
    }
    const MaceAddr& _getHead () const
    {
      ADD_SELECTORS ("ContextMapping::_getHead");

      return head;
    }
    const mace::map < MaceAddr, uint32_t >& _getAllNodes () const
    {
      return nodes;
    }


protected:
    typedef std::map< uint64_t, const mace::ContextMapping* > VersionContextMap;
    mutable VersionContextMap versionMap;

private:
    typedef mace::hash_map < uint32_t,  ContextMapEntry> ContextMapType;

    mace::map<mace::string, mace::MaceAddr > defaultMapping; ///< User defined mapping. This should only be accessed by head node. Therefore it is not serialized


    mace::MaceAddr head;
    ContextMapType mapping; ///< The mapping between contexts to physical node address
    mace::map < mace::MaceAddr, uint32_t > nodes; ///< maintain a counter of contexts on this node. When it decrements to zero, remove the node from node set.
    uint32_t nContexts; ///< number of total contexts currently

    mace::hash_map< mace::string, uint32_t > nameIDMap;

    ///<------ static members
    static const uint32_t headContext;
    static mace::string headContextName;
    static pthread_mutex_t alock; ///< This mutex is used to protect static variables -- considering to drop it because process-wide sharing should use AgentLock instead.
    static std::map < uint32_t, MaceAddr > virtualNodes;
    static mace::MaceKey vnodeMaceKey; ///< The local logical node MaceKey
    static mace::map < mace::string, mace::map < MaceAddr, mace::list < mace::string > > >initialMapping;
    static std::map< uint64_t, std::set< pthread_cond_t* > > snapshotWaitingThreads;
  };
  struct addSnapshotContextID {
    mace::ContextMapping const& currentMapping;
    mace::vector< uint32_t >& contextIDVector;
    addSnapshotContextID( mace::ContextMapping  const& currentMapping, mace::vector< uint32_t >& snapshotContextID ): 
      currentMapping(currentMapping), contextIDVector(snapshotContextID) { }

    void operator() ( mace::string const& contextIDName ){
      contextIDVector.push_back(  currentMapping.findIDByName( contextIDName ) );
    }
  };

}

#endif // CONTEXTMAPPING_H
