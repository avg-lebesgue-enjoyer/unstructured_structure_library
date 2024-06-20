/**
 * @file array.c
 * @author Gabriel Field
 * @brief Datas: Array
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "array.h"



/* SECTION: Byte array */

ByteArray constructByteArray(uint32_t length) {
    uint8_t* start = malloc(sizeof(uint8_t) * length);
    ByteArray returnMe = { .length = length, .start = start };
    return returnMe;
}



/* SECTION: Generic array */

Array newArray(uint32_t length, uint32_t cellSize) {
    // void* start = calloc(length, cellSize); // This is slower due to zero-initialisation!
    void* start = malloc(cellSize * length);
    Array returnMe = { .length = length, .cellSize = cellSize, .start = start };
    return returnMe;
}

void* indexArray(Array inHere, uint32_t atHere) {
    return inHere.start + atHere * inHere.cellSize;
}

uint8_t compareArrayElement(Array inHere, uint32_t atHere, void* againstThis) {
    uint8_t* pArrayByte;
    uint8_t* targetByte = againstThis; // NOTE: typecast (void*) --> (uint8_t*)
    uint8_t match = 1;
    uint32_t j = 0;
    while ((j < inHere.cellSize) && match) {
        // Compare byte j of inHere[i] against byte j of the target
        pArrayByte = inHere.start + atHere * inHere.cellSize + j; // NOTE: typecast (void*) --> (uint8_t*)
        match = (*(targetByte + j)) == *pArrayByte;
        j++;
    }
    return match;
}
