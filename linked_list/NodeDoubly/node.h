#ifndef node_h
#define node_h

    #include <stdio.h>
    #include <stdlib.h>
    
    typedef struct Node
    {
        int value;
        struct Node* next;
        struct Node* prev;
    }Node;
    
    Node* newNode(int value);

#endif /* node_h */