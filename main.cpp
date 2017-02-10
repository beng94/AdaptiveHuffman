#include "huffman/huffman_encoder.hpp"
#include "huffman/huffman_decoder.hpp"

#include <iostream>

int main() {
    HuffmanEncoder encoder("test.txt", "encoded.txt");
    encoder.encode(); // TODO: It should return a string

    HuffmanDecoder decoder("encoded.txt", "decoded.txt");
    decoder.decode();
}
