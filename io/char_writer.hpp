#include <fstream>

class CharWriter {
    public:
        CharWriter(std::string);
        ~CharWriter();
        void write(char);
        void finish();

    private:
        std::ofstream file;
};
