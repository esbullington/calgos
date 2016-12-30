
#ifndef LINKEDLIST_H_   /* Include guard */
#define LINKEDLIST_H_

#include <stdbool.h>

typedef struct Node{ 
    struct Node *next;
    struct Node *prev;
    int data;
} tNode;

typedef struct { 
    tNode *curr;
    tNode *first;
    tNode *last;
} tLinkedList;

bool allocate_list(tLinkedList *ll, int n);
bool ll_push(tLinkedList *ll, int data);
bool ll_pop(tLinkedList *ll);
int ll_find(tLinkedList *ll, int data);
bool ll_get_index(tLinkedList *ll, int i, tNode *node);
bool ll_from_array(tLinkedList *ll, int arr[], int size);

#endif // LINKEDLIST_H_
