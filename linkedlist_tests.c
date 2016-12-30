#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "CuTest.h"

void test_ll_push(CuTest *tc)
{
    tLinkedList *ll;

    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    ll_push(ll, 7);
    CuAssertIntEquals(tc, 7, ll->last->data);

    ll_push(ll, 8);
    CuAssertIntEquals(tc, 8, ll->last->data);
}

void test_ll_pop(CuTest *tc)
{
    tLinkedList *ll;
    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    ll_push(ll, 7);
    ll_push(ll, 8);
    ll_push(ll, 9);
    ll_pop(ll);

    CuAssertIntEquals(tc, 8, ll->last->data);

}

void test_ll_find(CuTest *tc)
{
    tLinkedList *ll;
    int data;
    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    ll_push(ll, 7);
    ll_push(ll, 77);
    ll_push(ll, 9);

    data = ll_find(ll, 77);
    CuAssertIntEquals(tc, 1, data);

    data = ll_find(ll, 87);
    CuAssertIntEquals(tc, -1, data);
}

void test_ll_get_index(CuTest *tc)
{
    tLinkedList *ll;
    tNode *node;
    int ret_code;
    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    ll_push(ll, 7);
    ll_push(ll, 77);
    ll_push(ll, 9);

    node = malloc( sizeof (tNode));
    ll_get_index(ll, 1, node);
    CuAssertIntEquals(tc, 77, node->data);

    node = malloc( sizeof (tNode));
    ll_get_index(ll, 0, node);
    CuAssertIntEquals(tc, 7, node->data);

    node = malloc( sizeof (tNode));
    ll_get_index(ll, 2, node);
    CuAssertIntEquals(tc, 9, node->data);

    node = malloc( sizeof (tNode));
    ret_code = ll_get_index(ll, 200, node);
    CuAssertIntEquals(tc, 0, ret_code);
}

void test_ll_from_array(CuTest *tc)
{
    tLinkedList *ll;
    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    int arr[] = {43, 52, 89, 1, 2, 3};

    ll_from_array(ll, arr, 6);

    CuAssertIntEquals(tc, 43, ll->first->data);
    CuAssertIntEquals(tc, 3, ll->last->data);

    ll_pop(ll);
    CuAssertIntEquals(tc, 2, ll->last->data);
}

CuSuite* LinkedListSuite()
{
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, test_ll_push);
	SUITE_ADD_TEST(suite, test_ll_pop);
	SUITE_ADD_TEST(suite, test_ll_find);
	SUITE_ADD_TEST(suite, test_ll_get_index);
	SUITE_ADD_TEST(suite, test_ll_from_array);
    return suite;
}
