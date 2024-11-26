#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


Node * insertBeginning(int val, Node *head)
{
    /* Create a new temp node with value to be inserted */
    Node * temp = (Node *)malloc(sizeof(Node *));
    temp->data = val;
    temp->next = NULL;

    /* Return temp node if list is empty */
    if(head == NULL)
    {
        return temp;
    }

    temp->next = head;
    head = temp;

    return head;
}


void displayLinkedList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{   
    Node * head = NULL;
    printf("Initial List: ");
    displayLinkedList(head);

    head = insertBeginning(1, head);
    head = insertBeginning(2, head);
    head = insertBeginning(3, head);
    head = insertBeginning(4, head);

    displayLinkedList(head);

    return 0;
}