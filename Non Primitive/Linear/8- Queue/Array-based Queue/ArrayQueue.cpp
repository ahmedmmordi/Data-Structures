#include <iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class Queue {
    private:
        int *arr; // Pointer to dynamically allocated array for storing queue elements
        int front; // Front of the queue
        int rear;  // Rear or back of the queue
        int capacity; // Actual capacity of the queue
        int size; // Current size

    public:
        // Constructor
        Queue() {
            this->capacity = 10;
            this->arr = new int[capacity];
            this->front = 0;
            this->rear = -1; // Set to -1 to indicate an empty queue
            this->size = 0;
        }

        // Parameterized constructor
        Queue(int given_capacity) : front(0), rear(-1), size(0) {
            assert(given_capacity>0);
            capacity = given_capacity;
            arr = new int[given_capacity];
        }

        // Function to print the elements in the queue
        void Print() {
            assert(!Is_Empty());
            int current = front;
            while (current!=rear) {
                cout << arr[current] << ' ';
                current = (current+1) % capacity;
            }
            cout << arr[current] << endl;
        }

        // Function to check if the queue is empty
        bool Is_Empty() {
            return size==0;
        }

        // Function to check if the queue is full
        bool Is_Full() {
            return size==capacity;
        }

        // Function to add an element to the rear of the queue
        void Enqueue(int value) {
            assert(!Is_Full());
            rear = (rear+1) % capacity;
            /*
            The purpose of this equation is to create a circular behavior in the array, which is a common technique used to efficiently utilize the available memory space in queue implementations.
            It works as follows: when the rear index reaches the end of the array, taking the modulus brings it back to 0, effectively wrapping around to the start of the array, allowing for circular usage.
            */
            arr[rear] = value;
            ++size;
        }

        // Function to remove and return the element from the front of the queue
        int Dequeue() {
            assert(!Is_Empty());
            int element = arr[front];
            front = (front+1) % capacity;
            --size;
            return element;
        }

        // Function to get the element at the front of the queue without removing it
        int Get_Front() {
            assert(!Is_Empty());
            return arr[front];
        }

        // Function to get the last element of the queue without removing it
        int Get_Rear() {
            assert(!Is_Empty());
            return arr[rear];
        }

        // Function to get the size of the queue
        int Get_Size() {
            return size;
        }

        // Function to get the maximum capacity of the queue
        int Get_Capacity(){
            return capacity;
        }

        // Destructor to release memory
        ~Queue() {
            delete[] arr;
        }
};

int main() {

    Queue My(5);
    cout << (My.Is_Empty() ? "Empty" : "Not empty") << endl;
    My.Enqueue(2); // enqueue means add an element to the queue (to the back of it)
    My.Enqueue(4);
    My.Enqueue(6);
    My.Enqueue(9);
    cout << (My.Is_Empty() ? "Empty" : "Not empty") << endl;
    cout << (My.Is_Full() ? "Full" : "Not full") << endl;

    cout << "Elements are: ";
    My.Print();
    cout << "Size is: " << My.Get_Size() << endl;
    cout << "-----------------------------------------\n";

    My.Enqueue(13); // dequeue means remove an element from the queue (the front or the first one)
    cout << (My.Is_Full() ? "Full" : "Not full") << endl;
    cout << "Elements are: ";
    My.Print();
    cout << "Size is: " << My.Get_Size() << endl;
    cout << "Front is: " << My.Get_Front() << endl;
    cout << "Rear is: " << My.Get_Rear() << endl;
    cout << "-----------------------------------------\n";

    My.Dequeue();
    cout << "Elements are: ";
    My.Print();
    cout << "Front is: " << My.Get_Front() << endl;
    My.Dequeue();
    cout << "Elements are: ";
    My.Print();
    cout << "Size is: " << My.Get_Size() << endl;
    cout << "Capacity is: " << My.Get_Capacity() << endl;
    cout << "Front is: " << My.Get_Front() << endl;
    cout << "Rear is: " << My.Get_Rear() << endl;
    cout << "-----------------------------------------\n";

    return 0;
}