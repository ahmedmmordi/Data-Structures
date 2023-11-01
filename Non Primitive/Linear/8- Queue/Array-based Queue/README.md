# Array-Based Queue Class

The `Queue` class is an array-based implementation of a circular queue data structure. It allows you to efficiently store and manage a collection of integer elements, following the First-In-First-Out (FIFO) principle.

## Class Members

### `Queue()`

- **Description:** Default constructor. Initializes an empty queue with a default capacity of 10.

### `Queue(int given_capacity)`

- **Description:** Parameterized constructor. Constructs a queue with the given capacity. If the provided capacity is less than or equal to 0, it will be set to 1.

### `~Queue()`

- **Description:** Destructor. Releases the memory used by the queue when the object is destroyed.

### `void Print()`

- **Description:** Prints the elements in the queue, maintaining the order in which they were enqueued.

### `bool Is_Empty()`

- **Description:** Checks if the queue is empty and returns `true` if it is, `false` otherwise.

### `bool Is_Full()`

- **Description:** Checks if the queue is full and returns `true` if it is, `false` otherwise.

### `void Enqueue(int value)`

- **Description:** Adds an element to the rear of the queue, expanding the capacity if necessary. Enqueued elements follow the FIFO order.

### `int Dequeue()`

- **Description:** Removes and returns the element from the front of the queue. The dequeued element is no longer in the queue.

### `int Get_Front()`

- **Description:** Returns the element at the front of the queue without removing it.

### `int Get_Rear()`

- **Description:** Returns the last element of the queue without removing it.

### `int Get_Size()`

- **Description:** Returns the current size of the queue, indicating the number of elements in it.

### `int Get_Capacity()`

- **Description:** Returns the maximum capacity of the queue, which is the total number of elements it can hold.

## Circular Queue Implementation

The `Queue` class utilizes a circular array internally to efficiently manage the elements in the queue. This internal mechanism ensures optimal memory utilization and allows for the circular behavior of the queue. Here's how it works internally:

### Circular Array Operation

1. **Initialization:**
   - The circular queue begins with the creation of an integer array to hold the elements. The array's size is determined by the specified capacity, with a default capacity of 10 if none is provided.

2. **Indices Management:**
   - Two indices, `front` and `rear`, are used to keep track of the front and rear elements in the circular queue. Initially, both indices are set to -1.

3. **Enqueue Operation:**
   - When an element is enqueued, it is added to the position indicated by the `rear` index.
   - The `rear` index is then updated to point to the next position in the circular array. If the end of the array is reached, the indices wrap around to the beginning using the modulus operation, creating a circular effect.

4. **Dequeue Operation:**
   - When an element is dequeued, it is removed from the position indicated by the `front` index.
   - The `front` index is then updated to point to the next position in the circular array. Similarly, if the end is reached, the indices wrap around to the beginning to maintain the circular behavior.

5. **Memory Utilization:**
   - By using a circular array with wrapping indices, the circular queue achieves efficient memory utilization. Elements can be added and removed without needing to shift the entire array, making it suitable for scenarios where elements are frequently added or removed in a FIFO manner.

The circular array mechanism ensures that the `Queue` class efficiently manages elements in a circular manner while preserving the FIFO (First-In-First-Out) order. This design is especially useful when you have limited memory resources and need to optimize memory usage.

## Example Usage

In the `main` function, you can see various examples of how to use the `Queue` class. You can create a queue, enqueue elements, dequeue elements, check its status, and print its contents while maintaining the FIFO order.