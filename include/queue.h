#ifndef QUEUE_H_   /* Include guard */
#define QUEUE_H_

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
} tQueue;

tQueue *queue_init();
bool queue_enqueue(tQueue *queue, int data);
tNode *queue_dequeue(tQueue *queue);
int queue_find(tQueue *queue, int data);
bool queue_get_index(tQueue *queue, int i, tNode *node);
bool queue_from_array(tQueue *queue, int arr[], int size);

#endif // QUEUE_H_
