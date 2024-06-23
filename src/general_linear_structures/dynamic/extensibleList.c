/**
 * @file extensibleList.c
 * @author Gabriel Field
 * @brief Datas: Extensible list
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "extensibleList.h"
#include "../../helpful.h"



/* SECTION: byte extensible list */

uint8_t byteExtensibleListValid(ByteExtensibleList* this) 
// ATTENTION: I can't actually check this properly. I'd need more serious tooling for that.
{
    return  this->size < this->capacity;
}

ByteExtensibleList* newByteExtensibleList(uint32_t capacity) {
    ByteExtensibleList* this = malloc(sizeof(ByteExtensibleList));
    this->size = 0;
    this->capacity = capacity;
    this->array = malloc(sizeof(uint8_t) * capacity);
    return this;
}

void killByteExtensibleList(ByteExtensibleList* me) {
    free(me->array);
    free(me);
}

uint8_t byteExtensibleListIsEmpty(ByteExtensibleList* this) {
    return this->size == 0;
}

uint32_t byteExtensibleListSize(ByteExtensibleList* ofThis) {
    return ofThis->size;
}

uint8_t byteExtensibleListGet(ByteExtensibleList* inHere, uint32_t atThisIndex) {
    return *(inHere->array + atThisIndex);
}

void byteExtensibleListSet(ByteExtensibleList* inHere, uint32_t atThisIndex, uint8_t toThis) {
    *(inHere->array + atThisIndex) = toThis;
}

void byteExtensibleListResize(ByteExtensibleList* this) 
// Frees the old array, but doesn't free its elements (more relevant comment for ExtensibleList).
{
    uint8_t* builtDifferent = malloc(sizeof(uint8_t) * this->capacity * 2);
    for (uint32_t i = 0; i < this->size; i++) {
        *(builtDifferent + i) = *(this->array + i);
    }
    free(this->array);
    this->array = builtDifferent;
    this->capacity = 2 * this->capacity;
}

void byteExtensibleListAppend(ByteExtensibleList* inHere, uint8_t thisElement) {
    if (inHere->size == inHere->capacity) {
        byteExtensibleListResize(inHere);
    }
    *(inHere->array + inHere->size) = thisElement;
    (inHere->size)++;
}

uint8_t byteExtensibleListHead(ByteExtensibleList* ofThis) {
    return *(ofThis->array);
}

uint8_t byteExtensibleListTail(ByteExtensibleList* ofThis) {
    return *(ofThis->array + ofThis->size - 1);
}

void byteExtensibleListInsert(ByteExtensibleList* inHere, uint32_t atThisIndex, uint8_t thisElement) {
    if (inHere->size == inHere->capacity) {
        byteExtensibleListResize(inHere);
    }
    // Shuffle elements along
    for (uint32_t destination = inHere->size; destination >= atThisIndex + 1; destination--) {
        *(inHere->array + destination) = *(inHere->array - 1 + destination);
    }
    *(inHere->array + atThisIndex) = thisElement;
}



/* SECTION: generic extensible list */

uint8_t extensibleListValid(ExtensibleList* this) 
// ATTENTION: I can't actually check this properly. I'd need more serious tooling for that.
{
    return  this->size < this->capacity;
}

ExtensibleList* newExtensibleList(size_t cellSize, uint32_t capacity) {
    ExtensibleList* this = malloc(sizeof(ExtensibleList) * 1);
    this->cellSize = cellSize;
    this->size = 0;
    this->capacity = capacity;
    this->array = malloc(cellSize * capacity);
    return this;
}

void slayExtensibleList(ExtensibleList* queen) {
    for (uint32_t i = 0; i < queen->capacity; i++) {
        free(queen->array + i);
    }
    free(queen->array);
    free(queen);
}

void killExtensibleList(ExtensibleList* me) {
    free(me->array);
    free(me);
}

uint8_t extensibleListIsEmpty(ExtensibleList* this) {
    return this->size == 0;
}

uint32_t extensibleListSize(ExtensibleList* ofThis) {
    return ofThis->size;
}

void* extensibleListGet(ExtensibleList* inHere, uint32_t atThisIndex) {
    return inHere->array + inHere->cellSize * atThisIndex;
}

void extensibleListSet(ExtensibleList* inHere, uint32_t atThisIndex, void* toThis) {
    // Copy contents at the end of the pointer one byte at a time.
    uint8_t* pByteToOverride = inHere->array + inHere->cellSize * atThisIndex; // NOTE: Typecast (void*) --> (uint8_t*)
    uint8_t* pByteToOverrideWith = toThis; // NOTE: Typecast (void*) --> (uint8_t*)
    for (size_t byteNumber = 0; byteNumber < inHere->cellSize; byteNumber++) {
        *pByteToOverride = *pByteToOverride;
        pByteToOverride++;
        pByteToOverrideWith++;
    }
    
}

void extensibleListResize(ExtensibleList* this)
// Frees the old array, but doesn't free its elements.
{
    void* builtDifferent = malloc(this->cellSize * this->capacity * 2);
    // Copy elements one at a time, copying them byte by byte.
    uint8_t* pByteToOverride;
    uint8_t* pByteToOverrideWith;
    for (uint32_t i = 0; i < this->size; i++) {
        pByteToOverride = builtDifferent + this->cellSize * i; // NOTE: Typecast (void*) --> (uint8_t*)
        pByteToOverrideWith = this->array + this->cellSize * i; // NOTE: Typecast (void*) --> (uint8_t*)
        for (size_t byteNumber = 0; byteNumber < this->cellSize; byteNumber++) {
            *pByteToOverride = *pByteToOverrideWith;
            pByteToOverride++;
            pByteToOverrideWith++;
        }
    }
    free(this->array);
    this->array = builtDifferent;
    this->capacity = 2 * this->capacity;
}

void extensibleListAppend(ExtensibleList* inHere, void* thisElement) {
    if (inHere->size == inHere->capacity) {
        extensibleListResize(inHere);
    }
    (inHere->size)++;
    // Copy thisElement in, one byte at a time
    uint8_t* pByteToOverride = inHere->array + inHere->cellSize * inHere->size; // NOTE: Typecast (void*) --> (uint8_t*)
    uint8_t* pByteToOverrideWith = thisElement; // NOTE: Typecast (void*) --> (uint8_t*)
    for (size_t byteNumber = 0; byteNumber < inHere->cellSize; byteNumber++) {
        *pByteToOverride = *pByteToOverrideWith;
        pByteToOverride++;
        pByteToOverrideWith++;
    }
}

void* extensibleListHead(ExtensibleList* ofThis) {
    return ofThis->array;
}

void* extensibleListTail(ExtensibleList* ofThis) {
    return ofThis->array + ofThis->cellSize * (ofThis->size - 1);
}

void extensibleListInsert(ExtensibleList* inHere, uint32_t atThisIndex, void* thisElement) {
    if (inHere->size == inHere->capacity) {
        extensibleListResize(inHere);
    }
    // Shuffle elements along
    for (uint32_t destination = inHere->size; destination >= atThisIndex + 1; destination--) {
        copy(inHere->array + inHere->cellSize * (destination - 1),
             inHere->array + inHere->cellSize * destination,
             inHere->cellSize);
    }
    copy(thisElement,
         inHere->array + inHere->cellSize * atThisIndex,
         inHere->cellSize);
}
