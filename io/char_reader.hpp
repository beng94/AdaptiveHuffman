#include <string>
#include <fstream>

class CharReader {
    public:
        CharReader(std::string);
        ~CharReader();
        char read();

    private:
        std::ifstream file;
};
