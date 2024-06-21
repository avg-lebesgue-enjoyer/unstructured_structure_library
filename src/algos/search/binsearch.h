#ifndef binsearch_H
#define binsearch_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string

#include "../../general_linear_structures/static/array.h"


/* SECTION: Function prototypes */

/**
 * @brief 
 * 
 * @param inHere ByteArray in which to search. MUST be sorted (as unsigned uint8_t values)
 * @param target uint8_t to find
 * @return uint32_t index in inHere at which target is found, or inHere.length if target is not in inHere
 */
uint32_t binsearchByte(ByteArray inHere, uint8_t target);

/**
 * @brief Linear search for a value
 * 
 * @param inHere Array in which to search. MUST be sorted
 * @param target void* to the thing we wish to find (we search for the value *target), which MUST occupy exactly inHere.cellSize bytes
 * @return uint32_t index in inHere at which the *target is found, or inHere.length if *target is not in inHere
 */
uint32_t binsearch(Array inHere, void* target);



#endif