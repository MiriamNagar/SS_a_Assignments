#include <stdio.h>
#include "my_mat.h"

//matrix that holds shortest paths from i to j (0<=i,j<=9)
//values of i, j in the matrix mat we get from main
int dist[10][10] = {0}; 

//function after getting input 'A' on main,
//scan values entered by usr into the matrix(assuming the input is proper)
void build_matrix(int mat[10][10])
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            scanf("%d", &mat[i][j]); //scans user input for paths from i to j
        }
    }
    Floyd_marshall(mat); //method calculate shortest path in matrix and saves it into dist[][] val
}

//method to copy nat matrix given at main to dist matrix
void copy_matrix(int arr[10][10])
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            dist[i][j] = arr[i][j]; //copying values
        }
    }
}

//method to calculate shortest acrs in matrix and saves it into dist[][] val
void Floyd_marshall(int mat[10][10])
{
    copy_matrix(mat); //copying mat values into dist
    int k = 0, i =0 , j=0; 
    for (k = 0; k < 10; k++) {  //k-intermediate in path fron i to j
        for (i = 0; i < 10; i++) { //i scr of path
            for (j = 0; j < 10; j++) { //j dst of path
                //first condition to find min path, 
                //second&third condition check path from i to k to j exist(not equals to zero)
                //forth condition- given in Assignment that theres no paths from a vertex to itself
                if (dist[i][k] + dist[k][j] < dist[i][j] && dist[i][k]!=0 && dist[k][j] != 0 && i!=j)
                    dist[i][j] = dist[i][k] + dist[k][j];
                //first condition - if path from i to j does'nt exist(equals zero)
                //second&third condition check path from i to k to j exist(not equals to zero)
                //if path from i to j not exist but path from i to k to j exist than save
                //path from i to k to j
                //forth condition- given in Assignment that theres no paths from a vertex to itself
                if (dist[i][j] == 0 && dist[i][k]!=0 && dist[k][j]!=0 && i!=j)
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

//print true if there is a path from i to j, false otherwise
void path_exists(int i, int j)
{
    //dist holds shortest paths fron matrix mat valus
    //if min dist from i to j > 0 -> path exists, path = 0 -> path nonexistent
    if(dist[i][j] > 0) 
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

//prints shortest path fron i to j
void shortest_path(int i, int j)
{
    if(i == j) //given in Assignment that theres no paths from a vertex to itself
    {
        printf("%d\n", -1); //print -1 ->no path
    }
    //dist holds shortest paths fron matrix mat valus
    //if min dist from i to j = 0 -> path nonexistent, print -1
    else if(dist[i][j] == 0) 
    {
        printf("%d\n", -1);
    }
    else{ // path existent print min path(by using dist matrix)
        printf("%d\n", dist[i][j]);
    }
}

