/**
 * @file binsearch.c
 * @author Gabriel Field
 * @brief Implementation of a binary search algorithm
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "binsearch.h"
#include "../../allTheStructures.h"



/* SECTION: Linear search algorithm */

uint32_t binsearchByte(ByteArray inHere, uint8_t target) { // Precondition: inHere is sorted
    // Trivial edge case
    if (inHere.length == 0) {
        return inHere.length;
    }
    // Generic case
    // Search space is inHere[left .. right], inclusive of both endpoints.
    uint32_t left = 0;
    uint32_t right = inHere.length - 1;
    uint32_t middle;
    while (left < right) {
        middle = (left + right) / 2;
        if ( (*(inHere.start + middle)) == target ) {
            return middle;
        } else if ( (*(inHere.start + middle)) < target ) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return inHere.length;
}

uint32_t binsearch(Array inHere, void* target) {
    // Trivial edge case
    if (inHere.length == 0) {
        return inHere.length;
    }
    // Generic case
    // Search space is inHere[left .. right], inclusive of both endpoints.
    uint32_t left = 0;
    uint32_t right = inHere.length - 1;
    uint32_t middle;
    while (left < right) {
        middle = (left + right) / 2;
        if ( arrayElementEquals(inHere, middle, target) ) {
            return middle;
        } else if ( arrayElementLess(inHere, middle, target) ) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return inHere.length;
}
