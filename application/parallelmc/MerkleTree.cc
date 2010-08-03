#include <algorithm>
#include <stack>
#include "MerkleTree.h"

using namespace macemc;

/* MerkleNode */
MerkleNode::MerkleNode() {
    this->left = NULL;
    this->right = NULL;
    this->hash = 0;
    this->level = 0;
}

MerkleNode::MerkleNode(uint32_t level) {
    this->left = NULL;
    this->right = NULL;
    this->hash = 0;
    this->level = level;
}

MerkleNode::MerkleNode(uint32_t level, uint32_t hash) {
    this->left = NULL;
    this->right = NULL;
    this->hash = hash;
    this->level = level;
}

MerkleNode::~MerkleNode() {
    if (this->left != NULL) {
        delete this->left;
    }

    if (this->right != NULL) {
        delete this->right;
    }

    /* Clear memory - for the paranoid. :) */
    hash = 0;
    level = 0;
}

bool MerkleNode::has_left() {
    return (left != NULL);
}

bool MerkleNode::has_right() {
    return (right != NULL);
}

bool MerkleNode::has_both() {
    return ((left != NULL) && (right != NULL));
}

MerkleNode *MerkleNode::get_left() {
    return left;
}

MerkleNode *MerkleNode::get_right() {
    return right;
}

uint32_t MerkleNode::get_hash() {
    return hash;
}

uint32_t MerkleNode::get_level() {
    return level;
}

void MerkleNode::set_left(MerkleNode *left) {
    this->left = left;
}

void MerkleNode::set_right(MerkleNode *right) {
    this->right = right;
}

void MerkleNode::set_both(MerkleNode *left, MerkleNode *right) {
    this->left = left;
    this->right = right;
}
/* End MerkleNode */



/* MerkleTree */

static MerkleNode *NULLNODE = new MerkleNode(0, 0);

MerkleTree::MerkleTree(std::vector<unsigned> states) {
    std::stack<MerkleNode *> state_stack;
    int states_remaining = states.size();
    int current_state = 0;
    
    this->root = NULL;
    std::sort(states.begin(), states.end());

    while (this->root == NULL) {
        MerkleNode *new_node = NULL;
        /* Grab the next state from the vector, if there is one. Otherwise,
         * use the NULLNODE as padding to construct the rest of the tree. */
        if (states_remaining > 0) {
            new_node = new MerkleNode(0);
            //FIXME: Set hash from states[current_state]
            current_state += 1;
            states_remaining -= 1;
        } else {
            new_node = NULLNODE;
        }

        state_stack.push(new_node);
        
        while (state_stack.size() > 1) {
            MerkleNode *stack_first = NULL;
            MerkleNode *stack_second = NULL;

            stack_first = state_stack.top();
            state_stack.pop();
            stack_second = state_stack.top();

            if (stack_first->get_level() == stack_second->get_level()) {
                MerkleNode *new_parent = new MerkleNode(stack_first->get_level() + 1);

                state_stack.pop();

                //FIXME: set hash on new_parent
                new_parent->set_both(stack_second, stack_first);

                state_stack.push(new_parent);
            } else {
                state_stack.push(stack_first);
                break;
            }
        }

        if (states_remaining == 0 && state_stack.size() == 1) {
            this->root = state_stack.top();
            state_stack.pop();
        }
    }
}

MerkleTree::~MerkleTree() {
    delete root;
}

#define HASH_MAGIC (0xd00dd00d)
uint32_t MerkleTree::hash_node(MerkleNode *node) {
    uint32_t result = node->get_hash();

    if (node->has_left() && node->has_right()) {
        result = node->get_left()->get_hash() ^ node->get_right()->get_hash();
    } else if (node->has_left()) {
        result = node->get_left()->get_hash() ^ HASH_MAGIC;
    } else if (node->has_right()) {
        result = HASH_MAGIC ^ node->get_right()->get_hash();
    }

    return result;
}

/* End MerkleTree */
