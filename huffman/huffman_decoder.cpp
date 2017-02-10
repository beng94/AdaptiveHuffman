#include "huffman_decoder.hpp"

#include <iostream>

HuffmanDecoder::HuffmanDecoder(std::string in, std::string out) :
    binaryReader{in}, charWriter{out}
{}

void HuffmanDecoder::decode() {
    while(!binaryReader.end()) {
        Node* node = findNode();

        char c = 0x0;
        if(isNytNode(node)) {
            binaryReader.read(); // Avoid first direction bit
            c = binaryReader.readChar();
        } else {
            c = node->getData().code;
        }

        std::cout << " " << c << " ";
        updateCodeTree(c);
        std::cout << std::endl;
        charWriter.write(c);
    }
}

bool HuffmanDecoder::isNytNode(Node* node) {
    return (node->getData().code == 0x0 &&
            !node->getLeftChild());
}

Node* HuffmanDecoder::findNode() {
    Node* node = codeTree.getRoot();
    while(node->getRightChild()) {
        int bit = binaryReader.read();
        if(bit == 0) {
            node = node->getLeftChild();
        } else {
            node = node->getRightChild();
        }
    }

    return node;
}

void HuffmanDecoder::updateCodeTree(char c) {
    symbolReceived(c);
}
