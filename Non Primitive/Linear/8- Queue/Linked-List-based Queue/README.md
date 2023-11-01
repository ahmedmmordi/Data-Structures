# Linked-List-Based Queue Class

The "Linked-List-Based Queue Class" is an implementation of a queue data structure that relies on a linked list as its underlying data structure. This class provides a convenient and efficient way to manage a queue of elements, allowing you to add elements to the back of the queue, remove elements from the front, and perform various operations on the elements within the queue.

## Note
This `Queue` class is implemented based on a linked list. It is essential to understand how linked lists work before using this class effectively. Linked lists are a data structure where each element (node) holds a value and a reference (or pointer) to the next element in the list. The `Queue` class takes advantage of this linked list structure to provide queue operations.

## Class Methods

### `void Enqueue(int value)`

- **Description:** Adds an element to the back of the queue.

### `void Dequeue()`

- **Description:** Removes the first (front) element from the queue.

### `int Get_Front()`

- **Description:** Returns the value of the front element in the queue.

### `int Get_Back()`

- **Description:** Returns the value of the back element in the queue.

### `bool Is_Empty()`

- **Description:** Checks if the queue is empty and returns `true` if it is, `false` otherwise.

### `int Get_Size()`

- **Description:** Returns the current size of the queue.

### `int Is_Exist(int value)`

- **Description:** Checks if a specific value exists in the queue and returns its index or -1 if not found.

### `void Print()`

- **Description:** Prints the elements of the queue.

## Example Usage

In the `main` function, you can find various examples demonstrating how to use the `Queue` class. You can create a queue, enqueue elements, dequeue elements, check the front and back elements, check if the queue is empty, get the current size, search for specific values, and print the elements.

These examples will help you understand how to work with the `Queue` class and leverage its functionality for your applications.