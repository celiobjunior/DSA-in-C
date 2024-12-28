#ifndef list_h
#define list_h

    #include <stdio.h>
    #include <stdlib.h>
    #include "/Users/celio/Documents/ED/NodeDoubly/node.h"

    typedef struct List
    {
        Node* head;
        Node* tail;
        int size;
    }List;

    List* newList();

    int isEmpty(List* list);

    Node* getNodeAtIndex(List* list, int index);

    int getValueAtIndex(List* list, int index);

    void addAtHead(List* list, int value);

    void addAtTail(List* list, int value);

    void addAtIndex(List* list, int index, int val);

    void deleteFirst(List* list);

    void deleteLast(List* list);

    void deleteAtIndex(List* list, int index);

#endif /* list_h */