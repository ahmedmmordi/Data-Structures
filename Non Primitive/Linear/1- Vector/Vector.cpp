#include <iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class Vector {
    private:
        int *arr {nullptr};
        int size {0};
        int capacity {0};

    public:
        // Default Constructor
        Vector() : size(0), capacity(10), arr(new int[capacity] {}) {}

        // Parameterized Constructor
        // Constructs a Vector object with the given size
        Vector(int size) : size(size) {
            if (size<0) size = 1;
            capacity = size+10;
            arr = new int[capacity] {};
        }

        // Destructor to Frees the memory used by the vector
        ~Vector() {
            delete[] arr;
            arr = nullptr;
        }

        // Returns the size of the vector
        int Get_Size() {
            return size;
        }

        // Random access a specific element by its index
        int Access(int index) {
            assert(0<=index and index<size);
            return arr[index];
        }

        // Sets the value at the specified index
        void Set(int index, int value) {
            assert(0<=index and index<size);
            arr[index] = value;
        }

        // Adds an element to the back of the vector
        void Push_Back(int value) {
            if (size==capacity) {
                Expand();
            }
            arr[size++] = value;
        }

        // Adds an element to the front of the vector
        void Push_Front(int value) {
                if (size==capacity) {
                    Expand();
                }
                for (int i=size;i>0;--i) {
                    arr[i] = arr[i-1];
                }
                arr[0] = value;
                ++size;
            }

        // Inserts an element at the specified index, shifting existing elements to the right
        void Insert_In(int index, int value) {
            assert(0<=index and index<size);
            if (size==capacity) {
                Expand();
            }
            for (int i=size-1;i>=index;--i) {
                arr[i+1] = arr[i];
            }
            arr[index] = value;
            ++size;
        }

        // Deletes the element at the specified index and returns its value
        int Delete_Position(int index) {
            assert(0<=index and index<size);
            int val = arr[index];
            for (int i=index+1;i<size;++i) {
                arr[i-1] = arr[i];
            }
            --size;
            return val;
        }

        // Sorts the elements of the vector in ascending order
        // You can write the sorting algorithm you need
        void Sort() {
            for (int i=0;i<size-1;++i) {
                for (int j=0;j<size-i-1;++j) {
                    if (arr[j]>arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }

        // Reverse the elements of the vector
        void Reverse() {
            int first = 0;
            int last = size-1;
            while (first<last) {
                // Swap
                int temp = arr[first];
                arr[first] = arr[last];
                arr[last] = temp;
                first++;
                last--;
            }
        }

        // Searches for a value in the vector and returns its index
        int Find(int value) {
            for (int i=0;i<size;++i) {
                if (arr[i]==value) {
                    return i;
                }
            }
            return -1; // Returns -1 if the value is not found
        }

        // Searches for a value in the vector, and if found, moves it to the previous position
        // Returns the new index of the value if found, or -1 if not found
        int Improved_Find(int value) {
            for (int i=0;i<size;++i) {
                if (arr[i]==value) {
                    if (i==0) {
                        return 0;
                    }
                    else {
                        // Swap
                        int temp = arr[i];
                        arr[i] = arr[i-1];
                        arr[i-1] = temp;
                        return i-1;
                    }
                }
            }
            return -1;
        }

        // Gets the first element of the vector
        int Get_Front() {
            return arr[0];
        }

        // Gets the last element of the vector
        int Get_Back() {
            return arr[size-1];
        }

        // Doubles the capacity of the vector by expanding its underlying array
        void Expand() {
            capacity *= 2;
            int *arr2 = new int[capacity] {};
            for (int i=0;i<size;++i) {
                arr2[i] = arr[i];
            }
            swap(arr, arr2);
            delete[] arr2;
        }

        // Rotates the elements of the vector one position to the right
        void Rotate_Right() {
            int last = arr[size-1];
            for (int i=size-2;i>=0;--i) {
                arr[i+1] = arr[i];
            }
            arr[0] = last;
        }

        // Rotates the elements of the vector one position to the left
        void Rotate_Left() {
            int first = arr[0];
            for (int i=1;i<size;++i) {
                arr[i-1] = arr[i];
            }
            arr[size-1] = first;
        }

        // Rotates the elements of the vector to the right by a specified number of times
        void Rotate_Right_Times(int times) {
            times %= size;
            while (times--) {
                Rotate_Right();
            }
        }

        // Check if the vector is empty
        bool IsEmpty() {
            return size==0;
        }

        // Prints the elements of the vector
        void Print() {
            for (int i=0;i<size;++i) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
};

int main() {

    /// VECTOR ///

    Vector Own(6);
    for (int i=0;i<6;++i) {
        Own.Set(i, i+1);
        // set(index, value);
    }
    Own.Print(); // Print the current vector elements

    cout << Own.Find(1) << endl; // Search for value 1 and print its index
    cout << Own.Find(12) << endl; // Search for value 12 (not found) and print -1
    cout << Own.Find(5) << endl; // Search for value 5 and print its index
    cout << "Size is: " << Own.Get_Size() << endl; // The vector's size
    cout << "Front: " << Own.Get_Front() << endl; // The first element
    cout << "Back: " << Own.Get_Back() << endl; // The last element

    Own.Push_Back(8);

    cout << "Back: " << Own.Get_Back() << endl;
    cout << "Size is: " << Own.Get_Size() << endl;
    cout << "-----------------------------------------" << endl;

    Own.Print();
    Own.Insert_In(6, 7); // Insert the value 7 at index 6
    Own.Print();
    Own.Rotate_Right(); // Rotate the elements to the right
    Own.Print();
    Own.Rotate_Left(); // Rotate the elements to the left
    Own.Print();
    Own.Rotate_Left();
    Own.Print();
    Own.Rotate_Right();
    Own.Print();

    Own.Delete_Position(7); // Delete the element at index 7
    Own.Print();
    Own.Improved_Find(4);
    Own.Improved_Find(4);
    Own.Improved_Find(4);
    Own.Improved_Find(4); // It is the first element now
    cout << "-----------------------------------------" << endl;

    Own.Improved_Find(7); // Search and moved one step to the  left
    Own.Improved_Find(7); // Search and moved another step to the left
    Own.Print();
    cout << "-----------------------------------------" << endl;

    Own.Improved_Find(3);
    Own.Print();
    cout << "-----------------------------------------" << endl;

    Own.Rotate_Right_Times(1024); // Rotate to the right 1024 times
    cout << "After rotate 1024 times: ";
    Own.Print();

    cout << "After sorting: ";
    Own.Sort(); // Sort in ascending order
    Own.Print();

    Own.Reverse(); // Reverse the elements
    cout << "After Reversing: ";
    Own.Print();
    cout << "-----------------------------------------" << endl;

    Own.Push_Front(8);
    cout << "After push front: ";
    Own.Print();
    cout << "-----------------------------------------" << endl;

    cout << (Own.IsEmpty() ? "No elements." : "There are elements.") << endl;
    Own.Print();
    cout << "The value at position 5 is: " << Own.Access(5) << endl;
    cout << "-----------------------------------------" << endl;

    return 0;
}