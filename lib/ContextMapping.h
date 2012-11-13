/* 
 * ContextMapping.h : part of the Mace toolkit for building distributed systems
 * 
 * Copyright (c) 2012, Wei-Chiu Chuang
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
#include "ContextLock.h"

namespace mace
{
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
    
    /*
     * update the now_serving number of the context.
     * Returns the last now_serving number
     * */
    uint64_t updateContext( const mace::string& contextName, const uint64_t newEventID, mace::map< uint32_t, uint64_t>& childContextSkipIDs ){
      ADD_SELECTORS ("ContextEventRecord::updateContext");
      uint32_t contextID = findContextIDByName( contextName );

      ContextNode* node = contexts[ contextID ];
      uint64_t last_now_serving = node->current_now_serving;
      node->current_now_serving = newEventID;
      node->last_now_serving = last_now_serving;

      childContextSkipIDs[ contextID ] = last_now_serving;
      ChildContextNodeType::iterator childCtxIt;
      for( childCtxIt = node->childContexts.begin(); childCtxIt != node->childContexts.end(); childCtxIt++ ){
        ASSERT( node != *childCtxIt );
        updateChildContext( *childCtxIt, last_now_serving, newEventID, childContextSkipIDs);
      }

      return last_now_serving;
    }
    void updateChildContext( ContextNode* node, const uint64_t pastEventID, const uint64_t newEventID, mace::map< uint32_t, uint64_t>& childContextSkipIDs ){
      ADD_SELECTORS ("ContextEventRecord::updateChildContext");
      ASSERTMSG( node != NULL, "The context id does not exist!" );

      uint64_t last_now_serving = node->current_now_serving;
      node->current_now_serving = newEventID;
      node->last_now_serving = last_now_serving;

        // chuangw: This might happen if an event starts at this child context after the parent context was visited last time
       // otherwise: the last event accessing this child context was the same one that visited the parent.
      if( last_now_serving > pastEventID ){
      // chuangw: I comment it out. It's  likely to be inefficient. But I'll just use it and see what can happen
      // Nov 11: found a hack
        childContextSkipIDs[ node->contextID ] = last_now_serving;
      }
      // so implicitly, if skip id of a context is not found, runtime should search for the skip id of the parent context, and so on so forth.

      ChildContextNodeType::iterator childCtxIt;
      for( childCtxIt = node->childContexts.begin(); childCtxIt != node->childContexts.end(); childCtxIt++ ){
        updateChildContext( *childCtxIt, last_now_serving, newEventID, childContextSkipIDs );
      }
    }
    
  protected:
  private:
    class ContextNode{
    public:
      ContextNode( const mace::string& contextName, const uint32_t contextID, const uint64_t firstEventID ):
        contextName( contextName ), contextID( contextID ), last_now_serving( firstEventID ), current_now_serving( firstEventID){
      }
      mace::string contextName;
      uint32_t contextID;
      uint64_t last_now_serving;
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


  class ContextMapping: public PrintPrintable, public Serializable
  {
  /*TODO: perhaps inherit from Printable to make debugging easier? */
  public:
    ContextMapping () : nContexts(0) {
      // empty initialization
    }
    ContextMapping (const mace::MaceAddr & vhead, const mace::map < mace::MaceAddr, mace::list < mace::string > >&mkctxmapping) {
      ADD_SELECTORS ("ContextMapping::(constructor)");
    }
    // override assignment operator
    ContextMapping& operator=(const ContextMapping& orig){
      ScopedLock sl (alock);
      ASSERTMSG( this != &orig, "Self assignment is forbidden!" );
      mapping = orig.mapping;
      nodes = orig.nodes;
      nContexts = orig.nContexts;
      nameIDMap = orig.nameIDMap;
      return *this;
    }
    ContextMapping (const mace::ContextMapping& orig) { // copy constructor
      *this = orig ;
    }
    ~ContextMapping(){
      //ScopedLock sl (alock);
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
        mace::serialize( str, &nContexts );
        mace::serialize( str, &nameIDMap );
    }
    virtual int deserialize(std::istream & is) throw (mace::SerializationException){
        int serializedByteSize = 0;

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
    /* public interface of snapshot() */
    const mace::ContextMapping* snapshot(const uint64_t& ver) const{
        if(  mace::ContextBaseClass::headContext.getCurrentMode() != mace::ContextLock::WRITE_MODE &&
          mace::AgentLock::getCurrentMode() != mace::AgentLock::WRITE_MODE ){
          ABORT("context snapshotting must be protected by process-wide AgentLock!" );
        }
        mace::ContextMapping* _ctx = new mace::ContextMapping(*this); // make a copy
        snapshot( ver, _ctx );
        ThreadStructure::setEventContextMappingVersion(ver);

        return _ctx;
    }
    const mace::ContextMapping* snapshot() const{
        const uint64_t& ver = ThreadStructure::myEvent().getEventID();
        return snapshot( ver );
    }
    bool hasSnapshot() const{
      return hasSnapshot( ThreadStructure::myEvent().getEventID() );
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

    const mace::ContextMapping& getSnapshot() const{
      // assuming the caller of this method applies a mutex.
      ADD_SELECTORS ("ContextMapping::getSnapshot");
      const uint64_t lastWrite = ThreadStructure::getEventContextMappingVersion();
      ScopedLock sl (alock);
      VersionContextMap::const_reverse_iterator i = versionMap.rbegin();
      while (i != versionMap.rend()) {
        if (i->first == lastWrite) {
          break;
        }
        i++;
      }
      if (i == versionMap.rend()) {
        Log::err() << "Error reading from snapshot " << lastWrite << " event " << ThreadStructure::myEvent().eventID << Log::endl;
        maceerr<< "Additional Information: " << ThreadStructure::myEvent() << Log::endl;
        VersionContextMap::const_iterator snapshotVer = versionMap.begin();
        maceerr<< "Available context snapshot version: ";
        while (snapshotVer != versionMap.end()) {
          maceerr<< snapshotVer->first <<" ";
          snapshotVer++;
        }
        maceerr<<Log::endl;
        ABORT("Tried to read from snapshot, but snapshot not available!");
      }
      sl.unlock();
      macedbg(1)<<"Read from snapshot version: "<< lastWrite <<Log::endl;
      return *(i->second);
    }
    static const mace::MaceAddr& getNodeByContext (const mace::ContextMapping& snapshotMapping, const mace::string & contextName)
    {
      const uint32_t contextID = snapshotMapping.findIDByName( contextName );
      return snapshotMapping._getNodeByContext( contextID );
    }
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
    // TODO: declare as a static method...
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
      if(  mace::ContextBaseClass::headContext.getCurrentMode() != mace::ContextLock::WRITE_MODE /*&&
        mace::AgentLock::getCurrentMode() != mace::AgentLock::WRITE_MODE */){
        ABORT("must be protected by process-wide AgentLock or head-node write lock!" );
      }
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
        const mace::MaceAddr& headAddr = getHead();
        ASSERTMSG( headAddr != SockUtil::NULL_MACEADDR, "Head node address is NULL_MACEADDR!" );
        std::pair<bool, uint32_t> newNode = updateMapping( headAddr, contextID );
        return std::pair< mace::MaceAddr, uint32_t>(headAddr, newNode.second);
      }

      // find parent context id
      mace::string parent = getParentContextID( contextID );
      // chuangw: this helper method is called before a new snapshot is created. 
      // it should use the old snapshot to find out the parent context mapping.
      //
      // chuangw: use the latest version of mapping
      const mace::MaceAddr& parentAddr = getNodeByContext(*this, parent);
      ASSERTMSG( parentAddr != SockUtil::NULL_MACEADDR, "Parent node address is NULL_MACEADDR!" );
      std::pair<bool, uint32_t> newNode = updateMapping( parentAddr, contextID );
      return std::pair< mace::MaceAddr, uint32_t>(parentAddr, newNode.second);

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
    }

    static mace::map < MaceAddr , mace::list < mace::string > >&getInitialMapping (const mace::string & serviceName)
    {
      return initialMapping[serviceName];
    }
    static const mace::string& getNameByID( const mace::ContextMapping& snapshotMapping, const uint32_t contextID ){
      ContextMapType::const_iterator it = snapshotMapping.mapping.find( contextID );
      ASSERT( it != snapshotMapping.mapping.end() );
      return it->second.name;
    }
    const uint32_t findIDByName( const mace::string& contextName ) const {
      mace::hash_map< mace::string, uint32_t >::const_iterator mit = nameIDMap.find( contextName );
      ASSERT( mit != nameIDMap.end() );
      return mit->second;
    }
    const uint32_t getParentContextID( const uint32_t contextID ) const{
      ContextMapType::const_iterator it = mapping.find( contextID );
      ASSERT( it != mapping.end() );

      // XXX: global context does not have parent
      
      return it->second.parent;
    }
  private:
    mace::string getParentContextID( const mace::string& contextID )const {
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
        const mace::string parentName = getParentContextID( contextName );
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
      if ( !(  versionMap.empty() || versionMap.back().first < ver ) ){
        maceerr<< "versionMap.empty() = " << versionMap.empty() << "\n";
        maceerr<< "versionMap.back().first = " << versionMap.back().first << ", ver = " << ver << "\n";
        for( VersionContextMap::iterator vit = versionMap.begin(); vit != versionMap.end(); vit ++ ){
          maceerr<< "version: " << vit->first << ", snapshot = " << *( vit->second ) << "\n";
        }
        maceerr<< Log::endl;

        ASSERT( versionMap.empty() || versionMap.back().first < ver );
      }
      ScopedLock sl (alock);
      versionMap.push_back( std::make_pair(ver, _ctx) );
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
    const mace::map < MaceAddr, uint32_t >& _getAllNodes () const
    {
      return nodes;
    }


protected:
    typedef std::deque<std::pair<uint64_t, const mace::ContextMapping* > > VersionContextMap;
    mutable VersionContextMap versionMap;

  private:
    typedef mace::hash_map < uint32_t,  ContextMapEntry> ContextMapType;

    mace::map<mace::string, mace::MaceAddr > defaultMapping; ///< User defined mapping. This should only be accessed by head node. Therefore it is not serialized


    ContextMapType mapping; ///< The mapping between contexts to physical node address
    mace::map < mace::MaceAddr, uint32_t > nodes; ///< maintain a counter of contexts on this node. When it decrements to zero, remove the node from node set.
    uint32_t nContexts; ///< number of total contexts currently

    mace::hash_map< mace::string, uint32_t > nameIDMap;

    ///<------ static members
    static const mace::string headContext;
    static pthread_mutex_t alock; ///< This mutex is used to protect static variables -- considering to drop it because process-wide sharing should use AgentLock instead.
    static mace::MaceAddr head;
    static std::map < uint32_t, MaceAddr > virtualNodes;
    static mace::MaceKey vnodeMaceKey; ///< The local logical node MaceKey
    static mace::map < mace::string, mace::map < MaceAddr, mace::list < mace::string > > >initialMapping;
  };

}

#endif // CONTEXTMAPPING_H
