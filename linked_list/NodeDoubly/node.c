#include "node.h"

Node* newNode(int value)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}