#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node * prev;
    int data;
    struct node * next;
} node;

node * create_node(int val)
{
    node * newNode = (node *) malloc(sizeof(node));

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

node * addNodeBeginDLL(int val, node * head)
{
    node * tempNode = create_node(val);

    if (head == NULL)
    {
        return tempNode;
    }

    head->prev = tempNode;
    tempNode->next = head;
    head = tempNode;

    return head;
}

node * addNodeBeforeDLL(int val, int nodeBefore, node * head)
{
    node * newNode = create_node(val);
    node * tempNode = head;

    while (tempNode->data != nodeBefore)
    {
        tempNode = tempNode->next;
    }

    tempNode->prev->next = newNode;
    newNode->next = tempNode;
    newNode->prev = tempNode->prev;
    tempNode->prev = newNode;

    return head;
}

node * addNodeAfterDLL(int val, int nodeAfter, node * head)
{
    node * newNode = create_node(val);
    node * tempNode = head;

    while (tempNode->data != nodeAfter)
    {
        tempNode = tempNode->next; 
    }

    if (tempNode->next == NULL)
    {
        tempNode->next = newNode;
        newNode->prev = tempNode;
    }
    else 
    {
        newNode->next = tempNode->next;
        tempNode->next->prev = newNode;
        tempNode->next = newNode;
        newNode->prev = tempNode;
    }

    return head;
}

void displayDLL(node * head)
{
    node * temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseDisplayDLL(node * head)
{
    node * lastNode = head;

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    while (lastNode != NULL)
    {
        printf("%d->", lastNode->data);
        lastNode = lastNode->prev;
    }
    printf("NULL\n");
}

int main()
{
    node * head = NULL;

    head = addNodeBeginDLL(1, head);
    head = addNodeBeginDLL(2, head);
    head = addNodeBeginDLL(3, head);

    head = addNodeBeforeDLL(6, 2, head);

    head = addNodeAfterDLL(7, 1, head);

    displayDLL(head);
    reverseDisplayDLL(head);

    return 0;
}