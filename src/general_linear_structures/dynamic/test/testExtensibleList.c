/**
 * @file testExtensibleList.c
 * @author Gabriel Field
 * @brief Tests for Datas: Extensible list
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "testExtensibleList.h"
#include "../extensibleList.h"



/* TEST: All */

// FIXME: Actually write the tests!!
int testExtensibleListDotC(void) {
    printf("<?> Running tests in testExtensibleList.c...\n");
    int result =
        testByteExtensibleList()
        + testExtensibleList();
    printf("<?> ...end tests in testExtensibleList.c; %d tests failed.\n", result);
    return result;
}



/* TEST: ByteExtensibleList */

int testByteExtensibleList(void) {
    printf("<?> Running tests in testExtensibleList.c ~> testByteExtensibleList()...\n");
    int result =
        0;
    printf("<?> ...end tests in testExtensibleList.c ~> testByteExtensibleList(); %d tests failed.\n", result);
    return result;
}



/* TEST: LinkedList */

int testExtensibleList(void) {
    printf("<?> Running tests in testExtensibleList.c ~> testExtensibleList()...\n");
    int result =
        0;
    printf("<?> ...end tests in testExtensibleList.c ~> testExtensibleList(); %d tests failed.\n", result);
    return result;
}
