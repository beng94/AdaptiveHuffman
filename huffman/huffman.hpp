#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include "../tree/binary_tree.hpp"

class Huffman {

    public:
        Huffman();

    protected:
        BinaryTree codeTree;

        void updateCodeTree(char);
        Node* findSymbolNode(char);
        bool isNytNode(Node*);

    private:
        Node* findSymbol(char);
        Node* findBlockLeader(int);
        void swapNodes(Node*, Node*);
        void incrementNode(Node*);
        Node* getNytNode();
        Node* insertNewNode(char);
};

#endif
