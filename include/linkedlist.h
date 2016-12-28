
#ifndef LINKEDLIST_H_   /* Include guard */
#define LINKEDLIST_H_

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

int allocate_list(tLinkedList *ll, int n);
int ll_push(tLinkedList *ll, int data);
int ll_pop(tLinkedList *ll);
int ll_find(tLinkedList *ll, int data);
int ll_get_index(tLinkedList *ll, int i, tNode *node);
int ll_from_array(tLinkedList *ll, int arr[], int size);

#endif // LINKEDLIST_H_
