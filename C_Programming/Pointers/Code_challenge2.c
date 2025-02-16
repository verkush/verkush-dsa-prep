//Work with Neighbors
//Write a function that receives an array and its size.
//Return 1, if the array has some element which value equals to the sum of both its neighbors (right, left).
// Return 0.

//Example #1 - [1,4,7,3,2] --> return 1
//Example #2 - [1,4,1,4,2] --> return 0
#include <stdio.h>
#include <stdint.h>

typedef uint8_t boolean;

boolean checkNeighborsSum(int *arr, int size)
{
    int i;
    for (int i = 1; i < size - 1; i++)
    {
        if((arr[i - 1] + arr[i + 1]) == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[5] = {1, 4, 1, 4, 2};
    boolean checkNeighbor = checkNeighborsSum(arr, 5);

    printf("%d", checkNeighbor);
    return 0;
}