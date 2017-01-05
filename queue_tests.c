#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "CuTest.h"

void test_queue_enqueue(CuTest *tc)
{
    tQueue *queue;
    queue = queue_init();

    if (queue == NULL) {
        perror("Linked list initialization failed");
        exit(EXIT_FAILURE); 
    } 

    queue_enqueue(queue, 7);
    CuAssertIntEquals(tc, 7, queue->last->data);

    queue_enqueue(queue, 8);
    CuAssertIntEquals(tc, 8, queue->last->data);
}

void test_queue_dequeue(CuTest *tc)
{
    tQueue *queue;
    queue = queue_init();

    if (queue == NULL) {
        perror("Linked list initialization failed");
        exit(EXIT_FAILURE); 
    } 

    queue_enqueue(queue, 7);
    queue_enqueue(queue, 8);
    queue_enqueue(queue, 9);
    queue_dequeue(queue);

    CuAssertIntEquals(tc, 8, queue->first->data);
    CuAssertIntEquals(tc, 9, queue->last->data);

}

void test_queue_find(CuTest *tc)
{

    int data;
    tQueue *queue;

    queue = queue_init();

    if (queue == NULL) {
        perror("Linked list initialization failed");
        exit(EXIT_FAILURE); 
    } 

    queue_enqueue(queue, 7);
    queue_enqueue(queue, 77);
    queue_enqueue(queue, 9);

    data = queue_find(queue, 77);
    CuAssertIntEquals(tc, 1, data);

    data = queue_find(queue, 87);
    CuAssertIntEquals(tc, -1, data);
}

void test_queue_get_index(CuTest *tc)
{
    tNode *node;
    int ret_code;
    tQueue *queue;

    queue = queue_init();

    if (queue == NULL) {
        perror("Linked list initialization failed");
        exit(EXIT_FAILURE); 
    } 

    queue_enqueue(queue, 7);
    queue_enqueue(queue, 77);
    queue_enqueue(queue, 9);

    node = malloc( sizeof (tNode));
    queue_get_index(queue, 1, node);
    CuAssertIntEquals(tc, 77, node->data);

    node = malloc( sizeof (tNode));
    queue_get_index(queue, 0, node);
    CuAssertIntEquals(tc, 7, node->data);

    node = malloc( sizeof (tNode));
    queue_get_index(queue, 2, node);
    CuAssertIntEquals(tc, 9, node->data);

    node = malloc( sizeof (tNode));
    ret_code = queue_get_index(queue, 200, node);
    CuAssertIntEquals(tc, 0, ret_code);
}

void test_queue_from_array(CuTest *tc)
{
    tQueue *queue;
    queue = queue_init();

    if (queue == NULL) {
        perror("Linked list initialization failed");
        exit(EXIT_FAILURE); 
    } 

    int arr[] = {43, 52, 89, 1, 2, 3};

    queue_from_array(queue, arr, 6);

    CuAssertIntEquals(tc, 43, queue->first->data);
    CuAssertIntEquals(tc, 3, queue->last->data);

    queue_dequeue(queue);
    CuAssertIntEquals(tc, 3, queue->last->data);
    CuAssertIntEquals(tc, 52, queue->first->data);
}

CuSuite* QueueSuite()
{
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, test_queue_enqueue);
	SUITE_ADD_TEST(suite, test_queue_dequeue);
	SUITE_ADD_TEST(suite, test_queue_find);
	SUITE_ADD_TEST(suite, test_queue_get_index);
	SUITE_ADD_TEST(suite, test_queue_from_array);
    return suite;
}
