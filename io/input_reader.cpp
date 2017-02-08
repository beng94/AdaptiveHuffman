#include "input_reader.hpp"

InputReader::InputReader(std::string fileName) :
    file{fileName, std::ios::binary | std::ios::in}, bitIndex{7} {
        file.get(currentChar);
    }

InputReader::~InputReader() {
    file.close();
}

/* Returns whether InputReader got to the end of the file. */
bool InputReader::end() {
    return file.eof();
}

void InputReader::readNextChar() {
    bitIndex = 7;
    file.get(currentChar);
}

/* Returns 0 or 1 according to the next bit in the file. */
int InputReader::nextBit() {
    int bit = (currentChar >> bitIndex) & 1;
    bitIndex--;

    if(bitIndex < 0) {
        readNextChar();
    }

    return bit;
}
