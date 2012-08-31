#ifndef READLINE_H
#define READLINE_H

#include "ThreadStructure.h"
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
  class TreeNode{
    public:
      TreeNode *prev;
      TreeNode *next;
      TreeNode *childlist;
      mace::string contextID;
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
    ReadLine(){
      const mace::set<mace::string> & eventContexts = ThreadStructure::getCurrentServiceEventContexts( );
      // find the cut of the read line.
      // algorithm: 
      // (1) Initially, create a list of n tree nodes: that is, assuming all of them are in the cut set.
      TreeNode head(""); // head points to the read-line cut set
      TreeNode* prev = &head;
      std::map<std::string, TreeNode* > ctxNodes;
      /*const mace::map<mace::string, mace::string> & eventSnapshotContexts = ThreadStructure::getCurrentServiceEventSnapshotContexts( );
      for( mace::map<mace::string, mace::string>::const_iterator ctxIt = eventSnapshotContexts.begin(); ctxIt != eventSnapshotContexts.end(); ctxIt++ ){
        TreeNode *node = new TreeNode( ctxIt->first ); // push_front() operation
        prev->next = node;
        node->prev = prev;
        node->next = NULL;
        ctxNodes.insert( std::make_pair<std::string, TreeNode*>( ctxIt->first, node ) ); // map context id to the node address
        prev = node;
      }*/
      for( mace::set<mace::string>::const_iterator ctxIt = eventContexts.begin(); ctxIt != eventContexts.end(); ctxIt++ ){
        TreeNode *node = new TreeNode( *ctxIt ); // push_front() operation
        prev->next = node;
        node->prev = prev;
        node->next = NULL;
        ctxNodes.insert( std::make_pair<std::string, TreeNode*>( *ctxIt, node ) ); // map context id to the node address
        prev = node;
      }
      // (2) For each tree node, if its parent is in the set(trivial to find using set::find() ), create the link between parent and that node
      TreeNode *node = head.next;
      while( node != NULL ){
        if( node->contextID == "" ){ 
          node = node->next;
          continue; 
        }// if it's not global context

        const mace::string parentContextID = getParentContextID( node->contextID );
        std::map<std::string, TreeNode* >::iterator parent = ctxNodes.find( parentContextID );
        TreeNode *next = node->next;
        if( parent != ctxNodes.end() ){
          TreeNode* parentNode = parent->second;
          // adjust linkage: remove the node from the list
          node->prev->next = node->next;
          if( node->next != NULL ){
            node->next->prev = node->prev;
          }

          parentNode->addChild( node );
        }
        node = next;
      }

      // (3) Finally, the remaining nodes are the root of the subtrees, and they are the read-line cut.
      node = head.next;
      while( node != NULL ){
        cutSet.insert( node->contextID );
        node = node->next;
      }

      // (4) cleanup
      for( std::map<std::string, TreeNode* >::iterator ctxIt = ctxNodes.begin(); ctxIt != ctxNodes.end(); ctxIt ++ ){
        delete ctxIt->second;
      }
      
      //
      // So it's an O( n* log n ) algorithm (assuming map insertion is O(log n) )
    }
    const mace::set< mace::string >& getCut(){
      return cutSet;
    }
private:
    const mace::string getParentContextID( const mace::string& childContextID ){
        mace::string parent;

        size_t lastDelimiter = childContextID.find_last_of("." );
        if( lastDelimiter == mace::string::npos ){
          parent = ""; // global context
        }else{
          parent = childContextID.substr(0, lastDelimiter );
        }
        return parent;
    }
    mace::set< mace::string > cutSet;
};

}
#endif
