#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

tQueue *queue_init()
{
    tQueue *queue;
    queue = malloc( sizeof (tQueue));
    return queue;
}

bool queue_from_array(tQueue *queue, int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        queue_enqueue(queue, arr[i]);
    }

    return true;
}

bool queue_enqueue(tQueue *queue, int data)
{
    tNode *new_node = malloc (sizeof (tNode));
    new_node->data = data;

    if (new_node == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); 
    } 

    if (queue->first == NULL) {
        queue->first = new_node;
        queue->last = new_node;
        queue->curr = new_node;
        return true;
    }

    queue->last->next = new_node;
    new_node->prev = queue->last;
    queue->last = new_node;
    queue->curr = queue->first;

    return true;
}

tNode *queue_dequeue(tQueue *queue)
{
    tNode *node = queue->first;
    queue->first = queue->first->next;
    return node;
}

int queue_find(tQueue *queue, int data)
{
    int count = 0;
    queue->curr = queue->first;
    while (queue->curr != NULL) {
        if (queue->curr->data == data) {
            return count;
        }
        queue->curr = queue->curr->next;
        count++;
    }

    return -1;
}

bool queue_get_index(tQueue *queue, int i, tNode *node)
{
    int count = 0;
    queue->curr = queue->first;
    while (queue->curr != NULL) {
        if (count == i) {
            *node = *(queue->curr);
            return true;
        }
        queue->curr = queue->curr->next;
        count++;
    }
    return false;
}
