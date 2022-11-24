#include "NumClass.h"

int numOfNumInX(int x)
{
    int c = 0;
    while(x>0) 
    {
        x = x/10;
        c += 1;
    }
    return c;
}

int isArmstrong(int x)
{
    int power = numOfNumInX(x);
    int temp = x;
    int sum = 0;
    while(temp > 0)
    {
        sum += powe(temp%10, power);
        temp = temp/10;
    }
    if(sum == x)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int x)
{
    int arrLength = numOfNumInX(x);
    int xToArray[arrLength];
    for(int i= 0 ; i<arrLength ;i++)
    {
        xToArray[i] = x % 10;
        x = x/10;
    }
    for(int i = 0; i< arrLength/2;i++)
    {
        if(xToArray[i] != xToArray[arrLength-1-i])
        {
            return 0;
        }
    }
    return 1;
}