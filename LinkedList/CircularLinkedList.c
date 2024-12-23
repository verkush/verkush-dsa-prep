#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} node;

node * create_node(int val)
{
    node * newNode = (node *) malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

node * addNodeBeginCLL(int val,  node * head)
{
    node * tempNode = create_node(val);

    node * lastNode = head;

    if (head == NULL)
    {
        head = tempNode;
        tempNode->next = head;

        return head;
    }

    tempNode->next = head;

    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = tempNode;

    head = tempNode;

    return head;
}

node * addNodeAfterCLL(int val, int afterNode, node * head)
{
    node * tempNode = create_node(val);

    node * prev = head;
    node * curr = prev->next;
    node * lastNode = head;

    if (head == NULL)
    {
        head = tempNode;
        tempNode->next = head;
        return head;
    }

    while (prev->data != afterNode)
    {
        prev = prev->next;
        curr = curr->next;
    }

    tempNode->next = curr;
    prev->next = tempNode;

    return head;
}

void displayCLL(node * head)
{
    node * temp = head;
    
    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->", temp->data);
    temp = temp->next;
    printf("%d", temp->data);

}

int main()
{   
    struct node * head = NULL;

    head = addNodeBeginCLL(1, head);
    head = addNodeBeginCLL(2, head);
    head = addNodeBeginCLL(3, head);
    head = addNodeBeginCLL(4, head);
    head = addNodeBeginCLL(5, head);

    head = addNodeAfterCLL(6, 2, head);
    head = addNodeAfterCLL(7, 5, head);
    head = addNodeAfterCLL(8, 1, head);

    displayCLL(head);

    return 0;
}