# Dynamic-Stack-With-Array-Implementation

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

   
