/**
 * @file linsearch.c
 * @author Gabriel Field
 * @brief Implementation of a linear search algorithm
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "linsearch.h"
#include "../../allTheStructures.h"



/* SECTION: Linear search algorithm */

uint32_t linsearchByte(ByteArray inHere, uint8_t target) {
    for (uint32_t i = 0; i < inHere.length; i++) {
        if ( *(inHere.start + i) == target ) {
            return i;
        }
    }
    return inHere.length;
}

uint32_t linsearch(Array inHere, void* target) {
    const uint8_t* targetByte = target; // NOTE: typecast (void*) --> (uint8_t*)
    uint8_t* pInHere = inHere.start; // NOTE: typecast (void*) --> (uint8_t*)
    for (uint32_t i = 0; i < inHere.length; i++) {
        // Check whether the data here matches the target data, byte by byte.
        int match = 1;
        uint32_t j = 0;
        while ((j < inHere.cellSize) && match) {
            // Compare byte j of inHere[i] against byte j of the target
            pInHere = inHere.start + i * inHere.cellSize + j; // NOTE: typecast (void*) --> (uint8_t*)
            match = (*(targetByte + j)) == *pInHere;
            j++;
        }
        if (match) {
            return i;
        }
    }
    return inHere.length;
}
