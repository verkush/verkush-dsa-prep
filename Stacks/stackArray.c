#include <stdio.h>

#define size 3

int arr[size];
int top = -1;

void push_stack(int val)
{
    if(top == size - 1)
    {
        printf("Stack is Full \n");
    }
    else
    {
        ++top;
        arr[top] = val;
    }
}

void pop_stack()
{
    if(top == -1)
    {
        printf("Stack is Empty! \n");
    }
    else
    {
        printf("Popped element is %d ", arr[top]);
        top--;
    }
}

int main()
{
    int choice, val;
    printf("STACK\n");

    printf("1. Enter Element in stack\n");
    printf("2. Remove Element from stack\n");
    scanf("%d", &choice);


    switch(choice)
    {
        case 1: printf("Enter element : ");
                scanf("%d", &val);    
                push_stack(val);
                break;
                
        case 2: pop_stack();
                break;

        default: printf("Wrong choice !");
                    break;
    }

    return 0;
}