#include "../tree/binary_tree.hpp"

class Huffman {

    public:

    protected:
        BinaryTree codeTree;

        Node* symbolReceived(char);

    private:
        Node* findSymbol(char);
        Node* findBlockLeader(int);
        void swapNodes(Node*, Node*);
        void incrementNode(Node*);
        Node* getNytNode();
        Node* insertNewNode(char);
};
