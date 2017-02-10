#include "binary_reader.hpp"

#include <iostream>

BinaryReader::BinaryReader(std::string fileName) :
    file{fileName, std::ios::binary | std::ios::in}, bitIndex{7} {
        file.get(currentChar);
    }

BinaryReader::~BinaryReader() {
    file.close();
}

/* Returns whether BinaryReader got to the end of the file. */
bool BinaryReader::end() {
    return file.eof();
}

void BinaryReader::readNextChar() {
    bitIndex = 7;
    file.get(currentChar);
}

/* Returns 0 or 1 according to the next bit in the file. */
int BinaryReader::read() {
    int bit = (currentChar >> bitIndex) & 1;
    std::cout << bit;
    bitIndex--;

    if(bitIndex < 0) {
        readNextChar();
    }

    return bit;
}


char BinaryReader::readChar() {
    char c = 0x0;
    for(int i = 7; i >= 0; i--) {
        int bit = read();
        c |= (bit << i);
    }

    return c;
}
