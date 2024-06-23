/**
 * @file array.h
 * @author Gabriel Field
 * @brief 
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright just don't misuse my work pls
 * 
 */

// FIXME: We need memory-freeing methods for ByteArray and for Array.

#ifndef array_H
#define array_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Exported structures */

/** Array of bytes. */
typedef struct ByteArray {
    uint32_t length;    /** Length of the array. Going past this is a buffer overflow. */
    uint8_t* start;     /** Pointer to the zeroth cell of the array. */
} ByteArray;

/** (Probably very unsafe) array. */
typedef struct Array {
    uint32_t length;    /** Length of the array. Going past this is a buffer overflow. */
    size_t   cellSize;  /** Size of each cell of the array. */
    void*    start;     /** Pointer to the zeroth cell of the array. */
} Array;



/* SECTION: Function prototypes */

/**
 * @brief Construct and return a new ByteArray
 * 
 * @param length of the array to be constructed
 * @return ByteArray filled with garbage values
 */
ByteArray constructByteArray(uint32_t length);

/**
 * @brief Free ALL MEMORY used by a specified array of bytes.
 * 
 * @param me `ByteArray` to free.
 */
void killByteArray(ByteArray me);

/**
 * @brief Construct and return a new Array
 * 
 * @param length of the array to be constructed
 * @param cellSize of each cell, in bytes
 * @return Array filled with garbage values
 */
Array newArray(uint32_t length, size_t cellSize);

/**
 * @brief Free ALL MEMORY used by a specified array.
 * 
 * @param me `Array` to free.
 */
void killArray(Array me);


/**
 * @brief Index into an array
 * 
 * @param inHere Array in which to index
 * @param atHere uint32_t location in which to index. UNSAFE OPERATION when atHere >= inHere.length (just like normal indexing lol)
 * @return void* 
 */
void* indexArray(Array inHere, uint32_t atHere);

/**
 * @brief Check if an array, at some index, stores a value equal to a target value
 * 
 * @param inHere Array into which to index
 * @param atHere uint32_t index at which to look. UNSAFE OPERATION when atHere >= inHere.length (just like normal indexing lol)
 * @param againstThis void* to target value to check against. MUST be a pointer to inHere.cellSize bytes.
 * @return uint8_t 1 iff the target value is present at the specified index in the specified array; 0 else.
 */
uint8_t compareArrayElement(Array inHere, uint32_t atHere, void* againstThis);

/** Alias for `compareArrayElement()` (I didn't like that name). The compiler should figure out that this method is unnecessary, 
 *  so I'm fine with this "inefficiency". */
uint8_t arrayElementEquals(Array inHere, uint32_t atHere, void* againstThis);

/**
 * @brief Check if an array, at some index, stored a value less than a target value. Comparison is done as UNSIGNED INTEGERS.
 * 
 * @param inHere Array into which to index
 * @param atHere uint32_t index at which to look. UNSAFE OPERATION when atHere >= inHere.length (just like normal indexing lol)
 * @param againstThis void* to target value to check against. MUST be a pointer to inHere.cellSize bytes.
 * @return uint8_t 1 iff the value at the specified index in the specified array is less than the target value; 0 else.
 */
uint8_t arrayElementLess(Array inHere, uint32_t atHere, void* againstThis);

#endif