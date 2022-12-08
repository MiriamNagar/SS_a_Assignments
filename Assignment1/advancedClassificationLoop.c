#include "NumClass.h"

int numOfNumInX(int x)
{
    int c = 0;
    while(x > 0) 
    {
        x = x / 10;
        c += 1;
    }
    return c;
}

int isArmstrong(int num)
{
    if(num < 0)
    {
        return 0;
    }
    int power = numOfNumInX(num);
    int temp = num;
    int sum = 0;
    while(temp > 0)
    {
        sum += powe(temp % 10, power);
        temp = temp / 10;
    }
    if(sum == num)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int num)
{
    if(num < 0)
    {
        return 0;
    }
    if(num == 0)
    {
        return 1;
    }
    int arrLength = numOfNumInX(num);
    int xToArray[arrLength];
    for(int i = 0 ; i < arrLength ;i++)
    {
        xToArray[i] = num % 10;
        num = num / 10;
    }
    for(int i = 0; i < arrLength / 2 ; i++)
    {
        if(xToArray[i] != xToArray[arrLength-1-i])
        {
            return 0;
        }
    }
    return 1;
}
