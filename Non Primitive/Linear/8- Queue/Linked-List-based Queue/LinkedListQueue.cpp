#include <iostream>
#define endl "\n"
using namespace std;

class Queue {
    private:
        class Node {
            public:
                int data;
                Node *next;
                // Parametrized constructor
                Node(int value) {
                    this->data = value;
                    this->next = nullptr;
                }
        };
        Node *Front;
        Node *Rear;
        int size;

    public:
        // default constructor
        Queue() {
            this->Front = nullptr;
            this->Rear = nullptr;
            this->size = 0;
        }

        // Destructor to release memory
        ~Queue() {
            while (Front!=nullptr) {
                Node *temp = Front;
                Front = Front->next;
                delete temp;
            }
            Front = nullptr;
            Rear = nullptr;
            size = 0;
        }

        // Function to add an element to the back of the queue
        void Enqueue(int value) {
            Node *new_element = new Node(value);
            if (Front==nullptr) {
                Front = new_element;
                Rear = new_element;
            }
            else {
                Rear->next = new_element;
                Rear = new_element;
            }
            ++size;
        }

        // Function to remove the first (front) element from the queue
        void Dequeue() {
            if (Front==nullptr) throw logic_error("Cannot delete from already empty queue.\n");
            else {
                Node *Temp = Front;
                Front = Front->next;
                delete Temp;
                --size;
            }
        }

        // Function to get the value of the first element in the queue
        int GetFront() {
            if (Front==nullptr) throw logic_error("Queue is empty.\n");
            else return Front->data;
        }

        // Function to get the value of the last element in the queue
        int GetBack() {
            if (Rear==nullptr) throw logic_error("Queue is empty.\n");
            else  return Rear->data;
        }

        // Function to search about an element in the queue
        bool IsExist(int value) {
            if (Front==nullptr) throw logic_error("Queue is empty.\n");
            else {
                Node *Temp = Front;
                while(Temp!=nullptr) {
                    if (Temp->data==value) return true; // found
                    Temp = Temp->next;
                }
                return false; // not found
            }
        }

        // Function to check if the queue is empty
        bool IsEmpty() {
            return Front==nullptr;
        }

        // Function to return the number of elements
        int Size() {
            return size;
        }

        // Function to print the elements of the queue
        void print() {
            if (Front==nullptr) throw logic_error("Cannot print an empty queue.\n");
            else{
                cout << "List: ";
                Node *Temp = Front;
                while(Temp!=nullptr) {
                    cout << Temp->data << ' ';
                    Temp = Temp->next;
                }
                cout << endl;
            }
        }

        // Function to remove all the elements of the queue
        void Clear() {
            if (Front==nullptr) throw logic_error("Cannot clear an already empty queue.\n");
            else {
                while(Front!=nullptr) {
                    Node *Temp = Front;
                    Front = Front->next;
                    delete Temp;
                }
                Front = nullptr;
                Rear = nullptr;
                size = 0;
            }
        }
};

int main() {

    Queue my;
    cout << (my.IsEmpty()? "Empty" : "Not empty") << endl;
    // my.Clear(); // It will throw an exception because its already empty
    my.Enqueue(1);
    my.Enqueue(2);
    my.Enqueue(3);
    my.Enqueue(4);
    my.Enqueue(5);
    cout << "Size: " << my.Size() << endl;
    my.print();
    cout << (my.IsExist(3)? "Found" : "Not Found") << endl;
    cout << (my.IsExist(7)? "Found" : "Not Found") << endl;
    cout << "Front: " << my.GetFront() << endl;
    cout << "Back: " << my.GetBack() << endl;
    my.Dequeue();
    my.Dequeue();
    cout << "Size became: " << my.Size() << endl;
    my.print();
    my.Clear();
    cout << "Size now: " << my.Size() << endl;
    // my.print(); // It will throw an exception because there are no elements to print

    my.Enqueue(1);
    my.print();

    return 0;
}