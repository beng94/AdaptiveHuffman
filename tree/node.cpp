#include "node.hpp"

Node::Node(Node* parent, Data data) :
    parent{parent}, left_child{nullptr}, right_child{nullptr}, data{data}
{}

Node* Node::getParent() {
    return parent;
}

Node* Node::getLeftChild() {
    return left_child;
}

Node* Node::getRightChild() {
    return right_child;
}

bool Node::isLeftChild(Node* node) {
    return left_child == node;
}

void Node::swap(Node* node) {
    if(parent->isLeftChild(this)) {
        parent->left_child = node;
    } else {
        parent->right_child = node;
    }

    Node* tmpParent = parent;
    parent = node->parent;
    node->parent = tmpParent;
}

Data& Node::getData() {
    return data;
}
