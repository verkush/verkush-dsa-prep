#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node;

Node * insertNodeLL(int val, Node * head)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
    {
        return newNode;
    }

    newNode->next = head;
    head = newNode;

    return head;
}

Node * reverseLL(Node *head)
{
    Node * curr = head;
    Node * prev = NULL;
    Node * temp = NULL;

    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;        
    }

    return prev;
}

void displayLL(Node * head)
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

    head = insertNodeLL(1, head);
    head = insertNodeLL(2, head);
    head = insertNodeLL(3, head);
    head = insertNodeLL(4, head);
    head = insertNodeLL(5, head);
    displayLL(head);

    head = reverseLL(head);
    displayLL(head);

}