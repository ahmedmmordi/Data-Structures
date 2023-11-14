#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        // left and right only because it's a binary tree (two child nodes at the most)

        // Parameterized constructor
        Node(int value) {
            this->data = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

// V -> means: Value
// R -> means: Right
// L -> means: Left

void Print_PreOrder(Node *current) { // Pre-Order (VLR)
    if (current==nullptr) return;

    cout << current->data << ' ';
    Print_PreOrder(current->left);
    Print_PreOrder(current->right);
}

void Print_InOrder(Node *current) { // In-Order (LVR)
    if (current==nullptr) return;

    Print_InOrder(current->left);
    cout << current->data << ' ';
    Print_InOrder(current->right);
}

void Print_PostOrder(Node *current) { // Post-Order (LRV)
    if (current==nullptr) return;

    Print_PostOrder(current->left);
    Print_PostOrder(current->right);
    cout << current->data << ' ';
}

int main() {

    // Let's assume that we have a tree like this
/*
Left       Root          Right
            1
    2               3
        4                 5
                    7           6
*/

    // A better illustration
/*
Left       Root          Right
            1
           / \
          2   3
           \   \
            4   5
               / \
              7   6
*/

    // Now let's create this tree
    // The root
    Node *root = new Node(1);

    // It's children
    root->left = new Node(2);
    root->right = new Node(3);

    // Connecting the nodes
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    root->right->right->left = new Node(7);

    // Printing our tree by three methods
    cout << "Pre-Order: ";
    Print_PreOrder(root);
    cout << endl;

    cout << "In-Order: ";
    Print_InOrder(root);
    cout << endl;

    cout << "Post-Order: ";
    Print_PostOrder(root);
    cout << endl;

    cout << "-----------------------------------------";

    return 0;
}
