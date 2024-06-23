#ifndef extensibleList_H
#define extensibleList_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Exported structures */

/**
 * @brief Extensible list (dynamic array) of bytes.
 *        Resizing scheme is doubling the capacity. I shouldn't hard code this, but eh it's fine.
 */
typedef struct ByteExtensibleList {
    uint32_t size;      /** Number of elements currently stored */
    uint32_t capacity;  /** Maximum number of elements to storable before a resize */
    uint8_t* array;     /** Elements currently stored */ // NOTE: I know this could be array.h's ByteArray. idc; this is nicer to me atm.
} ByteExtensibleList;



/**
 * @brief Extensible list (dynamic array).
 *        Resizing scheme is doubling the capacity. I shouldn't hard code this, but eh it's fine.
 */
typedef struct ExtensibleList {
    size_t   cellSize;  /** Size of each element stored */
    uint32_t size;      /** Number of elements currently stored */
    uint32_t capacity;  /** Maximum number of elements storable before a resize */
    void*    array;     /** Elements currently stored */ // NOTE: I know this could be array.h's Array. idc; this is nicer to me atm.
} ExtensibleList;



/* SECTION: Function prototypes */

/**
 * @brief Class invariant
 * 
 * @param this `ByteExtensibleList*` to test
 * @return uint8_t 1 iff `this` is valid; 0 else
 * 
 * @attention ENSURES `this->array` has length == `this->capacity`
 * @attention ENSURES `this->size <= this->capacity`
 */
uint8_t byteExtensibleListValid(ByteExtensibleList* this);

/**
 * @brief Construct a new, empty, extensible list of bytes.
 * 
 * @param capacity `uint32_t` initial capacity
 * @return `ByteExtensibleList*` to a fresh, empty, and extensible list of bytes
 */
ByteExtensibleList* newByteExtensibleList(uint32_t capacity);

/**
 * @brief Free ALL MEMORY used by a specified extensible list of bytes.
 * 
 * @param me `ByteExtensibleList*` to list to free.
 */
void killByteExtensibleList(ByteExtensibleList* me);

/**
 * @brief Check whether a ByteExtensibleList is empty.
 * 
 * @param this `ByteExtensibleList*` to list to test for emptiness inside
 * @return `uint8_t` 0 iff `this` is not empty 
 */
uint8_t byteExtensibleListIsEmpty(ByteExtensibleList* this);

/**
 * @brief Get current number of elements stored in a ByteExtensibleList.
 * 
 * @param ofThis `ByteExtensibleList*` to list to get length of
 * @return `uint32_t` length of list
 */
uint32_t byteExtensibleListSize(ByteExtensibleList* ofThis);

/**
 * @brief Retrieve the element at a specified index in a ByteExtensibleList.
 * 
 * @param inHere `ByteExtensibleList*` to ByteExtensibleList to index into.
 * @param atThisIndex `uint32_t` index to retrieve from
 * @return `uint8_t` element retrieved 
 */
uint8_t byteExtensibleListGet(ByteExtensibleList* inHere, uint32_t atThisIndex);

/**
 * @brief Overwrite the element at a specified index in a ByteExtensibleList with a prescribed value.
 * 
 * @param inHere `ByteExtensibleList*` to list to index into
 * @param atThisIndex `uint32_t` index of cell to overwrite
 * @param toThis  `uint8_t` to overwrite cell with
 */
void byteExtensibleListSet(ByteExtensibleList* inHere, uint32_t atThisIndex, uint8_t toThis);

/**
 * @brief Double the capacity of a ByteExtensibleList
 * 
 * @param this `ByteExtensibleList*` to list to resize
 * 
 * @attention REQUIRES `byteExtensibleListValid(this)`
 * @attention REQUIRES `2 * this->capacity <= uint32_t::MAX_VALUE`
 * @attention ENSURES `byteExtensibleListValid(this)`
 * @attention ENSURES `this->capacity == 2 * old(this->capacity)`
 * @attention ENSURES `this->size == old(this->size)`
 * @attention ENSURES `this->array[..this->size] == old(this->array[..this->size])`
 */
void byteExtensibleListResize(ByteExtensibleList* this);

/**
 * @brief Append a prescribed value to a ByteExtensibleList.
 * @brief O(1) amortised
 * 
 * @param inHere `ByteExtensibleList*` to list to append to
 * @param thisElement `uint8_t` element to append
 */
void byteExtensibleListAppend(ByteExtensibleList* inHere, uint8_t thisElement);

/**
 * @brief Get the first element in a ByteExtensibleList.
 * 
 * @param ofThis `ByteExtensibleList*` to list to retreive head of
 * @return uint8_t element stored at the head
 * 
 * @attention REQUIRES `this->size > 0`
 */
uint8_t byteExtensibleListHead(ByteExtensibleList* ofThis);

/**
 * @brief Get the last element in a ByteExtensibleList.
 * 
 * @param ofThis `ByteExtensibleList*` to list to retreive tail of
 * @return uint8_t element stored at the tail
 * 
 * @attention REQUIRES `this->size > 0`
 */
uint8_t byteExtensibleListTail(ByteExtensibleList* ofThis);

/**
 * @brief Insert an element to a ByteExtensibleList.
 * @brief amo. `O(inHere->size)`
 * 
 * @param inHere `ByteExtensibleList*` to list into which to insert
 * @param atThisIndex `uint32_t` index to insert element immediately before
 * @param thisElement `uint8_t` element to insert
 * 
 * @attention REQUIRES `byteExtensibleListValid(inHere)`
 * @attention REQUIRES `atThisIndex < inHere->size`
 * @attention ENSURES `inHere[..] == old(inHere[0 .. atThisIndex]) + [thisElement] + old(inHere[atThisIndex..])`
 * @warning Will break if `atThisIndex == uint32_t::MAX_VALUE`
 */
void byteExtensibleListInsert(ByteExtensibleList* inHere, uint32_t atThisIndex, uint8_t thisElement);



/**
 * @brief Class invariant
 * 
 * @param this `ExtensibleList*` to test
 * @return uint8_t 1 iff `this` is valid; 0 else
 * 
 * @attention ENSURES `this->array` has length == `(this->cellSize) * (this->capacity)`
 * @attention ENSURES `this->size <= this-> capacity`
 */
uint8_t extensibleListValid(ExtensibleList* this);

/**
 * @brief Construct a new, empty, extensible list.
 * 
 * @param cellSize `size_t` memory size occupied by each cell
 * @param capacity `uint32_t` initial capacity
 * @return `ExtensibleList*` to a fresh, empty, and extensible list
 */
ExtensibleList* newExtensibleList(size_t cellSize, uint32_t capacity);

/**
 * @brief Free ALL MEMORY used by a specified extensible list,
 *        including all elements stored within.
 * 
 * @param queen `ExtensibleList*` to list to free.
 */
void slayExtensibleList(ExtensibleList* queen);

/**
 * @brief Free memory used to STORE THE STRUCTURE of an extensible list,
 *        NOT including any elements stored within.
 * 
 * @param me `ExtensibleList*` to list to free.
 */
void killExtensibleList(ExtensibleList* me);

/**
 * @brief Check whether an ExtensibleList is empty.
 * 
 * @param this `ExtensibleList*` to list to test for emptiness inside
 * @return `uint8_t` 0 iff `this` is not empty 
 */
uint8_t extensibleListIsEmpty(ExtensibleList* this);

/**
 * @brief Get current number of elements stored in an ExtensibleList.
 * 
 * @param ofThis `ExtensibleList*` to list to get length of
 * @return `uint32_t` length of list
 */
uint32_t extensibleListSize(ExtensibleList* ofThis);

/**
 * @brief Retrieve the element at a specified index in an ExtensibleList.
 * 
 * @param inHere `ExtensibleList*` to ExtensibleList to index into.
 * @param atThisIndex `uint32_t` index to retrieve from
 * @return `void*` to element retrieved 
 */
void* extensibleListGet(ExtensibleList* inHere, uint32_t atThisIndex);

/**
 * @brief Overwrite the element at a specified index in an ExtensibleList with a prescribed value.
 * 
 * @param inHere `ExtensibleList*` to list to index into
 * @param atThisIndex `uint32_t` index of cell to overwrite
 * @param toThis `void*` to element to overwrite cell with
 */
void extensibleListSet(ExtensibleList* inHere, uint32_t atThisIndex, void* toThis);

/**
 * @brief Double the capacity of an ExtensibleList
 * 
 * @param this `ExtensibleList*` to list to resize
 * 
 * @attention REQUIRES `extensibleListValid(this)`
 * @attention REQUIRES `2 * this->capacity <= uint32_t::MAX_VALUE`
 * @attention REQUIRES `this->size == this->capacity` (to avoid memory leak!) // [1.]
 * @attention ENSURES `extensibleListValid(this)`
 * @attention ENSURES `this->capacity == 2 * old(this->capacity)`
 * @attention ENSURES `this->size == old(this->size)`
 * @attention ENSURES `this->array[..this->size] == old(this->array[..this->size])`
 * 
 * @warning Only call this method when `this->size == this->capacity`. Otherwise, this method call will cause a memory leak.
 */
void extensibleListResize(ExtensibleList* this);
// [1.] I think it's pretty cool that actually writing stuff into the contract can be used to guarantee
//      that there won't be a memory leak due to a (legal) method call. That's really sick.

/**
 * @brief Append a prescribed value to an ExtensibleList.
 * 
 * @param inHere `ExtensibleList*` to list to append to
 * @param thisElement `void*` element to append
 */
void extensibleListAppend(ExtensibleList* inHere, void* thisElement);

/**
 * @brief Get the first element in an ExtensibleList.
 * 
 * @param ofThis `ExtensibleList*` to list to retreive head of
 * @return void* to element stored at the head
 * 
 * @attention REQUIRES `this->size > 0`
 */
void* extensibleListHead(ExtensibleList* ofThis);

/**
 * @brief Get the last element in an ExtensibleList.
 * 
 * @param ofThis `ExtensibleList*` to list to retreive tail of
 * @return void* to element stored at the tail
 * 
 * @attention REQUIRES `this->size > 0`
 */
void* extensibleListTail(ExtensibleList* ofThis);

/**
 * @brief Insert an element to an ExtensibleList.
 * 
 * @param inHere `ExtensibleList*` to list into which to insert
 * @param atThisIndex `uint32_t` index to insert element immediately before
 * @param thisElement `void*` to element to insert
 * 
 * @attention REQUIRES `extensibleListValid(inHere)`
 * @attention REQUIRES `atThisIndex < inHere->size`
 * @attention ENSURES `inHere[..] == old(inHere[0 .. atThisIndex]) + [thisElement] + old(inHere[atThisIndex..])`
 * @warning Will break if `atThisIndex == uint32_t::MAX_VALUE`
 */
void extensibleListInsert(ExtensibleList* inHere, uint32_t atThisIndex, void* thisElement);



#endif