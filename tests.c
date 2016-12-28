#include "cutest.h"
#include "linkedlist.h"

void test_ll_push(void)
{
    tLinkedList *ll;

    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    ll_push(ll, 7);
    TEST_CHECK_(ll->last->data == 7, "Test first list item.");

    ll_push(ll, 8);
    TEST_CHECK_(ll->last->data == 8, "Test second list item.");
}

void test_ll_pop(void)
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

    TEST_CHECK_(ll->last->data == 8, "Test second list item after popping.");

}

void test_ll_find(void)
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
    TEST_CHECK_(data == 1, "Test find.");

    data = ll_find(ll, 87);
    TEST_CHECK_(data == -1, "Test find.");
}

void test_ll_get_index(void)
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
    TEST_CHECK_(node->data == 77, "Test get index.");

    node = malloc( sizeof (tNode));
    ll_get_index(ll, 0, node);
    TEST_CHECK_(node->data == 7, "Test get index.");

    node = malloc( sizeof (tNode));
    ll_get_index(ll, 2, node);
    TEST_CHECK_(node->data == 9, "Test get index.");

    node = malloc( sizeof (tNode));
    ret_code = ll_get_index(ll, 200, node);
    TEST_CHECK_(ret_code == -1, "Test get index.");
}

void test_ll_from_array(void)
{
    tLinkedList *ll;
    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    int arr[] = {43, 52, 89, 1, 2, 3};

    ll_from_array(ll, arr, 6);

    TEST_CHECK_(ll->first->data == 43, "Test first item.");
    TEST_CHECK_(ll->last->data == 3, "Test last item.");

    ll_pop(ll);
    TEST_CHECK_(ll->last->data == 2, "Test last item.");
}


TEST_LIST = {
    { "linked list push",  test_ll_push },
    { "linked list pop",  test_ll_pop },
    { "linked list find",  test_ll_find },
    { "linked list get index",  test_ll_get_index },
    { "linked list from array",  test_ll_from_array },
    { 0 }
};
