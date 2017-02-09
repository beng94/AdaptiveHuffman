#include "../data/data.hpp"

class Node {
    private:
        Data data;
        Node* parent;
        Node* left_child;
        Node* right_child;

        bool isLeftChild(Node*);

    public:
        Data& getData();
        Node* getParent();
        Node* getLeftChild();
        Node* getRightChild();
        void swap(Node*);
};
