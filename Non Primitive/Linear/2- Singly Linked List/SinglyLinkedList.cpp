#include <iostream>
#include <cassert>
#define endl '\n'
using namespace std;

// class to represent a node in the linked list
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

class SinglyLinkedList {
    private:
        Node *head = nullptr;
        Node *tail {nullptr}; // == { }
        int length = 0;
    public:
        // Default constructor
        SinglyLinkedList() = default;

        // Destructor to release memory
        ~SinglyLinkedList() {
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
            // for (Node *now=head;now;now=now->next) // now same as now!=nullptr
            for (Node *now=head;now!=nullptr;now=now->next) {
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
                head = new_node;
            }
            ++length;
        }

        void Insert_Position(int index, int value) {
            assert(index>=0 and index<=length);
            if (index==0) Insert_Front(value);
            else if (index==length) Insert_Back(value);
            else {
                Node *new_node = new Node(value);
                Node *now = head;
                for (int i=0;i<index-1;i++) {
                    now = now->next;
                }
                new_node->next = now->next;
                now->next = new_node;
            }
            ++length;
        }

        // Function to get the Nth element (1-Based) from the linked list
        int Get_Nth_Element(int index) {
            --index;
            assert(index>=0 and index<length); // To check if the index is in range or not
            int con = 0;
            for (Node *now=head;now!=nullptr;now=now->next,++con) {
                if (con==index) {
                    return now->data;
                }
            }
            return -1; // Element not found
            // -1 Just for practice
        }

        // Function to get the Nth node (1-Based) from the linked list
        Node *Get_Nth_Node(int index) {
            --index;
            assert(index>=0 and index<length);
            int con = 0;
            for (Node *now=head;now;now=now->next) {
                if (++con==index) {
                    return now;
                }
            }
            return nullptr; // Node not found
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

        // Function to search for a value and swap it with the previous node's value if found
        int Improved_Search(int value) {
            int position = 0;
            Node *Previous = nullptr;
            for (Node *now=head;now;now=now->next,++position) {
                if (now->data==value) {
                    if (!Previous) return position;
                    swap(Previous->data, now->data);
                    return position-1; // New index
                }
                Previous = now;
            }
            return -1; // Value not found
        }

        // Function to search for a value and swap it with the previous node's value if found (alternative implementation)
        int Improved_Search2(int value) {
            int position = 0;
            //                               The order is so important in this
            for (Node *now=head,*Prev=nullptr; now; Prev=now,now=now->next) {
                if (now->data==value) {
                    if (!Prev) return position;
                    swap(Prev->data, now->data);
                    return position-1;
                }
                ++position;
            }
            return -1;
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

        // Function to check if a value exists in the linked list
        bool Is_Exist(int value) {
            for (Node *now=head;now!=nullptr;now=now->next) {
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

// Functions to create some nodes and do many operations on them first
void Print(Node *head) {
    while (head!=nullptr) {
        cout << head->data << ' ';
        head =  head->next;
    }
    cout << endl;
}

void Print_Recursive(Node *head) {
    if (head==nullptr) {
        cout << '\n';
        return;
    }
    cout << head->data << ' ';
    Print_Recursive (head->next);
}

void Print_Reversed(Node *head) {
    if (head==nullptr) return;
    Print_Reversed(head->next);
    cout << head->data << ' ';
}

bool Find_Value(Node *head, int value) {
    while (head) {
        if (head->data==value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

Node *Find_Node(Node *head, int value) {
    while (head) {
        if (head->data==value) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

int main() {

    // Let's create some nodes
    Node *one = new Node(5);
    Node *two = new Node(10);
    Node *three = new Node(15);
    Node *four = new Node(20);

    // Now we have to connect each one to its next
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = nullptr; // The last one point to nullptr (no thing)

    cout << one->data << ' '; // 5
    cout << two->data << ' '; // 10
    cout << three->data << ' '; // 15
    cout << four->data << endl; // 20

    cout << one->next->next->next->data << endl; // 20, Same as four->data
    Print(two); // Begin from two: 10 15 20

    cout << "-----------------------------------------\n";

    cout << "Recursive: ";
    Print_Recursive(three); // Same as Print but this is recursive

    cout << "Reversed: ";
    Print_Reversed(one);
    cout << endl;

    cout << "-----------------------------------------\n";

    if (Find_Value(one, 20)) cout << "Found\n";
    else cout << "Not found\n";

    cout << (Find_Value(one, 18) ? "Found\n" : "Not found\n");

    Node *Result = Find_Node(one, 20);
    if (Result) cout << "Data found: " << Result->data << endl;
    else cout << "Data not found\n";

    Result = Find_Node(one, 25);
    if (Result) cout << "Data found: " << Result->data << endl;
    else cout << "Data not found\n";

    cout << "-----------------------------------------\n";

    // Clean up the linked list (free memory)
    while (one) {
        Node *temp = one;
        one = one->next;
        delete temp;
    }
    cout << "-----------------------------------------\n";

    // Another linked-list like: one, two, three, and four
    Node *Base = new Node(1);
    Base->next = new Node(2);
    Base->next->next = new Node(3);
    Base->next->next->next = new Node(4);
    Base->next->next->next->next = new Node(5);
    // cout << Base->next->next->next->next->next << endl; // We must check first if it is exist or not
    cout << "Base: ";
    Print(Base);

    while (Base) { // Base!=nullptr
        Node *temp = Base;
        Base = Base->next;
        delete temp;
    }

    cout << "-------------------------------------------\n";

    /// SINGLY LINKED LIST ///

    // Make an instance
    SinglyLinkedList My;
    My.Insert_Front(3);
    My.Insert_Back(5);
    My.Insert_Back(7);
    My.Insert_Front(2);
    My.Insert_Back(11);
    cout << "Size: " << My.Get_Length() << endl;
    cout << "While: "; My.Print_With_While();
    cout << "For: "; My.Print_With_For();

    cout << "-----------------------------------------\n";

    cout << (My.Is_Exist(11) ? "Found\n" : "Not Found\n");
    cout << My.Get_Nth_Element(1) << endl; //  Given index 1-Based
    cout << My.Get_Nth_Element(3) << endl;
    cout << My.Get_Nth_Element(5) << endl;

    cout << "-----------------------------------------\n";
    My.Print_With_For();
    cout << My.Search(2) << endl; // Return index 0-Based
    cout << My.Search(11) << endl;
    cout << "-----------------------------------------\n";
    My.Print_With_For();
    cout << My.Improved_Search(11) << endl; // Shifting the value if found by one to the left and return its new position
    My.Print_With_For();
    cout << My.Improved_Search2(11) << endl;
    My.Print_With_While();
    cout << My.Improved_Search(11) << endl;
    My.Print_With_For();
    cout << My.Improved_Search2(11) << endl;
    My.Print_With_While();
    cout << "-----------------------------------------\n";
    My.Delete_Node(1); // Index 1-Based
    cout << "The Length Became: " << My.Get_Length() << endl;
    My.Print_With_For();
    My.Delete_Node(4);
    cout << "The Length Became: " << My.Get_Length() << endl;
    My.Print_With_For();
    My.Delete_Node(2);
    cout << "The Length Became: " << My.Get_Length() << endl;
    cout << "The remaining elements are: ";
    My.Print_With_For();

    My.Insert_Position(1,100); // (index, value)
    cout << "After inserting in the middle: ";
    My.Print_With_For();
    cout << "-----------------------------------------\n";

    // Test the remaining methods such as: Is_Empty, Get_Head, etc.., to verify your understanding.

    return 0;
}