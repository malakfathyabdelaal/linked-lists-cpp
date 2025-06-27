# linked-lists-cpp
Two C++ programs demonstrating singly and doubly linked lists with rich operations.
# Linked Lists in C++ 🔗

This project includes two separate C++ programs demonstrating both **singly** and **doubly** linked list operations. Each task focuses on a different data type and use case.

---

## 📁 Files Included

- `task1.cpp` — Singly linked list for integer values
- `task2.cpp` — Doubly linked list for character/string manipulation

---

## 🔷 task1.cpp — Integer Singly Linked List

This program creates a singly linked list that:
- Inserts elements in **ascending order**
- Tracks **duplicate values** with a `ctr` counter
- Allows:
  - Displaying values
  - Displaying values in descending order
  - Deleting values
  - Removing the maximum element
  - Clearing the entire list
  - Generating the list from an array

### 🧪 Sample Behavior
```plaintext
Initial list: 1 1 2 2 3 7 7 7 10 15

Add 5:
Updated list: 1 1 2 2 3 5 7 7 7 10 15

Display descending: 15 10 7 7 7 5 3 2 2 1 1

Delete 7:
Updated list: 1 1 2 2 3 5 7 7 10 15

Remove Max:
Updated list: 1 1 2 2 3 5 7 7 10

Clear:
Updated list: (empty)
```

## task2.cpp — Character Doubly Linked List
This program builds and manages two doubly linked lists of characters. It allows:

Adding characters to the head or tail

Concatenating two lists

Deleting a character at a specific index

Extracting a substring from the list

Searching for a substring

Replacing one substring with another

🧪 Sample Behavior
plaintext
Copy
Edit
Input list1: hello
Input list2: world

Concatenated: helloworld

Delete character at index 4:
Result: hellworld

Substring (index 2, length 4): llwo

Search for "llo":
Found at index 2

Replace "ll" with "zz":
Result: hezzoworld
🛠️ Technologies Used
Language: C++

Data Structures:

Singly Linked List

Doubly Linked List

Core Concepts:

Pointer manipulation

Dynamic memory

Node linking and traversal

👩‍💻 Author
Malak Ali
Data Science Student | Tech Enthusiast

📌 How to Run
Open either task1.cpp or task2.cpp in a C++ IDE (e.g., Code::Blocks, VS Code).

Compile and run the code.

Follow console instructions for inputs and operations.

⭐ Highlights
Proper memory management (delete operations)

In-place substring search and replacement

Custom counter per node for duplicates

Both forward and reverse traversals

