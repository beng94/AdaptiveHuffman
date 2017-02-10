#include "binary_writer.hpp"

#include <iostream>

BinaryWriter::BinaryWriter(std::string fileName) :
    file{fileName}, cnt{7}, currentChar{0x0}
{}

BinaryWriter::~BinaryWriter() {
    end();
    file.close();
}

void BinaryWriter::write(int bit) {
    currentChar |= (bit << cnt);
    cnt--;

    if(cnt < 0) {
        file.put(currentChar);
        cnt = 7;
        currentChar = 0x0;
    }
}

void BinaryWriter::end() {
    file.put(currentChar);
}
