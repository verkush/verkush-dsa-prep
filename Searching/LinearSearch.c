#include <stdio.h>

int LinearSearch(int *arr, int item, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 4, 5, 8, 3, 0, 9, 30, 2, 11, 56 };

    int item;

    printf("Enter an item to Search ? ");
    scanf("%d", &item);

    int index = LinearSearch(&arr[0], item, sizeof(arr));

    index != -1 ? printf("\nItem found at index %d", index) : printf("Item not found!");

    return 0;
}