

class Node {
    private:
        int number;
        int weight;
        char code;
        Node* left_child;
        Node* right_child;

    public:
        Node* getLeftChild();
        Node* getRightChild();
};
