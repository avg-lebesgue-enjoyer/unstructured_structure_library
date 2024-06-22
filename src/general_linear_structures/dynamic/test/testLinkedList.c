/**
 * @file testArray.c
 * @author Gabriel Field
 * @brief Tests for Datas: Linked list
 * @version 0.1
 * @date 2024-06-21
 * 
 * @copyright just don't misuse my work pls
 * 
 */

/* SECTION: #include */

#include "testLinkedList.h"
#include "../linkedList.h"



/* TEST: All */

int testLinkedListDotC(void) {
    printf("<?> Running tests in testLinkedList.c...\n");
    int result =
        testByteLinkedList()
        + testLinkedList()
        + testByteLinkedListLength()
        + testByteLinkedListGet()
        + testByteLinkedListSet()
        + testByteLinkedListInsert();
    printf("<?> ...end tests in testLinkedList.c; %d tests failed.\n", result);
    return result;
}



/* TEST: ByteLinkedList */

int testByteLinkedList(void) {
    printf("<?> Running tests in testLinkedList.c ~> testByteLinkedList()...\n");
    int result =
        byteLinkedListConstructs()
        + byteLinkedListNodeConstructs()
        + byteLinkedListBuilds();
    printf("<?> ...end tests in testLinkedList.c ~> testByteLinkedList(); %d tests failed.\n", result);
    return result;
}

int byteLinkedListConstructs(void) {
    printf("<?> Running test testLinkedList.c ~> byteLinkedListConstructs()...\n");
    ByteLinkedList* fresh = newByteLinkedList(); // NOTE: Allocated memory must be freed
    printf("\tNew ByteLinkedList constructed with head address 0x%p\n", fresh->head);
    killByteLinkedList(fresh); // NOTE: Allocated memory must be freed
    printf("<?> ...end test testLinkedList.c ~> byteLinkedListConstructs(); success.\n");
    return 0;
}

int byteLinkedListNodeConstructs(void) {
    printf("<?> Running test testLinkedList.c ~> byteLinkedListNodeConstructs()...\n");
    ByteLinkedListNode* fresh = newByteLinkedListNode(0x69);
    printf("\tNew ByteLinkedListNode constructed with data byte 0x%02x and next address 0x%p\n", 
            fresh->data, fresh->next);
    printf("<?> ...end test testLinkedList.c ~> byteLinkedListNodeConstructs(); success.\n");
    killByteLinkedListNode(fresh);
    return 0;
}

int byteLinkedListBuilds(void) {
    printf("<?> Running test testLinkedList.c ~> byteLinkedListBuilds()...\n");
    ByteLinkedList* list = newByteLinkedList();
    byteLinkedListPrepend(list, newByteLinkedListNode(0x69));
    byteLinkedListPrepend(list, newByteLinkedListNode(0x42));
    byteLinkedListPrepend(list, newByteLinkedListNode(0xab));
    // Traverse linked list for funsies
    ByteLinkedListNode* pLocation = list->head;
    for (uint32_t index = 0; index < 3; index++) {
        printf("\tIndex %d stores data 0x%02x with next pointer 0x%p", 
                index, pLocation->data, pLocation->next);
        pLocation = pLocation->next; // Equivalent to `pLocation = (*pLocation).next`;
    }
    printf("\tFinal location pointer is 0x%p", pLocation);
    printf("<?> ...end test testLinkedList.c ~> byteLinkedListBuilds(); success.\n");
    killByteLinkedList(list);
    return 0;
}

int testByteLinkedListLength(void) {
    printf("<?> Running test testLinkedList.c ~> testByteLinkedListLength()...\n");
    ByteLinkedList* list = newByteLinkedList();
    byteLinkedListPrepend(list, newByteLinkedListNode(0x69));
    byteLinkedListPrepend(list, newByteLinkedListNode(0x42));
    byteLinkedListPrepend(list, newByteLinkedListNode(0xab));
    if ( byteLinkedListLength(list) == 3 ) {
        printf("<?> ...end test testLinkedList.c ~> testByteLinkedListLength(); success.\n");
        killByteLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testByteLinkedListLength(); success.\n");
        killByteLinkedList(list);
        return 1;
    }
}

int testByteLinkedListGet(void) {
    printf("<?> Running test testLinkedList.c ~> testByteLinkedListGet()...\n");
    ByteLinkedList* list = newByteLinkedList();
    byteLinkedListPrepend(list, newByteLinkedListNode(0x69));
    byteLinkedListPrepend(list, newByteLinkedListNode(0x42));
    byteLinkedListPrepend(list, newByteLinkedListNode(0xab));
    // <?>
    if ( byteLinkedListGet(list, 2) == 0x69 ) {
        printf("<?> ...end test testLinkedList.c ~> testByteLinkedListGet(); success.\n");
        killByteLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testByteLinkedListGet(); success.\n");
        killByteLinkedList(list);
        return 1;
    }
}

int testByteLinkedListSet(void) {
    printf("<?> Running test testLinkedList.c ~> testByteLinkedListSet()...\n");
    ByteLinkedList* list = newByteLinkedList();
    byteLinkedListPrepend(list, newByteLinkedListNode(0x69));
    byteLinkedListPrepend(list, newByteLinkedListNode(0x42));
    byteLinkedListPrepend(list, newByteLinkedListNode(0xab));
    // <?>
    byteLinkedListSet(list, 1, 0x24);
    if ( byteLinkedListGet(list, 1) == 0x24 ) {
        printf("<?> ...end test testLinkedList.c ~> testByteLinkedListSet(); success.\n");
        killByteLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testByteLinkedListSet(); success.\n");
        killByteLinkedList(list);
        return 1;
    }
}

int testByteLinkedListInsert(void) {
    printf("<?> Running test testLinkedList.c ~> testByteLinkedListInsert()...\n");
    ByteLinkedList* list = newByteLinkedList();
    byteLinkedListPrepend(list, newByteLinkedListNode(0x69));
    byteLinkedListPrepend(list, newByteLinkedListNode(0x42));
    byteLinkedListPrepend(list, newByteLinkedListNode(0xab));
    // <?>
    byteLinkedListInsert(list, 1, newByteLinkedListNode(0x24));
    if ( byteLinkedListGet(list, 2) == 0x24 ) {
        printf("<?> ...end test testLinkedList.c ~> testByteLinkedListInsert(); success.\n");
        killByteLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testByteLinkedListInsert(); success.\n");
        killByteLinkedList(list);
        return 1;
    }
}



/* TEST: LinkedList */

int testLinkedList(void) {
    printf("<?> Running tests in testLinkedList.c ~> testLinkedList()...\n");
    int result =
        0;
    printf("<?> ...end tests in testLinkedList.c ~> testLinkedList(); %d tests failed.\n", result);
    return result;
}
