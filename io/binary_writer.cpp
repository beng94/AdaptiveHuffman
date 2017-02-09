#include "binary_writer.hpp"

BinaryWriter::BinaryWriter(std::string fileName) :
    file{fileName}, cnt{7}
{}

BinaryWriter::~BinaryWriter() {
    end();
    file.close();
}

void BinaryWriter::write(int bit) {
    currentChar |= (1 << cnt);
    cnt--;

    if(cnt < 0) {
        cnt = 7;
    }
}

void BinaryWriter::end() {
    file.put(currentChar);
}
