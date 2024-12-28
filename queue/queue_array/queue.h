//
//  queue.h
//  Queue_Array
//
//  Created by Celio Junior on 19/09/24.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int* array;
    int first;
    int last;
    int max;
}Queue;

Queue* newQueue(int max);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

int isEmpty(Queue* queue);

int isFull(Queue* queue);

int size(Queue* queue);

void printQueue(Queue* queue);

#endif /* queue_h */
