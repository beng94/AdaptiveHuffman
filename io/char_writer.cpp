#include "char_writer.hpp"

CharWriter::CharWriter(std::string file) :
    file{file}
{}

CharWriter::~CharWriter() {
    finish();
}

void CharWriter::write(char c) {
    file.put(c);
}

void CharWriter::finish() {
    file.close();
}
