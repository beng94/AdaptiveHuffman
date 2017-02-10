#include "huffman_decoder.hpp"

HuffmanDecoder::HuffmanDecoder(std::string in, std::string out) :
    binaryReader{in}, charWriter{out}
{}

void HuffmanDecoder::decode() {
    while(!binaryReader.end()) {
        int bit = binaryReader.read();
    }
}
