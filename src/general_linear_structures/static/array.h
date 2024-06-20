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
    uint32_t cellSize;  /** Size of each cell of the array. */
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
 * @brief Construct and return a new Array
 * 
 * @param length of the array to be constructed
 * @param cellSize of each cell, in bytes
 * @return Array filled with garbage values
 */
Array newArray(uint32_t length, uint32_t cellSize);

#endif