#include "huffman.hpp"
#include "../io/char_reader.hpp"

#include <string>
#include <fstream>
#include <list>

class HuffmanEncoder : public Huffman {
    public:
        HuffmanEncoder(std::string, std::string);
        void encode();

    private:
        CharReader inputReader;
        std::ofstream outputFile;

        std::list<int> findRootPath(Node*);
        void writeCode(const std::list<int>&);
        void appendCharToCode(std::list<int>&, char);

};
