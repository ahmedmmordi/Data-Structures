#include<iostream>
#include <cassert>
#define endl '\n'
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev; // Pointer to the previous node

        // Parametrized constructor
        Node(int value) {
            this->data = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int length = 0;

    public:
        // Default constructor
        DoublyLinkedList() = default;

        // Destructor to release memory
        ~DoublyLinkedList() {
            while (head!=nullptr) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Function to print the linked list using a while loop
        void Print_With_While() {
            Node *now = head;
            while (now!=nullptr) {
                cout << now->data << ' ';
                now = now->next;
            }
            cout << endl;
        }

        // Function to print the linked list using a for loop
        void Print_With_For() {
            for (Node *now=head; now!=nullptr; now=now->next) {
                cout << now->data << ' ';
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
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
            ++length;
        }

        // Function to insert a new node at the front of the linked list
        void Insert_Front(int value) {
            Node *new_node = new Node(value);
            if (head==nullptr) {
                head = new_node;
                tail = new_node;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            ++length;
        }

        // Function to insert a new node at a specific position in the linked list
        void Insert_Position(int index, int value) {
            assert(index>=0 and index<=length);
            if (index==0) {
                Insert_Front(value);
            }
            else if (index==length) {
                Insert_Back(value);
            }
            else {
                Node *new_node = new Node(value);
                Node *now = head;
                for (int i=0; i<index-1; ++i) {
                    now = now->next;
                }
                new_node->prev = now;
                new_node->next = now->next;
                now->next->prev = new_node;
                now->next = new_node;
            }
            ++length;
        }

        // Function to get the Nth element (1-Based) from the linked list
        int Get_Nth_Element(int index) {
            --index;
            assert(index>=0 and index<length); // To check if the index is in range or not
            int con = 0;
            for (Node *now=head; now!=nullptr; now=now->next, ++con) {
                if (con==index) {
                    return now->data;
                }
            }
            return -1; // Element not found
        }

        // Function to get the Nth node (1-Based) from the linked list
        Node *Get_Nth_Node(int index) {
            --index;
            assert(index>=0 and index<length);
            int con = 0;
            for (Node *now=head; now; now=now->next) {
                if (++con==index) {
                    return now;
                }
            }
            return nullptr; // Node not found
        }

        // Function to search for a value in the linked list
        int Search(int value) {
            int position = 0;
            for (Node *now=head; now; now=now->next, ++position) {
                if (now->data==value) {
                    return position;
                }
            }
            return -1; // Value not found
        }

        // Function to search for a value and swap it with the previous node's value if found
        int Improved_Search(int value) {
            int position = 0;
            Node *Previous = nullptr;
            for (Node *now=head; now; now=now->next, ++position) {
                if (now->data==value) {
                    if (!Previous) return position;
                    swap(Previous->data, now->data);
                    return position - 1; // New index
                }
                Previous = now;
            }
            return -1; // Value not found
        }

        // Function to delete a specific node (1-Based) from the linked list
        void Delete_Node(int index) {
            --index;
            assert(index>=0 and index<length);
            if (index==0) {
                Node *temp = head;
                head = head->next;
                if (head!=nullptr) {
                    head->prev = nullptr;
                }
                else {
                    tail = nullptr;
                }
                delete temp;
                --length;
            }
            else if (index==length-1) {
                Node *temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
                --length;
            }
            else {
                int con = 1;
                Node *now = head;
                while (con<index) {
                    now = now->next;
                    ++con;
                }
                Node *temp = now->next;
                now->next = temp->next;
                temp->next->prev = now;
                delete temp;
                --length;
            }
        }

        // Function to check if a value exists in the linked list
        bool Is_Exist(int value) {
            for (Node *now=head; now!=nullptr; now=now->next) {
                if (now->data==value) {
                    return true;
                }
            }
            return false;
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

int main() {

    DoublyLinkedList My;
    My.Insert_Front(15);
    My.Insert_Back(20);
    My.Insert_Front(10);
    My.Insert_Back(30);
    My.Insert_Front(5);
    My.Print_With_For();
    My.Insert_Position(4,25); // Insert in a specific position
    My.Print_With_While();

    cout << "-----------------------------------------\n";

    cout << "First element: ";
    Node *Show_First = My.Get_Head(); // Return Node
    cout << Show_First->data << endl; // Data of this node

    cout << "Last element: ";
    Node *Show_Last = My.Get_Tail(); // Return Node
    cout << Show_Last->data << endl; // Data of this node

    My.Delete_Node(4); // Will delete 20
    cout << "Elements: ";
    My.Print_With_For();

    cout << "-----------------------------------------\n";

    My.Insert_Back(20);
    cout << "After inserting: ";
    My.Print_With_For();
    My.Improved_Search(20);
    My.Improved_Search(20);
    cout << "After searching about it twice: ";
    My.Print_With_For();

    cout << "-----------------------------------------\n";

    // Note: Test the remaining methods in the class and make some operations to verify your understanding.

return 0;
}