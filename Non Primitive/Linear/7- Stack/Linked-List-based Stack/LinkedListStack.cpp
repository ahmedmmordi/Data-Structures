#include<iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class Stack {
    private:
        // Private class representing a Node in the stack
        class Node {
            public:
                int data;
                Node *next;
                Node(int value) {
                    this->data = value;
                    this->next = nullptr;
                }
        };

        Node *top; // Pointer to the top Node of the stack
        int length;

    public:
        // Constructor for the Stack class
        Stack() : top(nullptr), length(0) {}

        // Pushes a new element onto the stack
        // It will work as long as your machine has more RAM
        // In real-life, We check if return null or not first
        void Push(int value){
            Node *new_node =  new Node(value);
            new_node->next = top;
            top = new_node;
            ++length;
        }

        // Pops the top element from the stack
        int Pop() {
            if (Is_Empty()) {
                throw underflow_error("Stack is empty\n");
                // Do not print on console unless it is a console project
                // In reality, people see output on web or mobile screens
            }
            Node *temp = top;
            top = top->next;
            int value = temp->data;
            delete temp;
            --length;
            return value;
        }

        // Prints the elements in the stack
        void Print() {
            Node *temp = top;
            while (temp!=nullptr) {
                cout << temp->data << ' ';
                temp = temp->next;
            }
            cout << endl;
            delete temp;
        }

        // Returns the length of the stack
        int Get_Length() {
            return length;
        }

        // Returns the top element of the stack
        int Get_Top() {
            assert(!Is_Empty());
            return top->data;
        }

        // Checks if the stack is empty
        bool Is_Empty() {
            return top==nullptr;
        }

        // Destructor for the stack, for cleaning up allocated memory
        ~Stack() {
            while (!Is_Empty()) {
                Pop();
            }
        }
};

int main() {

    Stack Own;
    Own.Push(6); // 6
    Own.Push(5); // 6 5
    Own.Push(13); // 6 5 13
    Own.Push(8); // 6 5 13 8
    cout << "Top: " << Own.Get_Top() << endl;
    cout << "Size: "<< Own.Get_Length() << endl;
    cout << (Own.Is_Empty() ? "Empty" : "Not Empty") << endl;

    cout << "-------------------------------\n";
    cout << "The popped element is: " << Own.Pop() << endl; // Elements became: 6 5 13
    cout << "Top: " << Own.Get_Top() << endl;
    cout << "Size: "<< Own.Get_Length() << endl;
    cout << "Elements: ";
    Own.Print();
    cout << "-------------------------------\n";

return 0;
}