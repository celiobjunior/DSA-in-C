#include "list.h"

List* newList()
{
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int isEmpty(List* list)
{
    return list->size == 0;
}

Node* getNodeAtIndex(List* list, int index)
{
    if (index < 0 || index >= list->size) 
    {
        return NULL;
    }

    Node* current;
    if (index <= list->size / 2) 
    {
        current = list->head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
    } 
    else 
    {
        current = list->tail;
        for (int i = list->size - 1; i > index; i--) 
        {
            current = current->prev;
        }
    }
    return current;
}

int getValueAtIndex(List* list, int index)
{
    Node* node = getNodeAtIndex(list, index);
    return node->value;
}

void addAtHead(List* list, int value) 
{
    if (isEmpty(list)) 
    {
        list->head = newNode(value);
        list->tail = list->head;
    } 
    else 
    {
        Node* newFirst = newNode(value);
        Node* oldFirst = list->head;
        newFirst->next = oldFirst;
        oldFirst->prev = newFirst;
        list->head = newFirst;
    }
    list->size++;
}

void addAtTail(List* list, int value) 
{
    if (isEmpty(list)) 
    {
        list->head = newNode(value);
        list->tail = list->head;
    } 
    else 
    {
        Node* newLast = newNode(value);
        list->tail->next = newLast;
        newLast->prev = list->tail;
        list->tail = newLast;
    }
    list->size++;
}

void addAtIndex(List* list, int index, int val) 
{
    if (index < 0 || index > list->size) 
    {
        return;
    }
    if (index == 0) 
    {
        addAtHead(list, val);
        return;
    }
    if (index == list->size) 
    {
        addAtTail(list, val);
        return;
    }

    Node* new_Node = newNode(val);
    Node* current = getNodeAtIndex(list, index - 1);

    new_Node->next = current->next;
    new_Node->prev = current;
    if (current->next != NULL) { current->next->prev = new_Node; }
    current->next = new_Node;
    list->size++;
}

void deleteFirst(List* list) 
{
    Node* oldHead = list->head;
    list->head = list->head->next;
    if (list->size > 1) list->head->prev = NULL; // when size = 1, head.prev is already NULL
    list->size--;
    // to avoid loitering
    oldHead->next = NULL;
}

void deleteLast(List* list) 
{
    if (list->size == 1) 
    {
        list->head = NULL;
        list->tail = NULL;
    } 
    else 
    {
        Node* oldTail = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        // to avoid loitering
        oldTail->prev = NULL;
    }
    list->size--;
}

void deleteAtIndex(List* list, int index) 
{
    if (isEmpty(list)) 
    {
        return;
    }
    if (index < 0 || index >= list->size) 
    {
        return;
    }
    if (index == 0) 
    {
        deleteFirst(list);
        return;
    }
    if (index == list->size - 1) 
    {
        deleteLast(list);
        return;
    }
    Node* current = getNodeAtIndex(list, index - 1);
    Node* removed  = current->next;
    current->next = current->next->next;
    if (current->next != NULL) { current->next->prev = current; }
    list->size--;
    // to avoid loitering
    removed->next = NULL;
    removed->prev = NULL;
}

int main()
{
    List* list = newList();
    addAtHead(list, 7);
    addAtHead(list, 2);
    addAtHead(list, 1);
    addAtIndex(list, 3, 0);
    deleteAtIndex(list, 2);
    addAtHead(list, 6);
    addAtTail(list, 4);
    printf("value: %d\n", getValueAtIndex(list, 4));
    addAtHead(list, 4);
    addAtIndex(list, 5, 0);
    addAtHead(list, 6);

    Node* current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}