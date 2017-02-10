#ifndef HUFFMAN_HUFFMAN_DECODER_H
#define HUFFMAN_HUFFMAN_DECODER_H

#include "huffman.hpp"
#include "../io/char_writer.hpp"
#include "../io/binary_reader.hpp"

class HuffmanDecoder : public Huffman {

    public:
        HuffmanDecoder(std::string, std::string);
        void decode();

    private:
        BinaryReader binaryReader;
        CharWriter charWriter;

        bool isNytNode(Node*);
        Node* findNode();
};

#endif
