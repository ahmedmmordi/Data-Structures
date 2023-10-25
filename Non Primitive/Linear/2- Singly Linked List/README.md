# Singly Linked List

A **linked list** is a fundamental data structure composed of nodes. Each node comprises two key components:

- **Data:** Stores the value or information represented by the node.
- **Next (or Link) Pointer:** Points to the next node in the list, enabling sequential traversal.

In a singly linked list, nodes are connected in one direction, from the head (the first node) to the tail (the last node). This dynamic data structure allows for efficient insertions and deletions.

## Node Class

### Description
The `Node` class is used to represent a node in a linked list. It encapsulates the following attributes:

- `int data`: The data stored in the node.
- `Node *next`: A pointer to the next node in the list.

### Constructor
The class features a parametrized constructor to initialize a `Node` object with a specified value. It sets the `data` attribute to the given value and the `next` pointer to `nullptr`, indicating that initially, there is no next node connected to it.


## Singly Linked-List Class Methods

### `SinglyLinkedList()`

- **Description:** Initializes an empty linked list.

### `~SinglyLinkedList()`

- **Description:** Destructor to release memory used by the linked list. It deletes all nodes.

### `void Print_With_While()`

- **Description:** Prints the elements of the linked list using a while loop.

### `void Print_With_For()`

- **Description:** Prints the elements of the linked list using a for loop.

### `void Insert_Back(int value)`

- **Description:** Inserts a new node with the specified value at the back of the linked list.

### `void Insert_Front(int value)`

- **Description:** Inserts a new node with the specified value at the front of the linked list.

### `void Insert_Position(int index, int value)`
- **Description:** Inserts a new node with the specified value at the given index within the linked list.

### `int Get_Nth_Element(int index)`

- **Description:** Returns the value of the Nth element (1-based) from the linked list.

### `Node *Get_Nth_Node(int index)`

- **Description:** Returns the Nth node (1-based) from the linked list.

### `int Search(int value)`

- **Description:** Searches for a value in the linked list and returns its position (1-based) or -1 if not found.

### `int Improved_Search(int value)`

- **Description:** Searches for a value in the linked list and swaps it with the previous node's value if found, returning the new position (1-based) or -1 if not found.

### `int Improved_Search2(int value)`

- **Description:** An alternative implementation of Improved_Search.

### `void Delete_Node(int index)`

- **Description:** Deletes a specific node (1-based) from the linked list.

### `bool Is_Exist(int value)`

- **Description:** Checks if a value exists in the linked list and returns `true` if found, `false` otherwise.

### `bool Is_Empty()`

- **Description:** Checks if the linked list is empty and returns `true` if it is, `false` otherwise.

### `int Get_Length()`

- **Description:** Returns the length of the linked list.

### `Node *Get_Head()`

- **Description:** Returns the head node of the linked list.

### `Node *Get_Tail()`

- **Description:** Returns the tail node of the linked list.

## Real-Life Scenarios

In the following scenarios, singly linked lists are used for specific purposes:

### Inventory Tracking
Inventory tracking systems in retail or warehouses can use singly linked lists to monitor stock levels and item information. Each node can represent a unique product or item in the inventory. The list allows for easy insertion and removal of items as new stock arrives or gets sold. Additionally, it provides a straightforward way to update item details such as price, quantity, and location, ensuring that inventory records remain accurate and up-to-date.

### Social Media Feed
Singly linked lists can be employed to create and manage a social media feed, such as those found on platforms like Facebook or Twitter. In this context, each node in the list represents a post or update from a user. Users can add new posts, scroll through their feed, like, comment on, or share posts. Singly linked lists make it convenient to display posts in chronological order, ensuring that users can view their social media content in a time-sequential manner. Additionally, it allows for efficient management of posts, enabling users to interact with their network and stay updated with the latest content.

## Example Usage

In the `main` function, there are various examples of how to use the `SinglyLinkedList` class. You can create a linked list, insert elements, perform various operations, and retrieve information about the linked list.