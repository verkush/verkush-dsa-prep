#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

void SelectionSort(int *arr, int size)
{
    // Outer Loop for passes
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
    int arr[] = {2, 1, 5, 10, 3, 0, 4, 9, 8, 7};

    printf("Before Sorting: ");
    displayArray(arr, MAX_SIZE);

    SelectionSort(arr, MAX_SIZE);

    printf("After Sorting: ");
    displayArray(arr, MAX_SIZE);

    return 0;
}