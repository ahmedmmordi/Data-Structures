# Vector Class

This is a simple C++ class, `Vector`, that represents a dynamic integer array. It provides a set of methods for various operations on the array. The class does not use templates and specifically uses `int` for practice.

## Class Methods

### `Vector()`

- **Description:** Initializes an empty vector with a default capacity of 10.

### `Vector(int size)`

- **Description:** Constructs a vector with the given size. If the size is negative, it is set to 1.

### `~Vector()`

- **Description:** Frees the memory used by the vector.

### `int Get_Size()`

- **Description:** Returns the size of the vector.

### `int Access(int index)`

- **Description:** Retrieves the element at the specified index.

### `void Set(int index, int value)`

- **Description:** Sets the value at the specified index.

### `void Push_Back(int value)`

- **Description:** Adds an element to the back of the vector, expanding the capacity if necessary.

### `void Push_Front(int value)`

- **Description:** Adds an element to the front of the vector, expanding the capacity if necessary.

### `void Insert_In(int index, int value)`

- **Description:** Inserts an element at the specified index, shifting existing elements to the right, and expanding the capacity if necessary.

### `int Delete_Position(int index)`

- **Description:** Deletes the element at the specified index and returns its value.

### `void Sort()`

- **Description:** Sorts the elements of the vector in ascending order.

### `void Reverse()`

- **Description:** Reverses the elements of the vector.

### `int Find(int value)`

- **Description:** Searches for a value in the vector and returns its index or -1 if not found.

### `int Improved_Find(int value)`

- **Description:** Searches for a value in the vector and moves it to the previous position if found, returning the new index or -1 if not found.

### `int Get_Front()`

- **Description:** Returns the first element of the vector.

### `int Get_Back()`

- **Description:** Returns the last element of the vector.

### `void Expand()`

- **Description:** Doubles the capacity of the vector by expanding its underlying array.

### `void Rotate_Right()`

- **Description:** Rotates the elements of the vector one position to the right.

### `void Rotate_Left()`

- **Description:** Rotates the elements of the vector one position to the left.

### `void Rotate_Right_Times(int times)`

- **Description:** Rotates the elements of the vector to the right by a specified number of times.

### `bool IsEmpty()`

- **Description:** Checks if the vector is empty and returns `true` if it is, `false` otherwise.

### `void Print()`

- **Description:** Prints the elements of the vector.

## Example Usage

In the `main` function, there are various examples of how to use the `Vector` class. You can create a vector, set elements, perform various operations, and print the results.