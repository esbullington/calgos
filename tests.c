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

    TEST_CHECK_(ll->curr->data == 0, "Test first list item.");
	while (ll->curr->next != NULL) {
		ll->curr = ll->curr->next;
	}
    TEST_CHECK_(ll->curr->data == 19, "Test last list item.");
}

TEST_LIST = {
    { "add",  test_add },
    { "list",  test_list },
    { 0 }
};
