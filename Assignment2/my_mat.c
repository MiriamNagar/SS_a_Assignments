#include <stdio.h>
#include "my_mat.h"

int dist[10][10];

void build_matrix(int mat[10][10])
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    Floyd_marshall(mat);
}

void copy_matrix(int arr[10][10])
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            dist[i][j] = arr[i][j];
        }
    }
}

void print_matrix(int mat[10][10])
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void Floyd_marshall(int mat[10][10])
{
    copy_matrix(mat);
    int k = 0, m =0 , v=0; 
    for (k = 0; k < 10; k++) {  
        for (m = 0; m < 10; m++) { // Pick all vertices as source one by one
            for (v = 0; v < 10; v++) { // Pick all vertices as destination for the above picked source
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[m][k] + dist[k][v] < dist[m][v] && dist[m][k] + dist[k][v] != 0 && m!=v)
                    dist[m][v] = dist[m][k] + dist[k][v];
                if (dist[m][v] == 0 && dist[m][k]!=0 && dist[k][v]!=0 && m!=v)
                    dist[m][v] = dist[m][k] + dist[k][v];
            }
        }
    }
}

void path_exists()//int mat[10][10])
{
    int i, j;
    scanf("%d%d", &i, &j);
    if(dist[i][j] > 0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}


void shortest_path()//int mat[10][10])
{
    int i, j;
    scanf("%d%d", &i, &j);
    if(i == j)
    {
        printf("%d\n", -1);
    }
    else if(dist[i][j] == 0)
    {
        printf("%d\n", -1);
    }
    else{
        printf("%d\n", dist[i][j]);
    }
}

