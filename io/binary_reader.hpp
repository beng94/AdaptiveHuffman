#include <string>
#include <fstream>

class BinaryReader {
	public:
		BinaryReader(std::string);
        ~BinaryReader();
		bool end();
		int read();
        char readChar();

    private:
        std::ifstream file;
        int bitIndex;
        char currentChar;

        void readNextChar();
};
