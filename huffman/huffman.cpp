#include "huffman.hpp"

#include <iostream>

Huffman::Huffman() :
    codeTree{}
{}

Node* Huffman::findSymbol(char c) {
    Node* symbolNode = NULL;
    codeTree.traverseTree([&symbolNode, c](Node* node) {
            if(node->getData().code == c) symbolNode = node;
        }
    );

    return symbolNode;
}

Node* Huffman::findBlockLeader(int weight) {
    Node* leaderNode = getNytNode();
    codeTree.traverseTree([&leaderNode, weight](Node* node) {
            Data data = node->getData();
            if((data.weight == weight) &&
               (data.order > leaderNode->getData().order)) {
                leaderNode = node;
            }
        }
    );
    return leaderNode;
}


void Huffman::swapNodes(Node* a, Node* b) {
    Data& dataA = a->getData();
    Data& dataB = b->getData();

    std::cout << "swap: " << dataA.order << ": '" << dataA.code << "' " << dataA.weight << " ";
    std::cout << dataB.order << ": '" << dataB.code << "' " << dataB.weight << " ";

    int tmpOrder = dataA.order;
    dataA.order = dataB.order;
    dataB.order = tmpOrder;

    a->swap(b);
}

void Huffman::incrementNode(Node* node) {
    Node* leaderNode = findBlockLeader(node->getData().weight);
    if(leaderNode != node && node->getParent() != leaderNode) {
        swapNodes(node, leaderNode);
    }
    node->getData().weight++;

    Node* parent = node->getParent();
    if(parent) {
        incrementNode(parent);
    }
}

Node* Huffman::getNytNode() {
    Node* nytNode = codeTree.getRoot();
    codeTree.traverseTree([&nytNode](Node* node) {
            if(node->getData().code == 0x0 &&
               node->getLeftChild() == nullptr) {
                nytNode = node;
            }
        }
    );

    return nytNode;
}

Node* Huffman::insertNewNode(char c) {
    Node* nytNode = getNytNode();

    Data nytData(nytNode->getData().order - 2, 0x0);
    Node* newNytNode = new Node(nytNode, nytData);
    nytNode->setLeftChild(newNytNode);

    Data data(nytNode->getData().order - 1, c);
    Node* newSymbolNode = new Node(nytNode, data);
    nytNode->setRightChild(newSymbolNode);

    return newSymbolNode;
}

Node* Huffman::symbolReceived(char c) {
    Node* symbolNode = findSymbol(c);
    if(!symbolNode) {
        symbolNode = insertNewNode(c);
    }

    incrementNode(symbolNode);

    return symbolNode;
}
