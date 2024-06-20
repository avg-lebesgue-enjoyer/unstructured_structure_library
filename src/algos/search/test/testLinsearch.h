#ifndef testLinsearch_H
#define testLinsearch_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Function prototypes */

int testLinsearchDotC(void);

int testLinsearchByteArray(void);
int linsearchBytePresent(void);
int linsearchByteAbsent(void);

int testLinsearch(void);
int linsearchPresent(void);
int linsearchAbsent(void);



#endif