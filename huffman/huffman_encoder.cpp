#include "huffman_encoder.hpp"


HuffmanEncoder::HuffmanEncoder(std::string in, std::string out) :
    inputReader{in}, outputFile{out, std::ios::binary | std::ios::out}
{}

void HuffmanEncoder::encode() {
    char c;
    while((c = inputReader.read()) != EOF) {
        Node* node = symbolReceived(c);
        std::list<int> huffmanCode = findRootPath(node);

        // This node got created recently
        if(node->getData().weight == 1) {
            appendCharToCode(huffmanCode, c);
        }

        writeCode(huffmanCode);
    }

    // TODO: outBinaryWriter.end
}

std::list<int> HuffmanEncoder::findRootPath(Node* node) {
    std::list<int> path;
    while(node->getParent()) {
        if(node->getParent()->getLeftChild() == node) {
            path.push_front(0);
        } else {
            path.push_front(1);
        }

        node = node->getParent();
    }

    return path;
}

void HuffmanEncoder::writeCode(const std::list<int>& code) {
    for(int c: code) {

    }
}

void HuffmanEncoder::appendCharToCode(std::list<int>& code, char c) {
    for(int i = 7; i >= 0; i--) {
        int bit = (c >> i) & 1;
        code.push_back(bit);
    }
}
