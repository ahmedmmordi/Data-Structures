#include <iostream>
#include <queue>
using namespace std;

class BinarySearchTree {
    private:
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
        Node *Root;
        int length;

        // The next helper functions streamline the code, enhancing readability, maintainability, and breaking down complex operations into smaller parts.

        // Depth First Search (DFS) can done by 3 methods
        // 1- Pre-Order: root, left, right
        // 2- In-Order: left, root, right
        // 3- Post-Order: left, right, root
        // Helper function for assisting PrintDFS in printing the elements in ascending order using In-Order traversal
        void PrintDFS_Helper(Node *Root) {
            if (Root==nullptr) return;
            else {
                PrintDFS_Helper(Root->left);
                cout << Root->data << ' ';
                PrintDFS_Helper(Root->right);
            }
        }

        // Helper function for assisting Insert in finding the correct node for new element insertion
        bool InsertHelper(Node *Root, int value) {
            if (value==Root->data) {
                return false; // Duplicate value, reject insertion
            }
            else if (value<Root->data) {
                if (Root->left==nullptr) {
                    Node *new_node = new Node(value);
                    Root->left = new_node;
                    return true;
                }
                else InsertHelper(Root->left, value);
            }
            else { // value>Root->data
                if (Root->right==nullptr) {
                    Node *new_node = new Node(value);
                    Root->right = new_node;
                    return true;
                }
                else InsertHelper(Root->right, value);
            }
        }

        // Helper function to help the Searching function
        bool SearchHelper(Node *Root, int value) {
            if (Root==nullptr) return false;
            else if (Root->data==value) return true;
            else if (Root->data>value) return SearchHelper(Root->left, value);
            else return SearchHelper(Root->right, value);
        }

        // Helper function to help the ClearAll function
        void ClearAll_Helper(Node *Root) {
            if (Root==nullptr) return;
            ClearAll_Helper(Root->left);
            ClearAll_Helper(Root->right);
            delete Root;
        }

    public:
        // Default constructor
        BinarySearchTree() {
            this->Root = nullptr;
            this->length = 0;
        }

        // Function to print the elements of the BST in ascending order (in-order traversal)
        void PrintDFS() {
            Node *Temp = Root;
            PrintDFS_Helper(Temp);
        }

        // Function to print the BST level by level (BFS)
        void PrintBFS() {
            if (Root==nullptr) {
                cout << "No elements to print.\n";
            }
            else {
                queue<Node*>Save;
                Save.push(Root);
                int counter = 0;
                while (!Save.empty()) {
                    int sz = Save.size();
                    cout << "- Level " << counter++ << " are: ";
                    for (int i=0;i<sz;++i) {
                        Node *Now = Save.front();
                        Save.pop();
                        cout << Now->data << ' ';
                        if (Now->left!=nullptr) Save.push(Now->left);
                        if (Now->right!=nullptr) Save.push(Now->right);
                    }
                    cout << endl;
                }
            }
        }

        // Function to insert the elements
        void Insert(int value) {
            Node *Temp = new Node(value);
            if (Root==nullptr) {
                Root = Temp;
                ++this->length;
            }
            else {
                if (InsertHelper(Root, value)) {
                    ++this->length;
                }
                else return;
            }
        }

        // Fuction to search about an element
        bool Search(int value) {
            return SearchHelper(Root, value);
        }

        // Fuction to get the minimum element
        int Get_Min() {
            Node *Temp = Root;
            while(Temp->left!=nullptr) {
                Temp = Temp->left;
            }
            return Temp->data;
        }

        // Fuction to get the maximum element
        int Get_Max() {
            Node *Temp = Root;
            while(Temp->right!=nullptr) {
                Temp = Temp->right;
            }
            return Temp->data;
        }

        // Fuction to get the size of the BST
        int Get_Size() {
            return this->length;
        }

        // Fuction to clear all the elements
        void ClearAll() {
            ClearAll_Helper(Root);
            Root = nullptr;
            length = 0;
        }

        // Fuction to check if the BST is empty or not
        bool IsEmpty() {
            return Root==nullptr;
        }
};

int main() {

    // This is a simple BST
    // You should not insert duplicates
    // You should not insert element between two existed ones
    // Insert only left or right

    BinarySearchTree BST;

    cout << (BST.IsEmpty() ? "Empty" : "Not Empty") << endl;
    cout << "Size is: " << BST.Get_Size() << endl;
    cout << "---------------------------\n";

    BST.Insert(4);
    BST.Insert(2);
    BST.Insert(6);
    BST.Insert(3);
    BST.Insert(1);
    BST.Insert(1);
    BST.Insert(1);
    BST.Insert(7);
    BST.Insert(5);

/*
           4
         /   \
        2     6
       / \   / \
      1   3 5   7
*/

    cout << (BST.IsEmpty() ? "Empty" : "Not Empty") << endl;
    cout << "Size is: " << BST.Get_Size() << endl;
    cout << "Maximum element is: " << BST.Get_Max() << endl;
    cout << "Minimum element is: " << BST.Get_Min() << endl;
    cout << "---------------------------\n";

    cout << "The elements are: ";
    BST.PrintDFS();
    cout << endl;

    cout << (BST.Search(3) ? "Found" : "Not Found") << endl;
    cout << (BST.Search(8) ? "Found" : "Not Found") << endl;
    cout << "---------------------------\n";

    cout << "The levels are:\n";
    BST.PrintBFS();
    cout << "---------------------------\n";

    BST.ClearAll();
    BST.PrintBFS();
    cout << "Size is: " << BST.Get_Size() << endl;
    cout << "---------------------------\n";

    return 0;
}
