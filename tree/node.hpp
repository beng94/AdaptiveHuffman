#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

#include "../data/data.hpp"

class Node {
    private:
        Data data;
        Node* parent;
        Node* left_child;
        Node* right_child;

        bool isLeftChild(Node*);

    public:
        Node();
        Node(Node*, Data);

        Data& getData();
        Node* getParent();
        Node* getLeftChild();
        Node* getRightChild();
        void setLeftChild(Node*);
        void setRightChild(Node*);
        void swap(Node*);
};

#endif
