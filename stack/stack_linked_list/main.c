//
//  main.c
//  Stack_Linked_List
//
//  Created by Celio Junior on 19/09/24.
//

#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack* stack = newStack();
    
    push(stack, 10);
    push(stack, 11);
    push(stack, 12);
    push(stack, 13);
    
    pop(stack);
    
    push(stack, 14);
    
    pop(stack);
    
    push(stack, 15);
    
    printf("Size stack: %d\n", sizeStack(stack));
    
    printf("Size stack: %d\n", sizeStack2(stack));
    
    printStack2(stack);
    
}
