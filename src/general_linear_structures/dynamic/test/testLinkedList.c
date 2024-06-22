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
        + testLinkedList();
    printf("<?> ...end tests in testLinkedList.c; %d tests failed.\n", result);
    return result;
}



/* TEST: ByteLinkedList */

int testByteLinkedList(void) {
    printf("<?> Running tests in testLinkedList.c ~> testByteLinkedList()...\n");
    int result =
        byteLinkedListConstructs()
        + byteLinkedListNodeConstructs()
        + byteLinkedListBuilds()
        + testByteLinkedListLength()
        + testByteLinkedListGet()
        + testByteLinkedListSet()
        + testByteLinkedListInsert();
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
        printf("\tIndex %d stores data 0x%02x with next pointer 0x%p\n", 
                index, pLocation->data, pLocation->next);
        pLocation = pLocation->next; // Equivalent to `pLocation = (*pLocation).next`;
    }
    printf("\tFinal location pointer is 0x%p\n", pLocation);
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
        testNewLinkedList()
        + testNewLinkedListNode()
        + linkedListBuilds()
        + testLinkedListLength()
        + testLinkedListGet()
        + testLinkedListSet()
        + testLinkedListInsert();
    printf("<?> ...end tests in testLinkedList.c ~> testLinkedList(); %d tests failed.\n", result);
    return result;
}

int testNewLinkedList(void) {
    printf("<?> Running test testLinkedList.c ~> testNewLinkedList()...\n");
    LinkedList* fresh = newLinkedList(); // NOTE: Allocated memory must be freed
    printf("\tNew LinkedList constructed with head address 0x%p\n", fresh->head);
    killLinkedList(fresh); // NOTE: Allocated memory must be freed
    printf("<?> ...end test testLinkedList.c ~> testNewLinkedList(); success.\n");
    return 0;
}

int testNewLinkedListNode(void) {
    printf("<?> Running test testLinkedList.c ~> testNewLinkedListNode()...\n");
    uint16_t* payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    LinkedListNode* fresh = newLinkedListNode(payload);
    printf("\tNew LinkedListNode constructed with data byte 0x%04x and next address 0x%p\n", 
            *((uint16_t*) fresh->data), fresh->next);
    printf("<?> ...end test testLinkedList.c ~> testNewLinkedListNode(); success.\n");
    killLinkedListNode(fresh);
    return 0;
}

int linkedListBuilds(void) {
    printf("<?> Running test testLinkedList.c ~> linkedListBuilds()...\n");
    LinkedList* list = newLinkedList();
    uint16_t* payload;
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0690;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0ab0;
    linkedListPrepend(list, newLinkedListNode(payload));
    // Traverse linked list for funsies
    LinkedListNode* pLocation = list->head;
    for (uint32_t index = 0; index < 3; index++) {
        printf("\tIndex %d stores data 0x%04x with next pointer 0x%p\n", 
                index, *((uint16_t*) pLocation->data), pLocation->next);
        pLocation = pLocation->next; // Equivalent to `pLocation = (*pLocation).next`;
    }
    printf("\tFinal location pointer is 0x%p\n", pLocation);
    printf("<?> ...end test testLinkedList.c ~> linkedListBuilds(); success.\n");
    killLinkedList(list);
    return 0;
}

int testLinkedListLength(void) {
    printf("<?> Running test testLinkedList.c ~> testLinkedListLength()...\n");
    LinkedList* list = newLinkedList();
    uint16_t* payload;
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0690;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0ab0;
    linkedListPrepend(list, newLinkedListNode(payload));
    // <?>
    if ( linkedListLength(list) == 3 ) {
        printf("<?> ...end test testLinkedList.c ~> testLinkedListLength(); success.\n");
        killLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testLinkedListLength(); FAILURE.\n");
        killLinkedList(list);
        return 1;
    }
}

int testLinkedListGet(void) {
    printf("<?> Running test testLinkedList.c ~> testLinkedListGet()...\n");
    LinkedList* list = newLinkedList();
    uint16_t* payload;
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0690;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0ab0;
    linkedListPrepend(list, newLinkedListNode(payload));
    // <?>
    if ( *((uint16_t*) linkedListGet(list, 2)) == 0x0690 ) {
        printf("<?> ...end test testLinkedList.c ~> testLinkedListGet(); success.\n");
        killLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testLinkedListGet(); FAILURE.\n");
        killLinkedList(list);
        return 1;
    }
}

int testLinkedListSet(void) {
    printf("<?> Running test testLinkedList.c ~> testLinkedListSet()...\n");
    LinkedList* list = newLinkedList();
    uint16_t* payload;
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0690;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0ab0;
    linkedListPrepend(list, newLinkedListNode(payload));
    // <?>
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0xabcd;
    linkedListSet(list, 1, payload);
    if ( *((uint16_t*) linkedListGet(list, 1)) == 0xabcd ) {
        printf("<?> ...end test testLinkedList.c ~> testLinkedListSet(); success.\n");
        killLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testLinkedListSet(); FAILURE.\n");
        killLinkedList(list);
        return 1;
    }
}

int testLinkedListInsert(void) {
    printf("<?> Running test testLinkedList.c ~> testLinkedListInsert()...\n");
    LinkedList* list = newLinkedList();
    uint16_t* payload;
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0690;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0420;
    linkedListPrepend(list, newLinkedListNode(payload));
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0x0ab0;
    linkedListPrepend(list, newLinkedListNode(payload));
    // <?>
    payload = malloc(sizeof(uint16_t) * 1);
    *payload = 0xabcd;
    linkedListInsert(list, 1, newLinkedListNode(payload));
    if ( *((uint16_t*) linkedListGet(list, 2)) == 0xabcd ) {
        printf("<?> ...end test testLinkedList.c ~> testLinkedListInsert(); success.\n");
        killLinkedList(list);
        return 0;
    } else {
        printf("<?> F..end test testLinkedList.c ~> testLinkedListInsert(); FAILURE.\n");
        killLinkedList(list);
        return 1;
    }
}
