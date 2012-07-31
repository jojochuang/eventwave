#ifndef READLINE_H
#define READLINE_H

#include "ThreadStructure.h"
#include "mset.h"
#include "mstring.h"

namespace mace
{

  class ReadLine{
private:
  class TreeNode{
    public:
      Node *prev;
      Node *next;
      Node *childlist;
      mace::string contextID;
    public:
      TreeNode( const mace::string& id ): contextID( id ) { 
      
      }
      void addChild( TreeNode* child ){
        if( childlist == NULL ){
          childlist = child;
        }else{
          
        }
      }
  };
  class TreeNodeList{
    TreeNode *begin;
    TreeNode *end;
    TreeNodeList(): begin(NULL), end(NULL) {
      
    }
    void append(){
      if( begin == NULL ){
        begin = end = new ThreeNode();
      }else{
        end->next = new TreeNode();
        end = end->next;
      }
    }
  };
public:
    ReadLine(){
      const mace::map<uint8_t, mace::set<mace::string> >& eventContexts = ThreadStructure::getEventContexts( );
      const mace::set<mace::string>& eventServiceContexts = eventContexts[ ThreadStructure::getServiceInstance() ];
      // TODO: find the cut of the read line.
      //
      // algorithm: 
      // (1) Initially, create n tree nodes
      TreeNode head;
      TreeNode* prev = &head;
      std::map<std::string, TreeNode* > ctxNodes;
      for( mace::set<mace::string>::const_iterator ctxIt = eventServiceContexts.begin(); ctxIt != eventServiceContexts.end(); ctxIt++ ){
        TreeNode *node = new TreeNode( *ctxIt ); // push_front() operation
        prev->next = node;
        node->prev = prev;
        node->next = NULL;
        ctxNodes.insert( make_pair<std::string, TreeNode*>( *ctxIt, node ) );
        prev = node;
      }
      // (2) For each tree node, if its parent is in the set(trivial to find using set::find() ), create the link between parent and that node
      TreeNode *node = head->next;
      while( node != NULL ){
        if( node->contextID == "" ){ continue; }// if it's not global context

        const mace::string parentContextID = ""; // TODO: 
        std::map<std::string, TreeNode* >::iterator parent = ctxNodes.find( parentContextID );
        if( parent != eventServiceContexts.end() ){
          TreeNode* parentNode = parent->second;
          // adjust linkage
          node->prev->next = node->next;
          node->next->prev = node->prev;

          parentNode->addChild( node );
        }
      }

      TreeNode *node = head->next;
      while( node != NULL ){
        cutSet.insert( node->contextID );
      }

      // (3) cleanup
      for( std::map<std::string, TreeNode* >::iterator ctxIt = ctxNodes.begin(); ctxIt != ctxNodes.end(); ctxIt ++ ){
        delete ctxIt->second;
      }

      
      //
      // So it's a O( n* log n ) algorithm
    }
    const mace::set< mace::string >& getCut(){
      return cutSet;
    }
private:
    mace::set< mace::string > cutSet;
  };
}
#endif
