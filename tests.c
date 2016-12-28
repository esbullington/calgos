#include "cutest.h"
#include "linkedlist.h"

void test_linked_list(void)
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

TEST_LIST = {
    { "linked list",  test_linked_list },
    { "linked list push",  test_ll_push },
    { "linked list pop",  test_ll_pop },
    { 0 }
};
