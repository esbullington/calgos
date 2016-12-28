
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int ll_from_array(tLinkedList *ll, int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        ll_push(ll, arr[i]);
    }

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
    new_node->prev = ll->last;
    ll->last = new_node;
    ll->curr = ll->first;

    return 0;
}

int ll_pop(tLinkedList *ll)
{
    ll->last = ll->last->prev;
    ll->last->next = NULL;

    return 0;
}

int ll_find(tLinkedList *ll, int data)
{
    int count = 0;
    ll->curr = ll->first;
    while (ll->curr != NULL) {
        if (ll->curr->data == data) {
            return count;
        }
        ll->curr = ll->curr->next;
        count++;
    }

    return -1;
}

int ll_get_index(tLinkedList *ll, int i, tNode *node)
{
    int count = 0;
    ll->curr = ll->first;
    while (ll->curr != NULL) {
        if (count == i) {
            *node = *(ll->curr);
            return 0;
        }
        ll->curr = ll->curr->next;
        count++;
    }
    return -1;
}
