#include <stdio.h>

#define V 3

void init_matrix(int arr[][V])
{
    int i, j;

    for (i  = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int add_edge(int arr[][V], int src, int dest)
{
    arr[src][dest] = 1;
}

void print_adj_matrix(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[V][V];

    init_matrix(adjMatrix);

    add_edge(adjMatrix, 0, 1);
    add_edge(adjMatrix, 0, 2);
    add_edge(adjMatrix, 0, 3);
    add_edge(adjMatrix, 1, 3);
    add_edge(adjMatrix, 1, 4);
    add_edge(adjMatrix, 2, 3);
    add_edge(adjMatrix, 3, 4);

    print_adj_matrix(adjMatrix);

    return 0;
}