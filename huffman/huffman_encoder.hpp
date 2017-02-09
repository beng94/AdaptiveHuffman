#include "huffman.hpp"
#include "../io/char_reader.hpp"
#include "../io/binary_writer.hpp"

#include <string>
#include <fstream>
#include <list>

class HuffmanEncoder : public Huffman {
    public:
        HuffmanEncoder(std::string, std::string);
        void encode();

    private:
        CharReader inputReader;
        BinaryWriter binaryWriter;

        std::list<int> findRootPath(Node*);
        void writeCode(const std::list<int>&);
        void appendCharToCode(std::list<int>&, char);

};
