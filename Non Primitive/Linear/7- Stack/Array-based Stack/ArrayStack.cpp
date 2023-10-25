#include<iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class Stack {
    private:
        int *arr;
        int top; // Keeps track of the top element in the stack
        int capacity;

    public:
        // Parameterized constructor for the Stack class
        // Initializes an empty stack with a given size
        Stack(int size) {
            this->arr = new int[size];
            this->top = -1;
            this->capacity = size;
        }

        // Destructor to release the dynamically allocated memory
        ~Stack() {
            delete[] arr;
        }

        // Pushes an element onto the stack
        void Push(int value) {
            assert(!Is_Full());
            arr[++top] = value;
        }

        // Pops and returns the top element from the stack
        int Pop() {
            assert(!Is_Empty());
            return arr[top--];
        }

        // Returns the top element of the stack
        int Get_Top() {
            assert(!Is_Empty());
            return arr[top];
        }

        // Returns the number of elements in the stack
        int Get_Length() {
            return top+1;
            // Do not return the capacity, the top+1 is the actually number of elements in the stack now
            // top+1 Because its begin from top = -1
        }

        // Checks if the stack is full
        bool Is_Full() {
            return top==capacity-1;
        }

        // Checks if the stack is empty
        bool Is_Empty() {
            return top==-1;
        }

        // Prints the elements of the stack from top to bottom
        void Print() {
            for (int i=top; i>=0; --i) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
};

int main() {

    Stack Own(5);
    cout << (Own.Is_Empty()? "Empty" : "Not Empty") << endl;
    Own.Push(14);
    Own.Push(11);
    Own.Push(22);
    Own.Push(17); // Now the top element is 17
    cout << "Top is: " << Own.Get_Top() << endl;
    Own.Print();
    Own.Pop(); // Delete the top
    Own.Push(9);
    Own.Print();
    cout << "Size is: " << Own.Get_Length() << endl;
    cout << "Top is: " << Own.Get_Top() << endl;

    cout << "-------------------------------\n";

    cout << (Own.Is_Full()? "Full" : "Not Full") << endl;
    cout << (Own.Is_Empty()? "Empty" : "Not Empty") << endl;

    cout << "-------------------------------\n";

    Own.Push(42);
    cout << "Size is: " << Own.Get_Length() << endl;
    cout << "Top is: " << Own.Get_Top() << endl;
    cout << (Own.Is_Full()? "Full" : "Not Full") << endl;
    // Own.Push(42); // Assertion failed: !Is_Full()

    cout << "-------------------------------\n";

    return 0;
}