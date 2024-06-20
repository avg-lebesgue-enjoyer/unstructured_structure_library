/**
 * @file testLinsearch.c
 * @author Gabriel Field
 * @brief Tests for Algo: linear search
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "testLinsearch.h"
#include "../linsearch.h"
#include "../../../general_linear_structures/static/array.h"



/* TEST: All */

int testLinsearchDotC(void) {
    printf("<?> Running tests in testLinsearch.c...\n");
    int result =
        testLinsearchByteArray()
        + testLinsearch();
    printf("<?> ...end tests in testLinsearch.c; %d tests failed.\n", result);
    return result;
}



/* TEST: linsearch byte array */

int testLinsearchByteArray(void) {
    printf("<?> Running tests in testLinsearch.c ~> testLinsearchByteArray()...\n");
    int result =
        linsearchBytePresent()
        + linsearchByteAbsent();
    printf("<?> ...end tests in testLinsearch.c ~> testLinsearchByteArray(); %d tests failed.\n", result);
    return result;
}

int linsearchBytePresent(void) {
    printf("<?> Running test testLinsearch.c ~> linsearchBytePresent()...\n");
    // Initialise array {0, 10, 20, 30}
    ByteArray inHere = constructByteArray(4);
    for (uint32_t i = 0; i < inHere.length; i++){
        *(inHere.start + i) = i * 10;
    }
    // <?>
    if (linsearchByte(inHere, 20) == 2) {
        printf("<?> ...end test testLinsearch.c ~> linsearchBytePresent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testLinsearch.c ~> linsearchBytePresent(); FAILURE.\n");
        return 1;
    }
}

int linsearchByteAbsent(void) {
    printf("<?> Running test testLinsearch.c ~> linsearchByteAbsent()...\n");
    // Initialise array {0, 10, 20, 30}
    ByteArray inHere = constructByteArray(4);
    for (uint32_t i = 0; i < inHere.length; i++){
        *(inHere.start + i) = i * 10;
    }
    // <?>
    if (linsearchByte(inHere, 69) == 4) {
        printf("<?> ...end test testLinsearch.c ~> linsearchByteAbsent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testLinsearch.c ~> linsearchByteAbsent(); FAILURE.\n");
        return 1;
    }
}



/* TEST: linsearch array */

int testLinsearch(void) {
    printf("<?> Running tests in testLinsearch.c ~> testLinsearch()...\n");
    int result =
        linsearchPresent()
        + linsearchAbsent();
    printf("<?> ...end tests in testLinsearch.c ~> testLinsearch(); %d tests failed.\n", result);
    return result;
}

int linsearchPresent(void) {
    printf("<?> Running test testLinsearch.c ~> linsearchPresent()...\n");
    // Initialise array {0, 100, 200, 300}, values of type int16_t
    Array inHere = newArray(4, sizeof(int16_t));
    int16_t* inHereStart = inHere.start; // NOTE: typecast (void*) --> (int16_t*)
    for (uint32_t i = 0; i < inHere.length; i++)
    {
        *(inHereStart + i) = 100 * i;
    }
    int16_t yourMom = 200;
    void* target = &yourMom; // NOTE: typecast (int16_t*) --> (void*)
    // <?>
    if (linsearch(inHere, target) == 2) {
        printf("<?> ...end test testLinsearch.c ~> linsearchPresent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testLinsearch.c ~> linsearchPresent(); FAILURE.\n");
        return 1;
    }
}

int linsearchAbsent(void) {
    printf("<?> Running test testLinsearch.c ~> linsearchAbsent()...\n");
    // Initialise array {0, 100, 200, 300}, values of type int16_t
    Array inHere = newArray(4, sizeof(int16_t));
    int16_t* inHereStart = inHere.start; // NOTE: typecast (void*) --> (int16_t*)
    for (uint32_t i = 0; i < inHere.length; i++)
    {
        *(inHereStart + i) = 100 * i;
    }
    int16_t yourMom = 420;
    void* target = &yourMom; // NOTE: typecast (int16_t*) --> (void*)
    // <?>
    if (linsearch(inHere, target) == 4) {
        printf("<?> ...end test testLinsearch.c ~> linsearchAbsent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testLinsearch.c ~> linsearchAbsent(); FAILURE.\n");
        return 1;
    }
}
