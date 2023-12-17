# Simple Binary Search Tree

## Overview
This C++ project provides a straightforward implementation of a Binary Search Tree (BST). It includes a `BinarySearchTree` class that supports essential operations such as insertion, searching, deleting, traversal, and more.

# BinarySearchTree Class

## Helper Functions Usage

### `PrintDFS_Helper(Node *Root)`
- **Usage:** Assists the `PrintDFS` function in performing an In-Order traversal.
- **How:** Recursively traverses the left subtree, visits the current node, and then recursively traverses the right subtree. This ensures the elements are printed in ascending order.

### `InsertHelper(Node *Root, int value)`
- **Usage:** Assists the `Insert` function in finding the correct node for new element insertion.
- **How:** Compares the value to be inserted with the current node's value. If the value is less, it traverses the left subtree; if greater, it traverses the right subtree. When a suitable null position is found, it inserts the new node.

### `SearchHelper(Node *Root, int value)`
- **Usage:** Assists the `Search` function in finding an element with a specified value.
- **How:** Recursively traverses the tree based on the comparison of values. If the value is found, it returns `true`; otherwise, it returns `false`.

### `ClearAll_Helper(Node *Root)`
- **Usage:** Assists the `ClearAll` function in clearing all elements from the BST.
- **How:** Recursively deletes each node in a post-order traversal, starting from the leaves and moving up to the root.

### `DeleteLeaf_Helper(Node *&Root, int value)`
- **Usage:** Assists the `DeleteLeaf` function in deleting a specific leaf node with a given value.
- **How:** Recursively traverses the tree until the target leaf node is found. Once found, it deletes the node and sets the parent's link to `nullptr`.

These helper functions contribute to code readability, maintainability, and the prevention of code redundancy. They encapsulate specific functionalities, making the main functions more focused and concise. The modular design facilitates easier debugging and modification of individual components without affecting the entire implementation.

## The public and main functions in the class
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
- **Description:** This function inserts a new element with the given value into the BST, maintaining the order of the tree.
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

### `DeleteLeaf(int value)`
- **Description:** This function deletes a specific leaf node with the given value from the BST.
- **Parameters:**
  - `int value`: The value of the node to be deleted.

## Conclusion
The Binary Search Tree (BST) serves as a versatile and efficient data structure for organizing and managing elements. The `BinarySearchTree` class, equipped with essential functions, offers a straightforward approach to insertion, searching, deletion, traversal, and more.