/**
 * @file main.c
 * @author Gabriel Field
 * @brief Driver for testing the data structures built in the project.
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "helpful.h"



/* SECTION: Helper methods */

void copy(void* source, void* destination, size_t numberOfBytes) {
    uint8_t* pByteToOverwrite = destination; // NOTE: Typecast (void*) --> (uint8_t*)
    uint8_t* pByteToOverwriteWith = source; // NOTE: Typecast (void*) --> (uint8_t*)
    for (size_t i = 0; i < numberOfBytes; i++) {
        *pByteToOverwrite = *pByteToOverwriteWith;
        pByteToOverwrite++;
        pByteToOverwriteWith++;
    }
}
