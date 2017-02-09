#include <string>
#include <fstream>

class BinaryWriter {

    public:
        BinaryWriter(std::string);
        ~BinaryWriter();
        void write(int);
        void end();

    private:
        std::ofstream file;
        int cnt;
        char currentChar;
};
