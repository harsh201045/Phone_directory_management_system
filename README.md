# Phone_directory Management System

The Contact Management System project is a user-friendly and console-based application developed in C & C++ using various data structures: Linked List, Binary Search Tree (BST), and Trie. This project enables users to efficiently store, retrieve, and manage contact information.

## Features

- **Add/Edit Contacts**: Easily add or edit contact information.
- **Search Contacts**: Search contacts using Name or Contact number.
- **Delete Contacts**: Remove contacts from the list.

## Data Structures Used

1. **Linked List**
   - A linear data structure where each element (node) points to the next, forming a sequence. It allows dynamic memory allocation and is suitable for scenarios where frequent insertion and deletion of contacts are required.

2. **Binary Search Tree (BST)**
   - A hierarchical data structure in which each node has at most two children referred to as the left child and the right child. BSTs enable efficient searching, insertion, and deletion operations, making them ideal for managing sorted contact information.

3. **Trie (Advanced Data Structure)**
   - A tree-like data structure used for storing a dynamic set of strings where the keys are usually strings. Tries are highly efficient for prefix-based searches, making them perfect for quickly searching contact names.

## Time Complexity

### Linked List

- **Add Contact**: O(n)
- **Delete Contact**: O(n)
- **Search Contact**: O(n)
- **Edit Contact**: O(n)

### Binary Search Tree (BST)

- **Add Contact**: O(log n) on average, O(n) in worst case
- **Delete Contact**: O(log n) on average, O(n) in worst case
- **Search Contact**: O(log n) on average, O(n) in worst case
- **Edit Contact**: O(log n) on average, O(n) in worst case

### Trie

- **Add Contact**: O(m), where m is the length of the contact name
- **Delete Contact**: O(m), where m is the length of the contact name
- **Search Contact**: O(m), where m is the length of the contact name
- **Edit Contact**: O(m), where m is the length of the contact name

## Requirements

- A C++ compiler (e.g., g++)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/harsh201045/contact-management-system.git
