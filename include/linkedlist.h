
#ifndef LINKEDLIST_H_   /* Include guard */
#define LINKEDLIST_H_

typedef struct Node{ 
    struct Node *next;
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

#endif // LINKEDLIST_H_
