# Simple Binary Search Tree

## Overview

This C++ project demonstrates the implementation of a Binary Search Tree (BST). The project includes a `BinarySearchTree` class that supports various operations such as insertion, searching, traversal, and more.

## `BinarySearchTree` Class

### `PrintDFS(Node *current)`

- **Description:** This function performs an In-Order traversal on the binary search tree (BST). In In-Order traversal, the order of operations is as follows:
  1. Recursively traverse the left subtree.
  2. Visit the current node (`current`).
  3. Recursively traverse the right subtree.

- **Parameters:**
  - `Node *current`: The current node in the traversal. It represents the root of the current subtree.

### `PrintBFS()`

- **Description:** This function prints the elements of the BST level by level using Breadth-First Search (BFS). BFS traverses the tree level by level, visiting all nodes at the current level before moving on to the next level.

- **Parameters:**
  - No additional parameters.

### `Insert(int value)`

- **Description:** This function inserts a new element with the given value into the BST. It finds the correct node for insertion by recursively traversing the tree based on the comparison of values.

- **Parameters:**
  - `int value`: The value to be inserted into the BST.

### `Search(int value)`

- **Description:** This function searches for an element with the specified value in the BST. It recursively traverses the tree, comparing values to find the desired element.

- **Parameters:**
  - `int value`: The value to search for in the BST.

### `Get_Min()`

- **Description:** This function returns the minimum element in the BST. It traverses the left child nodes until the leftmost node is reached.

- **Parameters:**
  - No additional parameters.

### `Get_Max()`

- **Description:** This function returns the maximum element in the BST. It traverses the right child nodes until the rightmost node is reached.

- **Parameters:**
  - No additional parameters.

### `Get_Size()`

- **Description:** This function returns the size (number of elements) of the BST.

- **Parameters:**
  - No additional parameters.

### `ClearAll()`

- **Description:** This function clears all elements from the BST by recursively deleting each node.

- **Parameters:**
  - No additional parameters.

### `IsEmpty()`

- **Description:** This function checks if the BST is empty by verifying whether the root node is `nullptr`.

- **Parameters:**
  - No additional parameters.

Feel free to use this formatted template for your README file, and customize it further based on your project's specifics.