#include "huffman/huffman_encoder.hpp"

#include <iostream>

int main() {
    HuffmanEncoder encoder("test.txt", "out.txt");
    encoder.encode(); // TODO: It should return a string
}
