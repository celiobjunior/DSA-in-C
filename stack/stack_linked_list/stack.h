//
//  stack.h
//  Stack_Linked_List
//
//  Created by Celio Junior on 19/09/24.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>
#include "NodeSingly/node.h"

typedef struct Stack
{
    Node* top;
    int size;
}Stack;

Stack* newStack(void);

void push(Stack* stack, int value);

int pop(Stack* stack);

int isEmpty(Stack* stack);

void printStack(Stack* stack);

void printStack2(Stack* stack);

int sizeStack(Stack* stack);

int sizeStack2(Stack* stack);

#endif /* stack_h */
