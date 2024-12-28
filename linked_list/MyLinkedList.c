#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

Node* newNode(int value)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

typedef struct
{
    Node* head;
    Node* tail;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate()
{
    MyLinkedList* list = (MyLinkedList*) malloc(sizeof(MyLinkedList));
    list->head = (Node*) malloc(sizeof(Node));
    list->tail = (Node*) malloc(sizeof(Node));
    list->size = 0;
    return list;
}

int isEmpty(MyLinkedList* obj)
{
    return obj->size == 0;
}

int myLinkedListGet(MyLinkedList* obj, int index)
{
    if (index < 0 || index >= obj->size)
    {
        return -1;
    }

    Node* current;
    if (index <= obj->size / 2)
    {
        current = obj->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
    }
    else
    {
        current = obj->tail;
        for (int i = obj->size - 1; i > index; i--)
        {
            current = current->prev;
        }
    }
    return current->value;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{
    if (isEmpty(obj))
    {
        obj->head = newNode(val);
        obj->tail = obj->head;
    }
    else
    {
        Node* newFirst = newNode(val);
        Node* oldFirst = obj->head;
        newFirst->next = oldFirst;
        oldFirst->prev = newFirst;
        obj->head = newFirst;
    }
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    if (isEmpty(obj))
    {
        obj->head = newNode(val);
        obj->tail = obj->head;
    }
    else
    {
        Node* newLast = newNode(val);
        obj->tail->next = newLast;
        newLast->prev = obj->tail;
        obj->tail = newLast;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
    {
        return;
    }
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size)
    {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node* new_Node = newNode(val);
    Node* current;
    if (index <= obj->size / 2)
    {
        current = obj->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
    }
    else
    {
        current = obj->tail;
        for (int i = obj->size - 1; i >= index; i--)
        {
            current = current->prev;
        }
    }

    new_Node->next = current->next;
    new_Node->prev = current;
    if (current->next != NULL) { current->next->prev = new_Node; }
    current->next = new_Node;
    obj->size++;
}

void deleteFirst(MyLinkedList* obj)
{
    Node* oldHead = obj->head;
    obj->head = obj->head->next;
    if (obj->size > 1) obj->head->prev = NULL; // when size = 1, head.prev is already NULL
    obj->size--;
    // to avoid loitering
    oldHead->next = NULL;
}

void deleteLast(MyLinkedList* obj)
{
    if (obj->size == 1)
    {
        obj->head = NULL;
        obj->tail = NULL;
    }
    else
    {
        Node* oldTail = obj->tail;
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
        // to avoid loitering
        oldTail->prev = NULL;
    }
    obj->size--;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if (isEmpty(obj))
    {
        return;
    }
    if (index < 0 || index >= obj->size)
    {
        return;
    }
    if (index == 0)
    {
        deleteFirst(obj);
        return;
    }
    if (index == obj->size - 1)
    {
        deleteLast(obj);
        return;
    }

    Node* current;
    if (index <= obj->size / 2)
    {
        current = obj->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
    }
    else
    {
        current = obj->tail;
        for (int i = obj->size - 1; i >= index; i--)
        {
            current = current->prev;
        }
    }

    Node* removed  = current->next;
    current->next = current->next->next;
    if (current->next != NULL) { current->next->prev = current; }
    obj->size--;
    // to avoid loitering
    removed->next = NULL;
    removed->prev = NULL;
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj->head);
    free(obj->tail);
    free(obj);
}
