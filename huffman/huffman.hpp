#include "../tree/binary_tree.hpp"

class Huffman {

    public:

    private:
        BinaryTree codeTree;
        Node* nytNode;

        Node* findSymbol(char);
        Node* findBlockLeader(int);
        void swapNodes(Node*, Node*);
        void incrementNode(Node*);
        void symbolReceived(char);
};
