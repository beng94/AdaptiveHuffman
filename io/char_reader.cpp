#include "char_reader.hpp"

CharReader::CharReader(std::string fileName) :
    file{fileName}
{}

CharReader::~CharReader() {
    file.close();
}


char CharReader::read() {
    char c;
    file.get(c);

    return c;
}
