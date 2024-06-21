/**
 * @file testBinsearch.c
 * @author Gabriel Field
 * @brief Tests for Algo: binary search
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "testBinsearch.h"
#include "../binsearch.h"
#include "../../../general_linear_structures/static/array.h"



/* TEST: All */

int testBinsearchDotC(void) {
    printf("<?> Running tests in testBinsearch.c...\n");
    int result =
        testBinsearchByteArray()
       + testBinsearch();
    printf("<?> ...end tests in testBinsearch.c; %d tests failed.\n", result);
    return result;
}



/* TEST: binsearch byte array */

int testBinsearchByteArray(void) {
    printf("<?> Running tests in testBinsearch.c ~> testBinsearchByteArray()...\n");
    int result =
        binsearchBytePresent()
        + binsearchByteAbsent();
    printf("<?> ...end tests in testBinsearch.c ~> testBinsearchByteArray(); %d tests failed.\n", result);
    return result;
}

int binsearchBytePresent(void) {
    printf("<?> Running test testBinsearch.c ~> binsearchBytePresent()...\n");
    // Initialise array {0 x 10, 1 x 10, ..., 199 x 10}
    ByteArray inHere = constructByteArray(2000);
    for (uint32_t i = 0; i < inHere.length; i++){
        *(inHere.start + i) = i / 10;
    }
    // <?>
    uint32_t claimedIndex = binsearchByte(inHere, 190);
    if (1900 <= claimedIndex && claimedIndex <= 1909) {
        printf("<?> ...end test testBinsearch.c ~> binsearchBytePresent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testBinsearch.c ~> binsearchBytePresent(); FAILURE.\n");
        return 1;
    }
}

int binsearchByteAbsent(void) {
    printf("<?> Running test testBinsearch.c ~> binsearchByteAbsent()...\n");
    // Initialise array {0 x 10, 1 x 10, ..., 199 x 10}
    ByteArray inHere = constructByteArray(2000);
    for (uint32_t i = 0; i < inHere.length; i++){
        *(inHere.start + i) = i / 10;
    }
    // <?>
    if (binsearchByte(inHere, 255) == 2000) {
        printf("<?> ...end test testBinsearch.c ~> binsearchByteAbsent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testBinsearch.c ~> binsearchByteAbsent(); FAILURE.\n");
        return 1;
    }
}



/* TEST: linsearch array */

int testBinsearch(void) {
    printf("<?> Running tests in testBinsearch.c ~> testBinsearch()...\n");
    int result =
        binsearchPresent()
       + binsearchAbsent();
    printf("<?> ...end tests in testBinsearch.c ~> testBinsearch(); %d tests failed.\n", result);
    return result;
}

int binsearchPresent(void) {
    printf("<?> Running test testLinsearch.c ~> binsearchPresent()...\n");
    // Initialise array {0 x 10, 1 x 10, ..., 799 x 10}, values of type int16_t
    Array inHere = newArray(8000, sizeof(int16_t));
    int16_t* inHereStart = inHere.start; // NOTE: typecast (void*) --> (int16_t*)
    for (uint32_t i = 0; i < inHere.length; i++)
    {
        *(inHereStart + i) = i / 10;
    }
    int16_t yourMom = 200;
    void* target = &yourMom; // NOTE: typecast (int16_t*) --> (void*)
    // <?>
    uint32_t claimedIndex = binsearch(inHere, target);
    if (2000 <= claimedIndex && claimedIndex < 2010) {
        printf("<?> ...end test testBinsearch.c ~> binsearchPresent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testBinsearch.c ~> binsearchPresent(); FAILURE.\n");
        return 1;
    }
}

int binsearchAbsent(void) {
    printf("<?> Running test testBinsearch.c ~> binsearchAbsent()...\n");
    // Initialise array {0 x 10, 1 x 10, ..., 799 x 10}, values of type int16_t
    Array inHere = newArray(8000, sizeof(int16_t));
    int16_t* inHereStart = inHere.start; // NOTE: typecast (void*) --> (int16_t*)
    for (uint32_t i = 0; i < inHere.length; i++)
    {
        *(inHereStart + i) = i / 10;
    }
    int16_t yourMom = 800;
    void* target = &yourMom; // NOTE: typecast (int16_t*) --> (void*)
    // <?>
    if (binsearch(inHere, target) == 8000) {
        printf("<?> ...end test testBinsearch.c ~> binsearchAbsent(); success.\n");
        return 0;
    } else {
        printf("<?> F..end test testBinsearch.c ~> binsearchAbsent(); FAILURE.\n");
        return 1;
    }
}
