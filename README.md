# C Vector Implementation

## Overview

This project implements a **dynamic array (vector)** in C, inspired by the C++ STL `vector`.  
It supports common vector operations such as insertion, deletion, access, and dynamic resizing.

The vector grows automatically when elements are added beyond its current capacity.

---

## Features / Functions

### Initialization

- `init(Vector *v)` — Initializes the vector with size 0 and capacity 1.

### Element Insertion

- `push_back(Vector *v, int value)` — Adds an element at the end, doubling capacity if needed.
- `insert(Vector *v, int position, int value)` — Inserts an element at a specified index.

### Element Removal

- `pop_back(Vector *v)` — Removes the last element.
- `erase(Vector *v, int position)` — Removes the element at a specific index.

### Access

- `int at(Vector *v, int position)` — Returns the element at the given index.
- `int front(Vector *v)` — Returns the first element.
- `int back(Vector *v)` — Returns the last element.

### Properties

- `int size(Vector *v)` — Returns the number of elements.
- `int capacity(Vector *v)` — Returns the current capacity.
- `int empty(Vector *v)` — Returns 1 if empty, 0 otherwise.

### Memory Management

- `clear(Vector *v)` — Resets the vector size to 0 (keeps allocated memory).
- `destroy(Vector *v)` — Frees allocated memory and resets size and capacity.

### Utility

- `display(Vector *v)` — Prints all elements of the vector.

---

## Implementation Details

- **Dynamic resizing**: When `size == capacity`, the vector doubles its capacity using `realloc`.
- **Memory handling**: `clear` keeps the allocated memory for faster reuse, while `destroy` frees all memory.
- **Safety checks**: Functions check for invalid positions and handle empty vectors gracefully.

---

## Author

**Biswajeet Sahoo**  
[GitHub Repository](https://github.com/bixuuu4u/C-VECTOR-SEP-2025.git)
