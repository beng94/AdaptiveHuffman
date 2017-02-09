#include "huffman.hpp"


Node* Huffman::findSymbol(char c) {
    Node* symbolNode = NULL;
    codeTree.traverseTree([&symbolNode, c](Node* node) {
            if(node->getData().code == c) symbolNode = node;
        }
    );

    return symbolNode;
}

Node* Huffman::findBlockLeader(int weight) {
    Node* leaderNode = nytNode;
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

void Huffman::symbolReceived(char c) {
    Node* symbolNode = findSymbol(c);
    if(!symbolNode) {
        // TODO: insert NYT
    } else {
        incrementNode(symbolNode);
    }
}
