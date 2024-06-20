#ifndef testArray_H
#define testArray_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Function prototypes */

int testArrayDotC(void);

int testByteArray(void);
int byteArrayConstructs(void);
int byteArrayInitialiseToZero(void);

int testArray(void);
int arrayConstructs(void);
int arrayInitialiseToZero(void);
int array2D(void);



#endif