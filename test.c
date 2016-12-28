#include "cutest.h"
#include "linkedlist.h"

void test_add(void)
{
    TEST_CHECK_(1 == 1, "One equals one.");
}

void test_list(void)
{
    tLinkedList *ll;

    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    allocate_list(ll, 20);
    TEST_CHECK_(ll->curr->data == 0, "Test list.");
}

TEST_LIST = {
    { "add",  test_add },
    { "list",  test_list },
    { 0 }
};
