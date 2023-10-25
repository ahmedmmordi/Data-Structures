#include <iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class SLL2DArray {
    private:
        // Private class representing a Node in the 2D singly linked list
        class Node {
            public:
                int data;
                Node *right;
                Node *down;
                Node(int value) {
                    this->data = value;
                    this->right = nullptr;
                    this->down = nullptr;
                }
        };
        int rows;
        int columns;
        Node *head;

    public:
        // Constructor to create a 2D singly linked list with the specified number of rows and columns
        SLL2DArray(int rows, int cols) {
            assert(rows>=0 and cols>=0);

            this->rows = rows;
            this->columns = cols;
            this->head = nullptr;

            head = new Node(0);
            Node *current_row = head , *current_col = head;

            // Create the first row
            for (int i=1;i<columns;++i) {
                current_col->right = new Node(0);
                current_col = current_col->right;
            }

            // Create the remaining rows
            for (int i=1;i<rows;++i) {
                current_row->down = new Node(0);
                current_row = current_row->down;
                current_col = current_row;
                for (int j=1;j<columns;++j) {
                    current_col->right = new Node(0);
                    current_col = current_col->right;
                }
            }
        }

        // Destructor to free dynamically allocated memory
        ~SLL2DArray() {
            Node *current_row = head;
            while (current_row!=nullptr) {
                Node *current_col = current_row;
                while (current_col!=nullptr) {
                    Node *next_col = current_col->right;
                    delete current_col;
                    current_col = next_col;
                }
                Node *next_row = current_row->down;
                current_row = next_row;
            }
        }

        // Assign a value to the specified location in the 2D array
        void Assign(int row, int col, int value) {
            assert((row>=0 and row<rows) and (col>=0 and col<columns));
            Node *current = head;
            for (int i=0;i<row;++i) {
                current = current->down;
            }
            for (int j=0;j<col;++j) {
                current = current->right;
            }
            current->data = value;
        }

        // Get the total size of the 2D array (number of elements)
        int Get_Size() {
            return rows*columns;
        }

        // Print the 2D array in a structured format
        void Print() {
            Node *current_row = head;
            for (int i=0;i<rows;++i) {
                Node *current_Col = current_row;
                for (int j=0;j<columns;++j) {
                    cout << current_Col->data << ' ';
                    current_Col = current_Col->right;
                }
                current_row = current_row->down;
                cout << endl;
            }
        }
};

int main() {
    int Rows=3 , Cols=5;
    SLL2DArray My_Array(Rows, Cols);

    // Assign any values
    int value = 10;
    for (int i=0;i<Rows;++i) {
        for (int j=0;j<Cols;++j,value+=5) {
            My_Array.Assign(i, j, value);
        }
    }
    My_Array.Assign(1, 2, 99); // (row, col, value) 0-Based

    My_Array.Print();
    cout << "-------------------------------\n";

    cout << "Number of elements is: " << My_Array.Get_Size() << endl;
    cout << "-------------------------------\n";

    // Try these to test your understanding:
    // 1- Implement a function to find the maximum or minimum number in this 2D array.
    // 2- Implement a recursive function to print the elements in reverse order.

    return 0;
}