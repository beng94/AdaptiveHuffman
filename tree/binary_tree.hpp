#include "node.hpp"

#include <functional>

class BinaryTree {

    public:
        BinaryTree();

        void traverseTree(std::function<void(Node*)>);
        Node* getRoot();

    private:
        Node* root;

        void traverseHelper(Node*, std::function<void(Node*)>);
};
