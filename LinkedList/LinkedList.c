#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node * insertBeginning(int val, Node *head);
Node * insertBeforeNode(int val, int node, Node * head);

Node * insertBeginning(int val, Node *head)
{
    /* Create a new temp node with value to be inserted */
    Node * temp = (Node *)malloc(sizeof(Node));
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


Node * insertBeforeNode(int val, int node, Node * head)
{
    /* Create a new temp node with value to be inserted */
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    Node *prev = head;
    Node *curr = prev->next;

    while(curr->data != node && curr != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = newNode;
    newNode->next = curr;

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

    head = insertBeforeNode(5, 3, head);

    displayLinkedList(head);

    return 0;
}