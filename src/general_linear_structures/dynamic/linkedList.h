#ifndef linkedList_H
#define linkedList_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Exported structures */

/** Singly linked list of bytes */
typedef struct ByteLinkedList {
    struct ByteLinkedListNode* head;   /** Pointer to head of this list */
} ByteLinkedList;

/** Node in a singly linked list of bytes */
typedef struct ByteLinkedListNode {
    uint8_t data;                      /** Byte stored at this node */
    struct ByteLinkedListNode* next;   /** Pointer to next node */
} ByteLinkedListNode; 



/** Singly linked list */
typedef struct LinkedList {
    struct LinkedListNode* head;       /** Pointer to head of this list */
} LinkedList;

/** Node in a singly linked list */
typedef struct LinkedListNode {
    void* data;                        /** Pointer to data stored at this node */
    struct LinkedListNode* next;       /** Pointer to next node */
} LinkedListNode;



/* SECTION: Function prototypes */

/**
 * @brief Construct a new, empty, singly linked list of bytes.
 * 
 * @return `ByteLinkedList*` to a fresh, empty, and singly linked list of bytes
 */
ByteLinkedList* newByteLinkedList(void);

/**
 * @brief Free ALL MEMORY used by a specified linked list of bytes.
 * 
 * @param me `ByteLinkedList*` to list to free. 
 *           MUST contain no loops.
 */
void killByteLinkedList(ByteLinkedList* me);

/**
 * @brief Construct a new node for a singly linked list of bytes, with prescribed data.
 *        Initially, point it nowhere.
 * 
 * @param data `uint8_t` to store.
 * @return `ByteLinkedListNode*` to a fresh node for a singly linked list of bytes, storing the prescribed `data`.
 */
ByteLinkedListNode* newByteLinkedListNode(uint8_t data);

/**
 * @brief Free ALL MEMORY used by a specified node in a linked list of bytes, including stuff pointed to.
 * 
 * @param me `ByteLinkedListNode*` to node to free.
 *           MUST not contain loops downstream.
 */
void killByteLinkedListNode(ByteLinkedListNode* me);

/**
 * @brief Find the length of a singly linked list of bytes.
 * 
 * @param ofThis `ByteLinkedList*` to list to find length of. MUST contain no loops, and MUST have length < 2^32 = 4294967296.
 * @return `uint32_t` length of the list.
 */
uint32_t byteLinkedListLength(ByteLinkedList* ofThis);

/**
 * @brief Get the byte stored at some index in a singly linked list of bytes.
 * 
 * @param fromHere `ByteLinkedList*` to list to to index into
 * @param atThisIndex `uint32_t` index to read from. MUST be <= byteLinkedListLength(fromHere).
 * @return `uint8_t` byte stored at the desired index
 */
uint8_t byteLinkedListGet(ByteLinkedList* fromHere, uint32_t atThisIndex);

/**
 * @brief Set the byte stored at some index in a singly linked list of bytes to a prescribed value.
 * 
 * @param inHere `ByteLinkedList*` to list to index into
 * @param atThisIndex `uint32_t` index to overwrite data for. MUST be <= byteLinkedListLength(fromHere).
 * @param toThis `uint8_t` to overwrite data with
 */
void byteLinkedListSet(ByteLinkedList* inHere, uint32_t atThisIndex, uint8_t toThis);

/**
 * @brief Prepend a node to a singly linked list of bytes
 * 
 * @param toThis `ByteLinkedList*` to list to prepend to
 * @param thisNode `ByteLinkedListNode*` to node to prepend
 */
void byteLinkedListPrepend(ByteLinkedList* toThis, ByteLinkedListNode* thisNode);

/**
 * @brief Insert a node into a singly linked list of bytes.
 *        ENSURES `new(index afterThisIndex) --> new(index afterThisIndex + 1) = thisNode --> old(index afterThisIndex + 1)`.
 * 
 * @param inHere `ByteLinkedList*` to list to insert into
 * @param atThisIndex `uint32_t` index at which to place the new node. MUST be <= byteLinkedListLength(inHere).
 * @param thisNode `ByteLinkedListNode*` to node to insert
 */
void byteLinkedListInsert(ByteLinkedList* inHere, uint32_t afterThisIndex, ByteLinkedListNode* thisNode);


// FIXME: Implement all methods past this point!
/**
 * @brief Construct a new, empty, singly linked list.
 * 
 * @return `LinkedList*`, fresh and empty.
 *         REMEMBER to `free()` this memory later!
 */
LinkedList* newLinkedList(void);

/**
 * @brief Free ALL MEMORY used by a specified linked list.
 * 
 * @param me `LinkedList*` to list to free. 
 *           MUST contain no loops.
 */
void killLinkedList(LinkedList* me);

/**
 * @brief Construct a new node for a singly linked list, with prescribed data.
 *        Initially, point it nowhere.
 * 
 * @param pData `void*` to data to store.
 * @return `LinkedListNode*` fresh node for a singly linked list, storing the prescribed `pData`.
 *         REMEMBER to `free()` this memory later!
 */
LinkedListNode* newLinkedListNode(void* pData);

/**
 * @brief Free ALL MEMORY used by a specified linked list node, including stuff pointed to.
 * 
 * @param me `LinkedListNode*` to node to free.
 *           MUST not contain loops downstream.
 */
void killLinkedListNode(LinkedListNode* me);

/**
 * @brief Find the length of a singly linked list.
 * 
 * @param ofThis `LinkedList*` to find length of. MUST contain no loops, and MUST have length < 2^32 = 4294967296.
 * @return `uint32_t` length of the list.
 */
uint32_t linkedListLength(LinkedList* ofThis);

/**
 * @brief Get a pointer to the data stored at some index in a singly linked list.
 * 
 * @param fromHere `LinkedList*` to index into
 * @param atThisIndex `uint32_t` index to read from. MUST be <= linkedListLength(fromHere).
 * @return `void*` to data stored at the desired index
 */
void* linkedListGet(LinkedList* fromHere, uint32_t atThisIndex);

/**
 * @brief Set the data pointed to at some index in a singly linked list to a prescribed pointer.
 * 
 * @param inHere `LinkedList*` to index into
 * @param atThisIndex `uint32_t` index to overwrite data for. MUST be <= linkedListLength(fromHere).
 * @param toThis `void*` to overwrite pointer with
 */
void linkedListSet(LinkedList* inHere, uint32_t atThisIndex, void* toThis);

/**
 * @brief Prepend a node to a singly linked list.
 * 
 * @param toThis `LinkedList*` to prepend to
 * @param thisNode `LinkedListNode*` to prepend
 */
void linkedListPrepend(LinkedList* toThis, LinkedListNode* thisNode);

/**
 * @brief Insert a node into a singly linked list.
 *        ENSURES `new(index atThisIndex) = thisNode --> old(index atThisIndex)`.
 * 
 * @param inHere `LinkedList*` to insert into
 * @param atThisIndex `uint32_t` index at which to place the new node. MUST be <= linkedListLength(inHere).
 * @param thisNode `LinkedListNode*` to insert
 */
void linkedListInsert(LinkedList* inHere, uint32_t atThisIndex, LinkedListNode* thisNode);



#endif