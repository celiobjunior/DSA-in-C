//
//  stack.c
//  Stack_Linked_List
//
//  Created by Celio Junior on 19/09/24.
//

#include "stack.h"

Stack* newStack(void)
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, int value)
{
    if(isEmpty(stack))
    {
        stack->top = newNode(value);
    }
    else
    {
        Node* aux = newNode(value);
        aux->next = stack->top;
        stack->top = aux;
    }
    stack->size++;
}

int pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        Node* aux = stack->top;
        int aux_value = stack->top->value;
        stack->top = stack->top->next;
        free(aux);
        stack->size--;
        return aux_value;
    }
}

int isEmpty(Stack* stack)
{
    return stack->top == NULL;
    //return stack->size == 0;
}

// When you do know the number of nodes
void printStack(Stack* stack)
{
    Node* node = stack->top;
    
    for(int i = 0; i < stack->size; i++)
    {
        printf("%d", node->value);
        
        if(i < stack->size - 1)
        {
            printf(" -> ");
        }
        
        node = node->next;
    }
    printf("\n");
}

// When you don't know the number of nodes
void printStack2(Stack* stack)
{
    Node* node = stack->top;
    
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

// When you do know the number of nodes
int sizeStack(Stack* stack)
{
    return stack->size;
}

// When you don't know the number of nodes
int sizeStack2(Stack* stack)
{
    if(isEmpty(stack))
    {
        return 0;
    }
    Node* node = stack->top;
    int size = 0;
    while(node != NULL)
    {
        size++;
        node = node->next;
    }
    return size;
}
