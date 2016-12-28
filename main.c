
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


int main(int argc, char **argv)
{
    tLinkedList *ll;

    ll = malloc( sizeof (tLinkedList));

    if (ll == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    allocate_list(ll, 20);

    // Print first node
    printf("Current node#: %d\n", ll->curr->data);

    // Print remaining nodes
	while (ll->curr->next != NULL) {
		ll->curr = ll->curr->next;
		printf("Current node#: %d\n", ll->curr->data);
	}

    exit(EXIT_SUCCESS); 
}
