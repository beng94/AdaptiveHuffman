#ifndef HUFFMAN_DATA_H
#define HUFFMAN_DATA_H

class Data {
    public:
        int order;
        int weight;
        char code;

        Data();
        Data(int, char);
};

#endif
