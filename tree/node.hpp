#include "../data/data.hpp"


class Node {
    private:
        Node* left_child;
        Node* right_child;

    public:
        Node* getLeftChild();
        Node* getRightChild();
};
