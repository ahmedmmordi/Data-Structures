# 2D singly linked-list Class

This is a C++ implementation of a 2D singly linked list, `SLL2DArray`, representing a two-dimensional array. The class provides methods for creating, managing, and performing operations on a dynamically allocated 2D array using a singly linked list data structure.

## Class Methods

### `SLL2DArray(int rows, int cols)`

- **Description:** Initializes a 2D singly linked list with the specified number of rows and columns. It dynamically allocates memory and sets up the structure. Rows and columns must be non-negative values.

### `~SLL2DArray()`

- **Description:** Destructor that frees the dynamically allocated memory when the instance of the class is destroyed.

### `Assign(int row, int col, int value)`

- **Description:** Assigns a value to the specified location in the 2D array. It checks whether the row and column indices are valid before assignment.

### `Get_Size()`

- **Description:** Returns the total size of the 2D array, which is the product of the number of rows and columns.

### `Print()`

- **Description:** Prints the 2D array in a structured format, displaying the values in row-major order.

## Example Usage

In the `main` function, there are examples demonstrating the practical use of the `SLL2DArray` class. You can create a 2D array, assign values to specific locations, retrieve the size of the array, and print its contents.

**Note that:** there are tasks you can perform within the `main` function to explore the functionality of the `SLL2DArray` class.