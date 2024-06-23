#ifndef helpful_H
#define helpful_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Function prototypes */

/**
 * @brief Copy `numberOfBytes` bytes from `source` to `destination`.
 *        Shitty memcpy().
 * 
 * @param source `void*` to source for copy
 * @param destination `void*` to destination for copy
 * @param numberOfBytes `size_t` number of bytes to copy
 * 
 * @attention REQUIRES `[source .. source + numberOfBytes] !! [destination .. destination + numberOfBytes]`
 */
void copy(void* source, void* destination, size_t numberOfBytes);



#endif