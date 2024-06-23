#ifndef main_H
#define main_H

/* SECTION: #include */

#include <stdlib.h>     // malloc(), calloc(), realloc(), free()
#include <ctype.h>      // bool
#include <stdint.h>     // uint32_t, int32_t
#include <stdio.h>      // printf(), scanf(), fgets()
#include <string.h>     // >> int strcmp(const char *_Str1,const char *_Str2); << returns 0 iff _Str1 and _Str2 are the same string



/* SECTION: Function prototypes */

int main(int argc, char *argv[]);



/* SECTION: Command-line argument copypastas */

#define TESTARRAY "array.c"
#define TESTARRAYLENGTH (8)

#define TESTLINSEARCH "linsearch.c"
#define TESTLINSEARCHLENGTH (12)

#define TESTBINSEARCH "binsearch.c"
#define TESTBINSEARCHLENGTH (12)

#define TESTLINKEDLIST "linkedList.c"
#define TESTLINKEDLISTLENGTH (13)

#define TESTEXTENSIBLELIST "extensibleList.c"
#define TESTEXTENSIBLELISTLENGTH (17)



#endif