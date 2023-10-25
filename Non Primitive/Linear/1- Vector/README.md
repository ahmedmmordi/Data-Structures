# Vector Class

The **Vector** class is a C++ template class that represents a dynamic array capable of storing elements of any data type. It offers a wide range of operations for managing and manipulating the elements within the array. This class allows you to create, modify, and work with dynamic arrays efficiently.

## Class Overview

The `Vector` class provides several essential methods for working with dynamic arrays:

### Constructors and Destructor

- **`Vector()`**
  - *Description:* Initializes an empty vector with a default capacity of 10.

- **`Vector(int size)`**
  - *Description:* Constructs a vector with the given size. If the size is negative, it is set to 1.

- **`~Vector()`**
  - *Description:* Frees the memory used by the vector.

### Access and Modification

- **`int Get_Size()`**
  - *Description:* Returns the size of the vector.

- **`T Access(int index)`**
  - *Description:* Retrieves the element at the specified index.

- **`void Set(int index, T value)`**
  - *Description:* Sets the value at the specified index.

### Adding and Removing Elements

- **`void Push_Back(T value)`**
  - *Description:* Adds an element to the back of the vector, expanding the capacity if necessary.

- **`void Push_Front(T value)`**
  - *Description:* Adds an element to the front of the vector, expanding the capacity if necessary.

- **`void Pop_Back()`**
  - *Description:* Removes the last element in the vector without deallocating memory.

- **`void Insert_In(int index, T value)`**
  - *Description:* Inserts an element at the specified index, shifting existing elements to the right, and expanding the capacity if necessary.

- **`T Delete_Position(int index)`**
  - *Description:* Deletes the element at the specified index and returns its value.

### Sorting and Reversing

- **`void Sort()`**
  - *Description:* Sorts the elements of the vector in ascending order.

- **`void Reverse()`**
  - *Description:* Reverses the elements of the vector.

### Searching and Manipulation

- **`int Find(T value)`**
  - *Description:* Searches for a value in the vector and returns its index or -1 if not found.

- **`int Improved_Find(T value)`**
  - *Description:* Searches for a value in the vector and moves it to the previous position if found, returning the new index or -1 if not found.

- **`T Get_Front()`**
  - *Description:* Returns the first element of the vector.

- **`T Get_Back()`**
  - *Description:* Returns the last element of the vector.

- **`void Expand()`**
  - *Description:* Doubles the capacity of the vector by expanding its underlying array.

- **`void Rotate_Right()`**
  - *Description:* Rotates the elements of the vector one position to the right.

- **`void Rotate_Left()`**
  - *Description:* Rotates the elements of the vector one position to the left.

- **`void Rotate_Right_Times(int times)`**
  - *Description:* Rotates the elements of the vector to the right by a specified number of times.

### Utility

- **`bool IsEmpty()`**
  - *Description:* Checks if the vector is empty and returns `true` if it is, `false` otherwise.

- **`void Print()`**
  - *Description:* Prints the elements of the vector.

## Example Usage

In the `main` function, you can find various examples of how to use the `Vector` class. You can create a vector, set elements, perform various operations, and print the results.

Feel free to use this versatile `Vector` class in your C++ projects to manage dynamic arrays with ease.
