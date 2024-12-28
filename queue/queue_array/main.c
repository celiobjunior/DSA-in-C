//
//  main.c
//  Queue_Array
//
//  Created by Celio Junior on 19/09/24.
//

#include <stdio.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    
    Queue* queue = newQueue(10);
    
    enqueue(queue, 1);
    
    enqueue(queue, 2);
    
    enqueue(queue, 3);
    
    enqueue(queue, 4);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);
    
    enqueue(queue, 5);
    
    enqueue(queue, 6);
    
    enqueue(queue, 7);
    
    enqueue(queue, 8);

    enqueue(queue, 9);

    enqueue(queue, 10);
    
    enqueue(queue, 11);
    
    enqueue(queue, 12);
    
    enqueue(queue, 13);
    
    enqueue(queue, 14);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    dequeue(queue);

    printf("First: %d, Last: %d\n", queue->first, queue->last);
    
    printQueue(queue);
    
    return 0;
}
