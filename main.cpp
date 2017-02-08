#include "io/input_reader.hpp"

#include <iostream>

int main() {
    InputReader in("test.txt");
    while(!in.end()) {
        std::cout << in.nextBit();
    }
    std::cout << std::endl;
}
