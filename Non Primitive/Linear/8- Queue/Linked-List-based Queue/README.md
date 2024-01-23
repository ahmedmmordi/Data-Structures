# Linked-List-Based Queue Class

This is a C++ class, `Queue`, that represents a queue using a linked list. This class uses a private inner class, `Node`, to manage the elements in the queue. The class provides basic methods for queue operations.

## Node Class

The `Node` class is a private inner class within the `Queue`. It is used to represent individual elements in the queue. The `Node` class has the following attributes:

- `int data`: This attribute stores the data associated with the node.
- `Node *next`: A pointer to the next node in the queue.

The `Node` class features a constructor to initialize a node with a specified value. It sets the `data` attribute to the given value and the `next` pointer to `nullptr`, indicating that there is no next node initially.

## Queue Attributes

- `Node *Front`: This attribute is a pointer to the front (first) node in the queue, representing the element to be dequeued.
- `Node *Rear`: It is a pointer to the rear (last) node in the queue, representing the element most recently enqueued.
- `int size`: It keeps track of the number of elements in the queue.

The queue class is designed to manage a first-in, first-out (FIFO) collection of elements, making it suitable for various applications where this data structure is needed.


## Class Methods

### `Queue()`
- **Description:** Initializes an empty queue.

### `~Queue()`
- **Description:** Destructor for the queue, cleans up memory allocated for the queue.

### `void Enqueue(int value)`
- **Description:** Adds an element to the back of the queue.

### `void Dequeue()`
- **Description:** Removes the first (front) element from the queue.

### `int GetFront()`
- **Description:** Returns the value of the front element in the queue.

### `int GetBack()`
- **Description:** Returns the value of the back element in the queue.

### `bool IsExist(int value)`
- **Description:** Checks if the specified value exists in the queue and returns `true` if it is found, `false` otherwise.

### `bool IsEmpty()`
- **Description:** Checks if the queue is empty and returns `true` if it is, `false` otherwise.

### `int Size()`
- **Description:** Returns the current size of the queue.

### `void Print()`
- **Description:** Prints the elements of the queue.

### `void Clear()`
- **Description:** Removes all elements from the queue.

## Example Usage

In the `main` function, you can find various examples demonstrating how to use the `Queue` class. You can create a queue, enqueue elements, dequeue elements, check the front and back elements, check if the queue is empty, get the current size, print the elements, and clear the queue.

These examples will help you understand how to work with the `Queue` class and leverage its functionality for your applications.