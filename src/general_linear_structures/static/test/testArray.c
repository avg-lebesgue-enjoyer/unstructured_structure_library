/**
 * @file testArray.c
 * @author Gabriel Field
 * @brief Tests for Datas: Array
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "testArray.h"
#include "../array.h"



/* TEST: All */

int testArrayDotC(void) {
    printf("<?> Running tests in testArray.c...\n");
    int result =
        testByteArray()
        + testArray();
    printf("<?> ...end tests in testArray.c; %d tests failed.\n", result);
    return result;
}



/* TEST: ByteArray */

int testByteArray(void) {
    printf("<?> Running tests in testArray.c ~> testByteArray()...\n");
    int result =
        byteArrayConstructs()
        + byteArrayInitialiseToZero();
    printf("<?> ...end tests in testArray.c ~> testByteArray(); %d tests failed.\n", result);
    return result;
}

int byteArrayConstructs(void) {
    printf("<?> Running test testArray.c ~> byteArrayConstructs()...\n");
    ByteArray test = constructByteArray(10);
    // <?>
    for (uint32_t i = 0; i < test.length; i++){
        printf("\tIndex %d stores 0x%02x\n", i, *(test.start + i));
    }
    printf("<?> ...end test testArray.c ~> byteArrayConstructs(); success.\n");
    return 0;
}

int byteArrayInitialiseToZero(void) {
    printf("<?> Running test testArray.c ~> byteArrayInitialiseToZero()...\n");
    ByteArray test = constructByteArray(10);
    for (uint32_t i = 0; i < test.length; i++) {
        test.start[i] = 0; // Same as *(test.start + i) = 0
    }
    // <?> 
    int sad = 0;
    for (uint32_t i = 0; i < test.length; i++) {
        printf("\tIndex %d stores 0x%02x\n", i, *(test.start + i));
        if (*(test.start + i) != 0) {
            sad = 1;
        }
    }
    if (sad) {
        printf("<?> F..end test testArray.c ~> byteArrayInitialiseToZero(); FAILURE.\n");
    } else {
        printf("<?> ...end test testArray.c ~> byteArrayInitialiseToZero(); success.\n");
    }
    return sad;
}



/* TEST: Array */

int testArray(void) {
    printf("<?> Running tests in testArray.c ~> testArray()...\n");
    int result =
        arrayConstructs()
        + arrayInitialiseToZero()
        + array2D();
    printf("<?> ...end tests in testArray.c ~> testArray(); %d tests failed.\n", result);
    return result;
}

int arrayConstructs(void) {
    printf("<?> Running test testArray.c ~> arrayConstructs()...\n");
    Array test = newArray(10, sizeof(uint32_t));
    uint32_t* testStart = test.start; // NOTE: Type promotion (void*) --> (uint32_t*)
    printf("\tNew array made with length %d and cell size %d, for holding values of type uint32_t\n", 
            test.length, test.cellSize);
    for (uint32_t i = 0; i < test.length; i++) {
        printf("\tIndex %d stores %d\n", i, testStart[i]);
    }
    printf("<?> ...end test testArray.c ~> arrayConstructs(); success.\n");
    return 0;
}

int arrayInitialiseToZero(void) {
    printf("<?> Running test testArray.c ~> arrayInitialiseToZero()...\n");
    Array test = newArray(10, sizeof(uint32_t));
    uint32_t* testStart = test.start; // NOTE: Type promotion (void*) --> (uint32_t*)
    for (uint32_t i = 0; i < test.length; i++) {
        *(testStart + i) = 0; // Same as testStart[i] = 0;
    }
    // <?> 
    int sad = 0;
    for (uint32_t i = 0; i < test.length; i++) {
        printf("\tIndex %d stores %d\n", i, *(testStart + i));
        if (*(testStart + i) != 0) {
            sad = 1;
        }
    }
    if (sad) {
        printf("<?> F..end test testArray.c ~> arrayInitialiseToZero(); FAILURE.\n");
    } else {
        printf("<?> ...end test testArray.c ~> arrayInitialiseToZero(); success.\n");
    }
    return sad;
}



int array2D(void) {
    printf("<?> Running test testArray.c ~> array2D()...\n");
    Array grid = newArray(3, sizeof(Array)); // grid : Array<Array<uint8_t>> length 3 is what I intend
    Array* gridStart = grid.start;
    for (uint32_t down = 0; down < grid.length; down++) {
        gridStart[down] = newArray(1 + down, sizeof(uint8_t)); // gridStart[down] : Array<uint8_t> length (1 + down) is what I intend
    }
    /* Initialise 2D array to
        grid =
            {{0},
             {10, 11},
             {20, 21, 22}}
       i.e. grid[down][across] = 10 * down + across
    */
    uint32_t* rowStart;
    for (uint32_t down = 0; down < grid.length; down++) {
        rowStart = (*(gridStart + down)).start; // : uint32_t*, not : void* :)
        for (uint32_t across = 0; across < (*(gridStart + down)).length; across++) {
            *(rowStart + across) = 10 * down + across;
        }
    }
    // <?> Check that 2D array is as promised
    int sad = 0;
    for (uint32_t down = 0; down < grid.length; down++) {
        rowStart = (*(gridStart + down)).start; // : uint32_t*, not : void* :)
        printf("\tRow %d:\n\t\t", down);
        for (uint32_t across = 0; across < (*(gridStart + down)).length; across++) {
            printf("%d ", *(rowStart + across));
            if (*(rowStart + across) != 10 * down + across) {
                sad = 1;
            }
        }
        printf("\n");
    }
    if (sad) {
        printf("<?> F..end test testArray.c ~> array2D(); FAILURE.\n");
    } else {
        printf("<?> ...end test testArray.c ~> array2D(); success.\n");
    }
    return sad;
}
