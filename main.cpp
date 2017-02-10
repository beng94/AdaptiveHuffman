#include "huffman/huffman_encoder.hpp"
#include "io/input_reader.hpp"

#include <iostream>

int main() {
    HuffmanEncoder encoder("test.txt", "out.txt");
    encoder.encode(); // TODO: It should return a string

    InputReader i("out.txt");
    while(!i.end()) {
        std::cout << i.nextBit();
    }
}
