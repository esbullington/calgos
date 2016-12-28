
#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

int allocate_list(tLinkedList *ll, int n)
{
    int i;

    ll->first = malloc (sizeof (tNode));

    if (ll->first == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

	ll->last = ll->first;

    ll->first->data = 0;
    ll->first->next = NULL;

    for (i = 1; i < n; i++) {
        ll->curr = malloc (sizeof (tNode));
        if (ll->curr == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE); 
        } 
        ll->curr->data = i;
        ll->curr->next = NULL;
        ll->last->next = ll->curr;
        ll->last = ll->curr;
    }

	ll->curr = ll->first;
    return 0;
}

int ll_push(tLinkedList *ll, int data)
{
    tNode *new_node = malloc (sizeof (tNode));
    new_node->data = data;

    if (new_node == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    if (ll->first == NULL) {
        ll->first = new_node;
        ll->last = new_node;
        ll->curr = new_node;
        return 0;
    }

    ll->last->next = new_node;
    ll->last = new_node;
    ll->curr = ll->first;

    return 0;
}

int ll_pop(tLinkedList *ll)
{
    ll->curr = ll->first;
	while (ll->curr->next->next != NULL) {
		ll->curr = ll->curr->next;
	}
    ll->curr->next = NULL;
    ll->last = ll->curr;

    return 0;
}
