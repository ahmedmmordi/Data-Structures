# Simple Binary Tree

This C++ program demonstrates the creation of a binary tree and implements three different traversal methods: Pre-Order, In-Order, and Post-Order. The tree is represented by the `Node` class, and the main function initializes a sample tree and prints its elements using the traversal methods.

## Node Class

### `Node`

- **Description:** Represents a node in a binary tree.
- **Attributes:**
  - `int data`: Holds the data value of the node.
  - `Node *left`: Points to the left child node.
  - `Node *right`: Points to the right child node.
- **Constructor:**
  - Initializes a node with the given value, setting left and right pointers to `nullptr`.

## Tree Traversal Methods

### `Print_PreOrder(Node *current)`

- **Description:** This function performs Pre-Order traversal on a binary tree. In Pre-Order traversal, the order of operations is as follows:
  1. Visit the current node (`current`).
  2. Recursively traverse the left subtree.
  3. Recursively traverse the right subtree.

- **Parameters:**
  - `Node *current`: The current node in the traversal. It represents the root of the current subtree.

### `Print_InOrder(Node *current)`

- **Description:** This function performs In-Order traversal on a binary tree. In In-Order traversal, the order of operations is as follows:
  1. Recursively traverse the left subtree.
  2. Visit the current node (`current`).
  3. Recursively traverse the right subtree.

- **Parameters:**
  - `Node *current`: The current node in the traversal. It represents the root of the current subtree.

### `Print_PostOrder(Node *current)`

- **Description:** This function performs Post-Order traversal on a binary tree. In Post-Order traversal, the order of operations is as follows:
  1. Recursively traverse the left subtree.
  2. Recursively traverse the right subtree.
  3. Visit the current node (`current`).

- **Parameters:**
  - `Node *current`: The current node in the traversal. It represents the root of the current subtree.

In each of these traversal methods, the recursive nature of the algorithms ensures that every node in the tree is visited exactly once. The difference lies in the order in which the nodes are visited. Pre-Order, In-Order, and Post-Order traversals have different applications depending on the problem at hand.


## Example Usage

In the `main` function, a binary tree is created with sample data. The program then prints the tree elements using the three traversal methods.

```cpp
// Sample Tree

           Root
          /    \
        Left  Right


           Root
   Left     1      Right
           / \
          2   3
           \   \
            4   5
               / \
              7   6

// Not actual code, for illustrative purposes to show node connections.
Root = Node(1);
Node(1)->left = Node(2);
Node(1)->right = Node(3);
Node(2)->right = Node(4);
Node(3)->right = Node(5);
Node(5)->right = Node(6);
Node(5)->left = Node(7);
```
Attempt to independently illustrate the diagram on paper and traverse it using each of the three methods: in-order, pre-order, and post-order, to gain a deeper understanding of the subject matter.