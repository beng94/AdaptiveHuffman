#ifndef HUFFMAN_BINARY_TREE_H
#define HUFFMAN_BINARY_TREE_H

#include "node.hpp"

#include <functional>

class BinaryTree {

    public:
        BinaryTree();

        void traverseTree(std::function<void(Node*)>);
        Node* getRoot();

    private:
        Node* root;

        void traverseHelper(Node*, std::function<void(Node*)>);
};

#endif
