
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
