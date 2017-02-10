#include "huffman.hpp"

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
    Node* leaderNode = codeTree.getRoot();
    codeTree.traverseTree([&leaderNode, weight](Node* node) {
            Data data = node->getData();
            if(data.weight == weight &&
               data.order > leaderNode->getData().order) {
                leaderNode = node;
            }
        }
    );
}


void Huffman::swapNodes(Node* a, Node* b) {
    Data& dataA = a->getData();
    Data& dataB = b->getData();

    int tmpOrder = dataA.order;
    dataA.order = dataB.order;
    dataB.order = tmpOrder;
}

void Huffman::incrementNode(Node* node) {
    Node* leaderNode = findBlockLeader(node->getData().weight);
    if(leaderNode != node) {
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
