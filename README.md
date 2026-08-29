# Dynamic-Stack-With-Array-Implementation. 

A generic, low-level implementation of a custom dynamic array (`clsDynamicArray`) and an array-based stack (`clsMyStackArr`) using C++ templates. This project demonstrates manual memory management, template metaprogramming, pointer manipulation, and Object-Oriented Design (OOD) principles without relying on standard sequence containers like `std::vector` or `std::stack`.

## 📌 Overview

This project provides a structural foundation for understanding dynamic memory allocation and fundamental data structures under the hood.

`clsDynamicArray<T>`: A resizable array class that manages dynamic heap allocations, array re-allocations, boundary checking, element insertion, deletion, and searching.

`clsMyStackArr<T>`: A Last-In, First-Out (LIFO) stack data structure built on top of clsDynamicArray<T>, showcasing code reusability via composition/wrapper architectural patterns.

## 🏗 Architecture & Design

The architecture is divided into two decoupled header layers:
    
    +-------------------------------------------------------+
    |                   clsMyStackArr<T>                   |
    |  (Adapter/Wrapper providing LIFO Stack Semantics)     |
    +-------------------------------------------------------+
                               |
                               | Aggregates / Uses
                               v
    +-------------------------------------------------------+
    |                  clsDynamicArray<T>                   |
    | (Low-Level Dynamic Memory & Allocation Controller)    |
    +-------------------------------------------------------+

1. Encapsulation & Protection: `clsDynamicArray` controls raw heap allocations (`new[]`, `delete[]`), insulating high-level containers from memory leak risks and pointer dangling.

2. Composition & Reusability: `clsMyStackArr` delegates continuous array operations directly to `clsDynamicArray`, adhering to DRY (Don't Repeat Yourself) design standards.

## ⚡ Core Operations

1. `clsDynamicArray<T>` Operations
   
   `Resize(size_t NewSize)`: 
   Re-allocates dynamic memory on the heap to fit the NewSize. Copies existing elements up to min(old_size, new_size) into a newly allocated buffer and frees old memory.

   `InsertAt(size_t index, T Value)`: Expands the array buffer by 1, shifts elements right of index forward, and inserts Value at the target index.

   `InsertAtBeginning(T Value) / InsertAtEnd(T Value)`: 
Specialized insertion routines calling InsertAt at position 0 or position _Size.

   `InsertBefore(size_t index, T Value) / InsertAfter(size_t index, T Value)`: 
Helper methods that safely calculate boundary indices to insert relative to existing positions.

   `DeleteItemAt(int index)` :
Reduces array allocation by 1, copies left and right segments relative to index, and frees previous memory.

   `DeleteFirstItem() / DeleteLastItem()`: 
Delegates element deletion safely to DeleteItemAt using reusable index strategies.

   `Find(T Item)`: 
Executes a linear search O(N) through elements to locate Item and returns its zero-based index or -1 if absent.

   `DeleteItem(T Item)`: 
Finds the target element's index via Find() and removes it using DeleteItemAt().

   `Reverse()`:
Reverses array contents in-place with $O(N)$ time complexity using mirror-swapping (`swap(DynamicArray[i], DynamicArray[_Size - 1 - i])`).

   `Clear()` :
Deallocates heap memory, resets DynamicArray to nullptr, and clears array size to zero.


2. `clsMyStackArr<T>` Operations
    
   `push(T Item)`: Pushes an element to the top of the stack (position 0) via `InsertAtBeginning`.

   `pop()`: Removes the top element of the stack using `DeleteFirstItem`.

   `Top()`: Returns the top element without removing it. Returns a default-constructed `T()` if the stack is empty.

   `Size()`: Returns the current count of elements inside the stack.

   `IsEmpty()`: Returns `true` if stack contains zero elements; `false` otherwise.

   `Clear()`: Clears all stack data and deallocates memory buffer.

## 🎯 Key Concepts Demonstrated

Manual Heap Memory Management: Direct utilization of `new[]` and `delete[]` keywords without memory leaks.

Generic Programming (Templates): Implementation using `template <class T>` to allow type flexibility (supports primitives and user-defined objects).

RAII (Resource Acquisition Is Initialization): Automatic memory cleanup inside destructors (`~clsDynamicArray()`) to avoid dangling resources when object lifetime ends.

Pointer Arithmetic & Raw Array Manipulation: Explicit index handling and buffer swapping.

Code Reusability & Software Abstraction: Wrapping continuous container logic inside dedicated interfaces.

## 🛠 Technologies

anguage: C++ (C++11 or higher recommended)

Standard Library Components Used: `<iostream>`, `std::swap`, `std::min`

Paradigm: Object-Oriented Programming (OOP) & Generic Programming

## 👨‍🏫 Instructor

Dr. Mohammed Abu-Hadhoud
Founder & Instructor — Programming Advices

Programming Advices
https://programmingadvices.com
