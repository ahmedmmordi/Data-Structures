#include <iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class LinkedList {
    private:
        // Private class to represent a node in the linked list
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

        Node *head;
        Node *tail;
        int length;

    public:
        // Default constructor
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        // Destructor to release memory
        ~LinkedList() {
            while (head!=nullptr) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Function to print the elements of the linked list
        void Print_List() {
            Node *now = head;
            while (now!=nullptr) {
                cout << now->data << ' ';
                now = now->next;
            }
            cout << endl;
        }

        // Function to insert a new node at the back of the linked list
        void Insert_Back(int value) {
            Node *new_node = new Node(value);
            if (head==nullptr) {
                head = new_node;
                tail = new_node;
            }
            else {
                tail->next = new_node;
                tail = new_node;
            }
            ++length;
        }

        // Function to search for a value in the linked list
        int Search(int value) {
            int position = 0;
            for (Node *now=head;now;now=now->next,++position) {
                if (now->data==value) {
                    return position;
                }
            }
            return -1; // Value not found
        }

        // Function to delete the a specific node (1-Based) from the linked list
        void Delete_Node(int index) {
            --index;
            assert(index>=0 and index<length);
            if (index==0) {
                Node *temp = head;
                head = head->next;
                delete temp;
                --length;
                if (head==nullptr) {
                    tail = nullptr;
                }
            }
            else {
                int con = 1;
                Node *Previous = head;
                while (con<index) {
                    Previous = Previous->next;
                    ++con;
                }
                Node *temp = Previous->next;
                Previous->next = temp->next;
                delete temp;
                --length;
                if (Previous->next==nullptr) {
                    tail = Previous;
                }
            }
        }

        // Function to check if the linked list is empty
        bool Is_Empty() {
            return head==nullptr;
        }

        // Function to get the length of the linked list
        int Get_Length() {
            return length;
        }

        // Function to get the head node of the linked list
        Node *Get_Head() {
            return head;
        }

        // Function to get the tail node of the linked list
        Node *Get_Tail() {
            return tail;
        }
};

class Queue {
    private:
        LinkedList list; // Queue implemented based on a linked list (as its underlying data structure).

    public:
        // Function to add an element to the back of the queue.
        void Enqueue(int value) {
            list.Insert_Back(value);
        }

        // Function to remove the first (front) element from the queue.
        void Dequeue() {
            return list.Delete_Node(1); // First (front) node 1-Based
        }

        // Function to get the value of the front element in the queue.
        int Get_Front() {
            return list.Get_Head()->data;
        }

        // Function to get the value of the back element in the queue.
        int Get_Back() {
            return list.Get_Tail()->data;
        }

        // Function to check if the queue is empty.
        bool Is_Empty() {
            return list.Is_Empty();
        }

        // Function to get the current size of the queue.
        int Get_Size() {
            return list.Get_Length();
        }

        // Function to check if a specific value exists in the queue.
        int Is_Exist(int value) {
            return list.Search(value);
        }

        // Function to print the elements of the queue.
        void Print() {
            list.Print_List();
        }
};

int main() {

    Queue My;
    cout<< (My.Is_Empty() ? "Empty" : "Not empty") << endl;
    cout << "Size is: " << My.Get_Size() << endl;
    My.Enqueue(2);
    My.Enqueue(5);
    My.Enqueue(7);
    My.Enqueue(12);
    cout << "Elements are: ";
    My.Print();
    cout << "Front is: " << My.Get_Front() << endl;
    cout << "Back is: " << My.Get_Back() << endl;

    cout << "-----------------------------------------\n";

    cout<< (My.Is_Empty() ? "Empty" : "Not empty") << endl;
    My.Dequeue();
    cout << "Elements are: ";
    My.Print();
    cout << "Size is: " << My.Get_Size() << endl;
    cout << "Front is: " << My.Get_Front() << endl;
    cout << "Back is: " << My.Get_Back() << endl;
    cout << (My.Is_Exist(6)==-1 ? "Not found" : "Found") << endl; // -1 means not found

    int position = My.Is_Exist(7);
    if (position==-1) cout << "Not found";
    else cout << "Found in: " << ++position << endl; // ++ to return it 1-Based
    cout << "-----------------------------------------\n";

    return 0;
}