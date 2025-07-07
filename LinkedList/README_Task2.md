# Doubly Linked List Operations – C++ Implementation

This project implements a custom **Doubly Linked List** class in C++ with various operations including insertion, deletion, display, and duplicate removal.

## File

- `DLL.cpp` — Contains the complete implementation of a doubly linked list with multiple test cases in the `main()` function.

## Features Implemented

### Insertion Operations:
- `insertAtFirst(int val)` — Insert a node at the beginning.
- `insertAtLast(int val)` — Insert a node at the end.
- `insertAtPosition(int val, int pos)` — Insert a node at a specific position.

### Deletion Operations:
- `deleteAtFirst()` — Delete the first node.
- `deleteAtLast()` — Delete the last node.
- `deleteAtPosition(int pos)` — Delete a node at a specific position.

### Other Operations:
- `display()` — Print the list from head to tail.
- `removeDuplicates()` — Remove duplicate values from the list.

## Sample Output Flow

```cpp
Original List:
1
2
3
2
4

List after removing duplicates:
1
2
3
4

List after inserting at position 2:
1
5
2
3
4

List after deleting at the first position:
5
2
3
4

List after deleting at the last position:
5
2
3

List after deleting at position 2:
5
3
```

## Notes

- The implementation uses raw pointers (no STL).
- Error handling is minimal — assumes valid input positions.
- The list maintains proper `next` and `prev` links throughout.

## Author

Faizan Aziz
