#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Write a function to check if the array is "Really sorted", "sorted", "not sorted".
// The function should return 1 and PASS 1 by reference if the array is "Really sorted". 
// The function should return 1 and PASS 0 by reference if the array is "Sorted". 
// The function should return 0 and PASS 0 by reference if the array is "not sorted".

// Example: [1,2,5,7,10] --> really sorted
// Example: [1,2,2,5,10] --> sorted
// Example: [1,2,5,3,10] --> not sorted

uint8_t checkArraySorted(int *arr, int size, int * isReallySorted)
{
    int i;
    *isReallySorted = 1; //Assuming array is really sorted

    for (int i = 1; i < size; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            *isReallySorted = 0;
        }
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
        
    }

    return 1;
}

int main()
{
    int arr[] = {1, 2, 2, 7, 10};
    int isReallySorted;

    uint8_t status = checkArraySorted(arr, 5, &isReallySorted);
    
    if ((isReallySorted == 1) && (status == 1))
    {
        printf("Really Sorted");
    }
    else if ((isReallySorted == 0) && (status == 1))
    {
        printf("Sorted");
    }
    else
    {
        printf("Not Sorted");
    }

    return 0;
}