# Linked-List-Based Stack Class

This is a C++ class, `Stack`, that represents a stack using a linked list. This class uses a private inner class, `Node`, to manage the elements in the stack. The class provides basic methods for stack operations.

### Node Class
The `Node` class is a private inner class within the `Stack`. It is used to represent individual elements in the stack. The `Node` class has the following attributes:

- `int data`: This attribute stores the data associated with the node.
- `Node *next`: A pointer to the next node in the stack.

The `Node` class features a constructor to initialize a node with a specified value. It sets the `data` attribute to the given value and the `next` pointer to `nullptr`, indicating that there is no next node initially.

### Stack Attributes
- `Node *top`: This attribute is a pointer to the top node in the stack, representing the most recently added element.
- `int length`: It keeps track of the number of elements in the stack.

The stack class is designed to manage a last-in, first-out (LIFO) collection of elements, making it suitable for various applications where this data structure is needed.

## Stack Class Methods

### `Stack()`

- **Description:** Initializes an empty stack.

### `void Push(int value)`

- **Description:** Pushes a new element onto the top of the stack.

### `int Pop()`

- **Description:** Pops and returns the top element from the stack. Throws an error if the stack is empty.

### `void Print()`

- **Description:** Prints the elements in the stack from top to bottom.

### `int Get_Length()`

- **Description:** Returns the number of elements in the stack.

### `int Get_Top()`

- **Description:** Returns the value of the top element in the stack without removing it. Throws an error if the stack is empty.

### `bool Is_Empty()`

- **Description:** Checks if the stack is empty and returns `true` if it is, `false` otherwise.

### `~Stack()`

- **Description:** Destructor for the stack, cleans up memory allocated for the stack.

## Usage
This class provides basic stack functionality, including pushing and popping elements, checking the size, and printing the elements.

If you have any specific modifications or additional details to include, please let me know.