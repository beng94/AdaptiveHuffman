#include "node.hpp"

#include <functional>

class BinaryTree {

    public:
        Node* blockLeader();
        void traverseTree(std::function<void(Node*)>);

    private:
        Node* root;

        void traverseHelper(Node*, std::function<void(Node*)>);
};
