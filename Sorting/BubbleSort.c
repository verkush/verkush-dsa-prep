#include <stdio.h>

#define MAX_SIZE 10

void BubbleSort(int *arr, int size)
{
    // Outer Loop for passes
    for (int i = 0; i < size; i++)
    {
        // inner loop for comparision
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {2, 1, 5, 10, 3, 0, 0, 0, 8, 7};

    printf("Before Sorting: ");
    displayArray(arr, MAX_SIZE);

    BubbleSort(arr, MAX_SIZE);

    printf("After Sorting: ");
    displayArray(arr, MAX_SIZE);

    return 0;
}