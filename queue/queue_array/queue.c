//
//  queue.c
//  Queue_Array
//
//  Created by Celio Junior on 19/09/24.
//

#include "queue.h"

Queue* newQueue(int max)
{
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->array = (int*) malloc(max * sizeof(int));
    queue->max = max;
    queue->first = 0;
    queue->last = 0;
    return queue;
}

// add item in the end of the queue
void enqueue(Queue* queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        exit(1);
    }
    queue->array[queue->last] = value;
    queue->last = (queue->last + 1) % queue->max;
}

// remove item from the begining of the queue
int dequeue(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(1);
    }
    int aux = queue->array[queue->first];
    queue->array[queue->first] = 0;
    queue->first = (queue->first + 1) % queue->max;
    return aux;
}

int isEmpty(Queue* queue)
{
    //if (queue->first == queue->last) { return 1; }
    
    return 0;
}

int isFull(Queue* queue)
{
    
    return 0;
}

int size(Queue* queue)
{
    return (queue->last - queue->first) + queue->max;
}

void printQueue(Queue* queue)
{
    printf("[");
    for (int i = 0; i < queue->max; i++)
    {
        printf("%d", queue->array[i]);
        if (i < queue->max-1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
