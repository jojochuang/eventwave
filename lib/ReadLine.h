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
      const mace::string& contextID;
    public:
      TreeNode( const mace::string& id ): prev(NULL), next(NULL),childlist(NULL), contextID( id ) { 
      
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
      TreeNode head(""); // head points to the read-line cut set
      prev = &head;
      //const mace::map<mace::string, mace::string> & eventSnapshotContexts = ThreadStructure::getCurrentServiceEventSnapshotContexts( );
      for( mace::map<mace::string, mace::string>::const_iterator ctxIt = eventSnapshotContexts.begin(); ctxIt != eventSnapshotContexts.end(); ctxIt++ ){
      
        recursivelyAddReadyOnlyContext( ctxIt->first );
      }
      for( mace::set<mace::string>::const_iterator ctxIt = eventContexts.begin(); ctxIt != eventContexts.end(); ctxIt++ ){
        appendCandidateList( *ctxIt);
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
    const mace::list< mace::string >& getCut(){
      return cutSet;
    }

    ~ReadLine(){

      // (4) cleanup
      for( std::map<mace::string const*, TreeNode* >::iterator ctxIt = ctxNodes.begin(); ctxIt != ctxNodes.end(); ctxIt ++ ){
        delete ctxIt->second;
      }
    }
private:
  // for a context that we have snapshot, it's already committed, so don't need to commit it.
  // but the event still need to enter its child contexts to commit them.
    void recursivelyAddReadyOnlyContext(const mace::string& contextID){
        std::queue< mace::string const* > contextNames;
        contextNames.push( &contextID );

        while( !contextNames.empty()){
          mace::string const* targetContextName = contextNames.front();
          contextNames.pop();
          const mace::set<mace::string>& childnodes = mace::ContextMapping::getChildContexts( contextMapping, *targetContextName );
          
          for( mace::set<mace::string>::const_iterator cnIt = childnodes.begin(); cnIt != childnodes.end(); cnIt ++ ){
            if( eventSnapshotContexts.count( *cnIt ) == 1 ){
              contextNames.push( &(*cnIt) );
            }else{
              appendCandidateList( *cnIt );
            }
          }

        }

    }
    void appendCandidateList( const mace::string& contextID){
        if( ctxNodes.count(  &contextID ) == 0 ){ // entry did not exist before
          TreeNode *node = new TreeNode( contextID ); // push_front() operation
          prev->next = node;
          node->prev = prev;
          node->next = NULL;
          ctxNodes.insert( std::make_pair<mace::string const*, TreeNode*>( &contextID, node ) ); // map context id to the node address
          prev = node;
        }
    }
    void unionContexts(const TreeNode& head){
      TreeNode *node = head.next;
      while( node != NULL ){
        if( node->contextID.empty() ){ 
          node = node->next;
          continue; 
        }// if it's not global context
        
        mace::string parentContextName = node->contextID; // make a string copy.

        TreeNode *next = node->next;
        while( getParentContextName( parentContextName ) ){
          std::map<std::string const*, TreeNode* >::iterator ancestor = ctxNodes.find( &(parentContextName) );
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
    bool getParentContextName( mace::string& contextName ){
        if( contextName.empty() ){ return false; } // global context ID does not have parent

        size_t lastDelimiter = contextName.find_last_of("." );
        if( lastDelimiter == mace::string::npos ){
          contextName.erase();
        }else{
          contextName.resize( lastDelimiter );
        }

        return true;
    }
    std::map<mace::string const*, TreeNode*, StringPtrComp > ctxNodes;
    TreeNode* prev;
    mace::list< mace::string > cutSet;
    const mace::map<mace::string, mace::string> & eventSnapshotContexts;
    const mace::ContextMapping& contextMapping;
};

}
#endif
