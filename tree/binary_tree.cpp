#include "binary_tree.hpp"


Node* BinaryTree::blockLeader() {

}

void BinaryTree::traverseTree(std::function<void(Node*)> func) {
    traverseHelper(root, func);
}

void BinaryTree::traverseHelper(Node* root, std::function<void(Node*)> func) {
    // Root can be an empty node, func has to handle this
    func(root);

    Node* leftChild = root->getLeftChild();
    Node* rightChild = root->getRightChild();
    if(leftChild) {
        traverseHelper(leftChild, func);
    }
    if(rightChild) {
        traverseHelper(rightChild, func);
    }
}
