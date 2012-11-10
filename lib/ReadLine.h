#ifndef READLINE_H
#define READLINE_H

#include "ThreadStructure.h"
#include "ContextMapping.h"
#include "mset.h"
#include "mstring.h"
#include <utility>

namespace mace
{
/**
 * ReadLine class implements the concept of access permission in FullContext model 
 *
 * */
class ReadLine{
private:
  struct StringPtrComp {
    bool operator()( const mace::string* const & ptr1, const mace::string* const& ptr2 ) const{
      return ptr1->compare( *ptr2 );
    }
  };
  class TreeNode{
    public:
      TreeNode *prev;
      TreeNode *next;
      TreeNode *childlist;
      //const mace::string& contextID;
      uint32_t contextID;
    public:
      //TreeNode( const mace::string& id ): prev(NULL), next(NULL),childlist(NULL), contextID( id ) { 
      TreeNode( const uint32_t id ): prev(NULL), next(NULL),childlist(NULL), contextID( id ) { 
      
      }
      void addChild( TreeNode* child ){ 
        child->prev = NULL;
        child->next = childlist;
        childlist = child;
      }
  };
public:
    ReadLine( const mace::ContextMapping& contextMapping):
      eventSnapshotContexts ( ThreadStructure::getCurrentServiceEventSnapshotContexts( ) ),
      contextMapping( contextMapping.getSnapshot() ) {
      const mace::set<mace::string> & eventContexts = ThreadStructure::getCurrentServiceEventContexts( );
      // find the cut of the read line.
      // algorithm: 
      // (1) Initially, create a list of n tree nodes: that is, assuming all of them are in the cut set.
      TreeNode head( 0 ); // head points to the read-line cut set
      prev = &head;
      //const mace::map<mace::string, mace::string> & eventSnapshotContexts = ThreadStructure::getCurrentServiceEventSnapshotContexts( );
      for( mace::map<mace::string, mace::string>::const_iterator ctxIt = eventSnapshotContexts.begin(); ctxIt != eventSnapshotContexts.end(); ctxIt++ ){
      
        recursivelyAddReadyOnlyContext( ctxIt->first );
      }
      for( mace::set<mace::string>::const_iterator ctxIt = eventContexts.begin(); ctxIt != eventContexts.end(); ctxIt++ ){
        const uint32_t contextID = contextMapping.findIDByName( *ctxIt );
        appendCandidateList( contextID);
      }
      // (2) For each tree node, if its parent is in the set(trivial to find using set::find() ), create the link between parent and that node
      unionContexts(head );

      // (3) Finally, the remaining nodes are the root of the subtrees, and they are the read-line cut.


      // FIXME: chuangw: string copy is stupid
      TreeNode *node = head.next;
      node = head.next;
      while( node != NULL ){
        cutSet.push_back( node->contextID );
        node = node->next;
      }
      
      //
      // So it's an O( n* log n ) algorithm (assuming map insertion is O(log n) )
    }
    const mace::list< uint32_t >& getCut(){
      return cutSet;
    }

    ~ReadLine(){

      // (4) cleanup
      for( mace::hash_map< uint32_t, TreeNode*, mace::SoftState >::iterator ctxIt = ctxNodes.begin(); ctxIt != ctxNodes.end(); ctxIt ++ ){
        delete ctxIt->second;
      }
    }
private:
  // for a context that we have snapshot, it's already committed, so don't need to commit it.
  // but the event still need to enter its child contexts to commit them.
    void recursivelyAddReadyOnlyContext(const mace::string& contextName ){
        //std::queue< mace::string const* > contextNames;
        std::queue< uint32_t > contextIDs;
        const uint32_t contextID = contextMapping.findIDByName( contextName );
        contextIDs.push( contextID );

        while( !contextIDs.empty()){
          //mace::string const* targetContextName = contextIDs.front();
          const uint32_t targetContextID = contextIDs.front();
          contextIDs.pop();
          //const mace::set<mace::string>& childnodes = mace::ContextMapping::getChildContexts( contextMapping, *targetContextName );
          const mace::set< uint32_t >& childnodes = contextMapping.getChildContexts( targetContextID );
          
          for( mace::set< uint32_t >::const_iterator cnIt = childnodes.begin(); cnIt != childnodes.end(); cnIt ++ ){
            const mace::string& contextName = mace::ContextMapping::getNameByID( contextMapping, contextID );
            if( eventSnapshotContexts.count( contextName ) == 1 ){
              // if the child is also a snapshot context, we need to look deeper
              contextIDs.push( *cnIt );
            }else{
              appendCandidateList( *cnIt );
            }
          }

        }

    }
    void appendCandidateList( const uint32_t contextID){
        if( ctxNodes.count(  contextID ) == 0 ){ // entry did not exist before
          TreeNode *node = new TreeNode( contextID ); // push_front() operation
          prev->next = node;
          node->prev = prev;
          node->next = NULL;
          //ctxNodes.insert( std::make_pair<mace::string const*, TreeNode*>( &contextID, node ) ); // map context id to the node address
          ctxNodes[ contextID ] = node ; // map context id to the node address
          prev = node;
        }
    }
    void unionContexts(const TreeNode& head){
      TreeNode *node = head.next;
      while( node != NULL ){
        //if( node->contextID.empty() ){ 
        if( node->contextID == 0 ){ 
          node = node->next;
          continue; 
        }// if it's not global context
        
        //mace::string parentContextName = node->contextID; // make a string copy.
        uint32_t parentContextID = node->contextID;

        TreeNode *next = node->next;
        while( (parentContextID = getParentContextID( parentContextID ) ) != 0 /*getParentContextName( parentContextName )*/ ){
          //std::map<std::string const*, TreeNode* >::iterator ancestor = ctxNodes.find( &(parentContextName) );
          mace::hash_map< uint32_t, TreeNode*, mace::SoftState >::iterator ancestor = ctxNodes.find( parentContextID );
          if( ancestor != ctxNodes.end() ){ // if its ancestor is in the list
            TreeNode* ancestorNode = ancestor->second;
            // adjust linkage: remove the node from the list
            node->prev->next = node->next;
            if( node->next != NULL ){
              node->next->prev = node->prev;
            }

            ancestorNode->addChild( node );
            break;
          }
        }
        node = next;

      }
    }
    uint32_t getParentContextID( const uint32_t contextID ) const{
      if( contextID == 1 ) { return 0; } // global context does not have parent

      return contextMapping.getParentContextID( contextID );
    }

    /*bool getParentContextName( mace::string& contextName ){
        if( contextName.empty() ){ return false; } // global context ID does not have parent

        size_t lastDelimiter = contextName.find_last_of("." );
        if( lastDelimiter == mace::string::npos ){
          contextName.erase();
        }else{
          contextName.resize( lastDelimiter );
        }

        return true;
    }*/
    //std::map<mace::string const*, TreeNode*, StringPtrComp > ctxNodes;
    mace::hash_map< uint32_t, TreeNode*, mace::SoftState> ctxNodes;
    TreeNode* prev;
    mace::list< uint32_t > cutSet;
    //mace::list< mace::string > cutSet;
    const mace::map<mace::string, mace::string> & eventSnapshotContexts;
    const mace::ContextMapping& contextMapping;
};

}
#endif
