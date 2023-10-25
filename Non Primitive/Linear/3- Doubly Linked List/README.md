# Doubly Linked List

A **doubly linked list** is a fundamental data structure composed of nodes. Each node in a doubly linked list contains three main components:

- **Data:** Stores the value or information represented by the node.
- **Next Pointer:** Points to the next node in the list, enabling sequential traversal.
- **Previous Pointer:** Points to the previous node in the list, allowing bidirectional traversal.

In contrast to a singly linked list, where nodes are connected in one direction, from the head to the tail, a doubly linked list allows nodes to be traversed in both directions.

## Node Class

### Description
The `Node` class is used to represent a node in a doubly-linked list. It encapsulates the following attributes:

- `int data`: This attribute holds the data stored in the node.
- `Node *next`: A pointer to the next node in the list.
- `Node *prev`: A pointer to the previous node in the list, making it a doubly-linked list.

### Constructor
The class features a parametrized constructor used to initialize a `Node` object with a specified value. It sets the `data` attribute to the given value and both the `next` and `prev` pointers to `nullptr`. This initialization creates a node with no previous or next connections.


## Doubly Linked-List Class Methods

### `DoublyLinkedList()`

- **Description:** Initializes an empty doubly linked list.

### `~DoublyLinkedList()`

- **Description:** Destructor to release memory used by the doubly linked list. It deletes all nodes.

### `void Print_With_While()`

- **Description:** Prints the elements of the doubly linked list using a while loop.

### `void Print_With_For()`

- **Description:** Prints the elements of the doubly linked list using a for loop.

### `void Insert_Back(int value)`

- **Description:** Inserts a new node with the specified value at the back of the doubly linked list.

### `void Insert_Front(int value)`

- **Description:** Inserts a new node with the specified value at the front of the doubly linked list.

### `void Insert_Position(int index, int value)`

- **Description:** Inserts a new node with the specified value at the given index within the doubly linked list.

### `int Get_Nth_Element(int index)`

- **Description:** Returns the value of the Nth element (1-based) from the doubly linked list.

### `Node *Get_Nth_Node(int index)`

- **Description:** Returns the Nth node (1-based) from the doubly linked list.

### `int Search(int value)`

- **Description:** Searches for a value in the doubly linked list and returns its position (1-based) or -1 if not found.

### `int Improved_Search(int value)`

- **Description:** Searches for a value in the doubly linked list and swaps it with the previous node's value if found, returning the new position (1-based) or -1 if not found.

### `void Delete_Node(int index)`

- **Description:** Deletes a specific node (1-based) from the doubly linked list.

### `bool Is_Exist(int value)`

- **Description:** Checks if a value exists in the doubly linked list and returns `true` if found, `false` otherwise.

### `bool Is_Empty()`

- **Description:** Checks if the doubly linked list is empty and returns `true` if it is, `false` otherwise.

### `int Get_Length()`

- **Description:** Returns the length of the doubly linked list.

### `Node *Get_Head()`

- **Description:** Returns the head node of the doubly linked list.

### `Node *Get_Tail()`

- **Description:** Returns the tail node of the doubly linked list.

## Differences Between Singly and Doubly Linked Lists

The primary difference between singly and doubly linked lists lies in the structure of the nodes. While singly linked lists have a single "next" pointer, doubly linked lists have both "next" and "prev" pointers. This additional "prev" pointer in a doubly linked list allows for bidirectional traversal, making it more flexible for certain applications.

Some key differences between the two types of linked lists include:

1. **Traversal:** Singly linked lists only support forward traversal, while doubly linked lists enable both forward and backward traversal.

2. **Insertion and Deletion:** Doubly linked lists are generally more efficient for insertions and deletions at arbitrary positions, as they do not require traversing the list from the beginning.

3. **Memory Usage:** Doubly linked lists consume slightly more memory due to the additional "prev" pointers.

4. **Complexity:** Singly linked lists are simpler in terms of implementation and memory usage, but they may be less efficient for certain operations.

Both singly and doubly linked lists have their own advantages and use cases. The choice between them depends on the specific requirements of the application or problem being solved.


## Real-Life Scenarios

In the following scenarios, singly linked lists are used for specific purposes:

### Music Player Playlist Management

Music player applications like Spotify and Apple Music often use doubly linked lists to manage playlists. Each song is represented as a node in the list, with the "next" pointer pointing to the next song and the "prev" pointer pointing to the previous song. This bidirectional navigation allows users to easily skip to the next or previous track in a playlist. It also facilitates features like shuffle and repeat, where songs can be played in a random order or looped through the playlist.

### Task Management and To-Do Lists

Task management and to-do list applications, such as Todoist and Microsoft To Do, utilize doubly linked lists to organize tasks and activities. Each task is a node in the list, and users can move forward and backward through their task list using the "next" and "prev" pointers. This structure enables efficient task prioritization and reordering, as well as the ability to quickly mark tasks as completed or incomplete. Users can also insert new tasks at any position within the list, making it easy to manage and update their to-do lists.


## Example Usage

In the `main` function, there are various examples of how to use the `DoublyLinkedList` class. You can create a doubly linked list, insert elements, perform various operations, and retrieve information about the doubly linked list.