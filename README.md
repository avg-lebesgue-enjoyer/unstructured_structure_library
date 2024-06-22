# unstructured_structure_library
have



# Purpose
This exists for me to:
- Understand how to implement and operate on data structures at a low level
- Practice writing in C
- Tick this off the *Computer Science student bucket list*
The tests I've written **are not rigorous**, because writing tests sucks all the joy out of programming.

This is being shared publically for others' benefit. **I encourage you to write something like this on your own before looking through mine.**



# Progress

### Data Structures

- [ ] General linear structures
    - [x] Static
        - [x] Array
    - [ ] Dynamic
        - [ ] Linked list
        - [ ] Extensible list
- [ ] Staques
    - [ ] Stack
    - [ ] Queues
        - [ ] Vanilla queue
        - [ ] Priority queue...
            - [ ] ...via extensible list
            - [ ] ...via heap
        - [ ] Adaptable priority queue (via heap)
- [ ] Trees
    - [ ] Bintrees
        - [ ] Vanilla bintree
        - [ ] Bin search trees (BSTs)
            - [ ] Vanilla BST
            - [ ] AVL tree
            - [ ] Splay tree (end me)
        - [ ] Heap
    - [ ] Vanilla tree *(arbitrary number of children)*
- [ ] Sets, maps and hashing
    - [ ] Map...
        - [ ] ...via hash table (hell yeah)
        - [ ] ...via (self-balancing) BST
    - [ ] Set
- [ ] Graphs
    - [ ] Edge list graph (?)
    - [ ] Adjacency list graph
    - [ ] Adjacency map graph
    - [ ] Adjacency matrix graph
    - [ ] A directed, weighted graph (I'll pick my favourite implementation to rip off)

### Algorithms

- [x] Search
    - [x] Linsearch
    - [x] Binsearch
- [ ] Sort
    - [ ] Comparison sort
        - [ ] Selection sort
        - [ ] Insertion sort
        - [ ] Merge sort
        - [ ] Quick sort (deterministic)
        - [ ] Heap sort...
            - [ ] ...via external data structure
            - [ ] ...via in-place heap
    - [ ] Non-comparison sort
        - [ ] Bucket sort
        - [ ] Lexicographic sort
        - [ ] Bin radix sort
- [ ] Heap methods
    - [ ] Upheap
    - [ ] Downheap
    - [ ] Bottom-up heap construction
    - [ ] Insert
    - [ ] Remove minimum
- [ ] BST methods
    - [ ] Vanilla BST methods
        - [ ] Insert
        - [ ] Remove
        - [ ] Overwrite
    - [ ] AVL tree methods
        - [ ] Rebalance
        - [ ] Tri-node restructuring
        - [ ] Insert
        - [ ] Remove
    - [ ] Splay tree methods
        - [ ] Splay
        - [ ] Insert
        - [ ] Remove
- [ ] Graph algos
    - [ ] DFS
    - [ ] BFS
    - [ ] Dijkstra's
    - [ ] Topological sort
    - [ ] Prim-Jarnik



# Changelog

### 2024-06-22_17-20
- Finished writing tests for a linked list of bytes.
- Updated [# Purpose](#purpose).
- `array.c ~> killArray()` and `array.c ~> killByteArray()` now exist.

### 2024-06-21_18-25
- Implemented a linked list of bytes, with SOME tests invoked by `> run linkedList.c`.
- I understand why object-oriented languages are pass-by-reference now! Pass-by-value **sucks ass**!
- I remembered to include "free all the memory pls" methods this time. I need to write one of those to clean up the arrays too...

### 2024-06-21_16-40
- Implemented binary search in `algos/search/binsearch.c`, with tests invoked by `> run binsearch.c`
- Added `array.c ~> arrayElementEquals()` (an alias for `array.c ~> compareArrayElement()`) and `array.c ~> arrayElementLess()`, because that second one *needs* abstracting and its name inspires a better name for `array.c ~> compareArrayElement()`.
- I understand lexicographic comparison better now. *Thank heavens* I'm not writing this in `asm`.

### 2024-06-21_00-50
- Implemented linear search in `algos/search/linsearch.c`, with tests invoked by `> run linsearch.c`
- Added `array.c ~> indexArray()` and `array.c ~> compareArrayElement()`, because that *needs* abstracting
- I understand pointer arithmetic, especially with `void*`s, much better now. Working at the low level is a pain in the ass... thank heavens I'm not writing this in `asm`.

### 2024-06-20_23-00
- Implemented an array in `general_linear_structures/static/array.c`, with tests
- Changed parameters to executable. Now, you give a list of names of files to be tested. For now, only an argument of `"array.c"` is supported, and it runs tests on the `ByteArray` and `Array` I implemented
- Actaully understood pointers a bit better

### 2024-06-20_21-10
- *Immediately* reduced the scope of [# Progress](#progress)

### 2024-06-20_20-40
- [# Progress](#progress) now exists. I'm afraid of setting my scope too large, so I might reduce it in the future (in particular, I might get rid of "stuff that just doesn't need to be here, really" like "map via unsorted list (ew)")
- `.gitignore` now exists (yes I'm stupid, no don't fire me)

### 2024-06-19_18-00
- `main.c` now exists
- `main.h` also exists, with rudimentary documentation
- I now understand how to structure files in subdirectories etc.
- Copied over `2023-10-14_13-00_Algos_Datas_Summary.pdf`
- Wtf is a makefile? ig I know now

### 2024-06-19_16-16
- Spawned in
