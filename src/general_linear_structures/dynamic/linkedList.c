/**
 * @file linkedList.c
 * @author Gabriel Field
 * @brief Datas: Linked list
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "linkedList.h"



/* SECTION: byte linked list */

// This is attempt 1 at the implementation...
// ByteLinkedList* newByteLinkedList(void) {
//     ByteLinkedList returnMe = { .head = NULL };
//     return &returnMe; // ERROR: returns address of local variable!!
// }

ByteLinkedList* newByteLinkedList(void) {
    ByteLinkedList* returnMe = malloc(sizeof(ByteLinkedList) * 1);
    returnMe->head = NULL;
    return returnMe;
}

void killByteLinkedList(ByteLinkedList* me) {
    if (me == NULL) {
        free(me);
        return;
    }
    killByteLinkedListNode(me->head);
    free(me);
}

// This is attempt 1 at the implementation...
// ByteLinkedListNode* newByteLinkedListNode(uint8_t data) {
//     ByteLinkedListNode returnMe = { .data = data, .next = NULL };
//     return &returnMe; // ERROR: returns address of local variable!!
// }

ByteLinkedListNode* newByteLinkedListNode(uint8_t data) {
    ByteLinkedListNode* returnMe = malloc(sizeof(ByteLinkedListNode) * 1);
    returnMe->data = data;
    returnMe->next = NULL;
    return returnMe;
}

void killByteLinkedListNode(ByteLinkedListNode* me) {
    // I don't have access to a Stack data structure yet, so this is implemented by recursion.
    // The recursion eats up
    //  # Math: \Theta(\text{length of stuff downstream from } \texttt{me})
    //  space on the call stack.
    if (me == NULL) {
        free(me);
        return;
    }
    killByteLinkedListNode(me->next);
    free(me);
}

uint32_t byteLinkedListLength(ByteLinkedList* ofThis) {
    ByteLinkedListNode* pLocation = (*ofThis).head;
    uint32_t length = 0;
    while (pLocation != NULL) {
        length++;
        pLocation = (*pLocation).next;
    }
    return length;
}

uint8_t byteLinkedListGet(ByteLinkedList* fromHere, uint32_t atThisIndex) {
    ByteLinkedListNode* pLocation = (*fromHere).head;
    uint32_t index = 0;
    while (index < atThisIndex) {
        index++;
        pLocation = (*pLocation).next;
    }
    return (*pLocation).data;
}

void byteLinkedListSet(ByteLinkedList* inHere, uint32_t atThisIndex, uint8_t toThis) {
    ByteLinkedListNode* pLocation = (*inHere).head;
    uint32_t index = 0;
    while (index < atThisIndex) {
        index++;
        pLocation = (*pLocation).next;
    }
    (*pLocation).data = toThis;
}

void byteLinkedListPrepend(ByteLinkedList* toThis, ByteLinkedListNode* thisNode) {
    (*thisNode).next = (*toThis).head;
    (*toThis).head = thisNode;
}

void byteLinkedListInsert(ByteLinkedList* inHere, uint32_t afterThisIndex, ByteLinkedListNode* thisNode) {
    ByteLinkedListNode* pLocation = (*inHere).head;
    uint32_t index = 0;
    while (index < afterThisIndex)
    //  invariant: 0 <= index <= afterThisIndex
    //  invariant: `pLocation` points to index `index` in `inHere`
    //  decreases: afterThisIndex - index
    {
        index++;
        pLocation = (*pLocation).next;
    }
    (*thisNode).next = (*pLocation).next;
    (*pLocation).next = thisNode;
}



/* SECTION: generic linked list */

LinkedList* newLinkedList(void) {
    LinkedList* returnMe = malloc(sizeof(LinkedList) * 1);
    returnMe->head = NULL; // NOTE: This NEEDS to be here for killLinkedList(). Otherwise, it might try to free un-allocated memory.
    return returnMe;
}

void killLinkedList(LinkedList* me) {
    free(me->head);
    free(me);
}

LinkedListNode* newLinkedListNode(void* pData) {
    LinkedListNode* returnMe = malloc(sizeof(LinkedListNode) * 1);
    returnMe->data = pData;
    returnMe->next = NULL;
    return returnMe;
}

void killLinkedListNode(LinkedListNode* me) {
    // I don't have access to a Stack data structure yet, so this is implemented by recursion.
    // The recursion eats up
    //  # Math: \Theta(\text{length of stuff downstream from } \texttt{me})
    //  space on the call stack.
    if (me == NULL) {
        free(me);
        return;
    }
    killLinkedListNode(me->next);
    free(me->data);
    free(me);
}

uint32_t linkedListLength(LinkedList* ofThis) {
    LinkedListNode* pLocation = (*ofThis).head;
    uint32_t length = 0;
    while (pLocation != NULL) {
        length++;
        pLocation = (*pLocation).next;
    }
    return length;
}

void* linkedListGet(LinkedList* fromHere, uint32_t atThisIndex) {
    LinkedListNode* pLocation = (*fromHere).head;
    uint32_t index = 0;
    while (index < atThisIndex) {
        index++;
        pLocation = (*pLocation).next;
    }
    return (*pLocation).data;
}

void linkedListSet(LinkedList* inHere, uint32_t atThisIndex, void* toThis) {
    LinkedListNode* pLocation = (*inHere).head;
    uint32_t index = 0;
    while (index < atThisIndex) {
        index++;
        pLocation = (*pLocation).next;
    }
    free(pLocation->data); // NOTE: Freed
    (*pLocation).data = toThis;
}

void linkedListPrepend(LinkedList* toThis, LinkedListNode* thisNode) {
    (*thisNode).next = (*toThis).head;
    (*toThis).head = thisNode;
}

void linkedListInsert(LinkedList* inHere, uint32_t afterThisIndex, LinkedListNode* thisNode) {
    LinkedListNode* pLocation = (*inHere).head;
    uint32_t index = 0;
    while (index < afterThisIndex)
    //  invariant: 0 <= index <= afterThisIndex
    //  invariant: `pLocation` points to index `index` in `inHere`
    //  decreases: afterThisIndex - index
    {
        index++;
        pLocation = (*pLocation).next;
    }
    (*thisNode).next = (*pLocation).next;
    (*pLocation).next = thisNode;
}
