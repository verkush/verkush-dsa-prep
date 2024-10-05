#include <stdio.h>

int BinarySearch(int *arr, int item, int size)
{
    int left = 0;
    int right = size - 1;
    int mid = (left + right) / 2;

    while (left <= right)
    {
        if (item > arr[mid])
        {
            left = mid + 1;
        }
        else if (item < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            if (arr[mid] == item)
            {
                return mid;
            }
        }
            mid = (left + right) / 2;
    }
    
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 10, 23, 45, 56, 63 };

    int item = 45;

    //printf("Enter an item to Search ? ");
    //scanf("%d", &item);

    int index = BinarySearch(&arr[0], item, sizeof(arr));

    index != -1 ? printf("\nItem found at index %d", index) : printf("Item not found!");

    return 0;
}