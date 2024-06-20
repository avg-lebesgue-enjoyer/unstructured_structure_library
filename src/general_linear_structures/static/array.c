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
