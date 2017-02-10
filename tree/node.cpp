#include "node.hpp"

Node::Node() :
    parent{nullptr}, left_child{nullptr}, right_child{nullptr}
{}

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

    if(node->parent->left_child == node) {
        node->parent->left_child = this;
    } else {
        node->parent->right_child = this;
    }

    Node* tmpParent = parent;
    parent = node->parent;
    node->parent = tmpParent;
}

Data& Node::getData() {
    return data;
}

void Node::setLeftChild(Node* node) {
    left_child = node;
}

void Node::setRightChild(Node* node) {
    right_child = node;
}
