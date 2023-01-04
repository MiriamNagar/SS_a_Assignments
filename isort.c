#include <stdio.h>
#include "isort.h"

#define SIZE 50

void shift_element(int* arr, int i)
{
    if(arr == NULL) return;
    for(int j = 0 ; j < i ; j++)
    {
        *(arr+i-j) = *(arr+i-j-1);
    }
}

void printArray(int* arr, int len)
{
    if(arr == NULL) return;
    for(int i = 0 ; i < len; i++)
    {
        printf("%d, ", *(arr+i));
    }
    printf("\n");
}

void insertion_sort(int* arr , int len)
{
    if(arr == NULL) return;
    int j=0, value = 0;
    for(int i = 1 ; i < len; i++)
    {
        value = *(arr+i);
        j = i-1;
        while(j >=0 && *(arr+j) > value)
        {
            shift_element((arr+j), 1);
            j--;
        }
        *(arr+j+1)=value;
    }
}

int main()
{
    int arr[SIZE] = {};
    char c =' ';
    for(int i = 0; i< SIZE ; i++)
    {
        while(scanf("%d", (arr+i)) != 1)
        {
            scanf("%c", &c);
        }
    }
    insertion_sort(arr, SIZE);
    printArray(arr, SIZE);

    return 0;
}