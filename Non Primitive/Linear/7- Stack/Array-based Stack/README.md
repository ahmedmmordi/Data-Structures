# Array-Based Stack Class

This is a C++ class, `Stack`, that represents a stack using an array-based approach. The class is designed for managing a last-in, first-out (LIFO) collection of elements and provides essential methods for stack operations.

## Stack Class Overview

The `Stack` class includes the following attributes and methods:

### Stack Attributes

- `int *arr`: A dynamically allocated integer array that stores the stack elements.
- `int top`: Keeps track of the top element in the stack.
- `int capacity`: Represents the maximum capacity of the stack, which is set during initialization.

## Stack Methods

### `Stack(int size)`

- **Description:** Parameterized constructor for the `Stack` class. Initializes an empty stack with a specified size.

### `~Stack()`

- **Description:** Destructor for the stack, which releases the dynamically allocated memory.

### `void Push(int value)`

- **Description:** Pushes a new element onto the top of the stack. It checks if the stack is full before pushing.

### `int Pop()`

- **Description:** Pops and returns the top element from the stack. Throws an error if the stack is empty.

### `int Get_Top()`

- **Description:** Returns the value of the top element in the stack without removing it. Throws an error if the stack is empty.

### `int Get_Length()`

- **Description:** Returns the number of elements in the stack. The length is determined by the top index plus one, as it starts from a top value of -1.

### `bool Is_Full()`

- **Description:** Checks if the stack is full and returns `true` if it is, `false` otherwise.

### `bool Is_Empty()`

- **Description:** Checks if the stack is empty and returns `true` if it is, `false` otherwise.

### `void Print()`

- **Description:** Prints the elements in the stack from top to bottom.

## Usage

This class provides basic stack functionality for managing elements in a last-in, first-out manner. Users can create a stack with a specified size, push and pop elements, check the size of the stack, and print its contents.

If you have any specific modifications or additional details to include, please let me know.