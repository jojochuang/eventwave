#ifndef __MERKLE_TREE_H__
#define __MERKLE_TREE_H__

#include <vector>
#include <inttypes.h>

namespace macemc {

    /* MerkleNode - Represents a node in a MerkleTree. */
    class MerkleNode {
        private:
            MerkleNode *left;
            MerkleNode *right;
            uint32_t hash;
            uint32_t level;

        public:
            MerkleNode();
            MerkleNode(uint32_t level);
            MerkleNode(uint32_t level, uint32_t hash);
            ~MerkleNode();

            bool has_left();
            bool has_right();
            bool has_both();
            MerkleNode *get_left();
            MerkleNode *get_right();
            uint32_t get_hash();
            uint32_t get_level();

            void set_left(MerkleNode *left);
            void set_right(MerkleNode *right);
            void set_both(MerkleNode *left, MerkleNode *right);
    };
    /* End MerkleNode */



    /* MerkleTree - Represents a hash tree in which a node's hash is the hash
     * of its concatenated children. */
    class MerkleTree {
        private:
            MerkleNode *root;

        public:
            MerkleTree(std::vector<unsigned> states);
            ~MerkleTree();
            
            uint32_t hash_node(MerkleNode *node);
    };
    /* End MerkleTree */

}  /* namespace macemc */

#endif  /* __MERKLE_TREE_H__ */
