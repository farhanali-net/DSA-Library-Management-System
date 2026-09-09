# DSA Library Management System

A beginner-friendly **Data Structures and Algorithms (DSA)** project written in C++.  
The project demonstrates how a **singly linked list** can be used to build a simple Library Management System.

## Features. 

- Add a new book
- Remove a book using its ISBN
- Search books by title or author
- Display all books
- Check out or return a book 
- Interactive console-based menu

## Data Structure Used

### Singly Linked List

Each book is stored in a `Book` node containing:

- `title`
- `author`
- `isbn`
- `isAvailable`
- Pointer to the next book

The linked list is used because books can be added and removed dynamically without requiring a fixed-size array.

## Algorithms / Operations

| Operation | Approach | Time Complexity |
|---|---|---:|
| Add Book | Traverse to the end and insert a node | O(n) |
| Remove Book | Linear search by ISBN and unlink node | O(n) |
| Search Book | Linear traversal with title/author matching | O(n) |
| Display Books | Traverse the complete list | O(n) |
| Check Out / Return | Linear search by ISBN and toggle status | O(n) |

## Project Structure

```text
DSA-Library-Management-System/
├── README.md
├── .gitignore
├── LICENSE
├── src/
│   └── library_management.cpp
├── tests/
│   └── sample_input.txt
└── docs/
    └── sample_output.txt
```

## Requirements

- C++ compiler supporting C++11 or later
- Terminal / Command Prompt

Tested conceptually with standard C++ features such as `iostream`, `string`, pointers, structs, and dynamic memory.

## How to Compile

Open a terminal in the project directory and run:

```bash
g++ -std=c++11 src/library_management.cpp -o library_management
```

## How to Run

### Windows

```bash
library_management.exe
```

### Linux / macOS

```bash
./library_management
```

## Sample Test

A sample sequence is provided in `tests/sample_input.txt`.  
Expected output is available in `docs/sample_output.txt`.

The sample demonstrates:

1. Adding two books
2. Displaying the books
3. Searching for a book
4. Checking out a book
5. Removing a book
6. Displaying the remaining book

## Learning Objectives

This project is designed to practice:

- Structures in C++
- Pointers
- Dynamic memory allocation
- Singly linked lists
- Traversal
- Insertion
- Deletion
- Linear searching
- Basic algorithmic complexity
- Menu-driven programming

## Future Improvements

Possible extensions include:

- Preventing duplicate ISBNs
- Separate `checkout` and `return` operations
- Sorting books by title or author
- Saving records to a file
- Loading records when the program starts
- Adding automated unit tests
- Replacing the raw linked-list implementation with a reusable class

## Academic Note

This repository is suitable as a beginner-level DSA academic project and portfolio demonstration. The implementation intentionally keeps the linked-list logic visible rather than hiding it behind the C++ Standard Library.

## License

This project is provided for educational and portfolio use. See `LICENSE`.
