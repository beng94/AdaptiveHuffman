#include <string>
#include <fstream>

class InputReader {
	public:
		InputReader(std::string);
        ~InputReader();
		bool end();
		int nextBit();

    private:
        std::ifstream file;
        int bitIndex;
        char currentChar;

        void readNextChar();
};
