#include "NumClass.h"

int numOfNumInX(int num)
{
    int c = 0;
    while(num > 0) 
    {
        num = num / 10;
        c += 1;
    }
    return c;
}

int countArmstrong(int num, int reminder, int inX)
{
    int sum = 0;
    if(inX - reminder <= 0) return 0;
    sum = powe(num % 10, inX);
    return sum + countArmstrong(num / 10, reminder+1, inX);
}

int isArmstrong(int num)
{
    if(num < 0)
    {
        return 0;
    }
    int sum = countArmstrong(num, 0, numOfNumInX(num));
    if(num == sum) return 1;
    return 0;
}


int checkPalindrome(int num, int fDigit, int lDigit, int len)
{
    if(len == 1) return 1;
    if(len == 2)
    {
        if(fDigit == lDigit) return 1;
        return 0;
    }
    int temp = powe(10, len - 2);
    int currentNum = num / 10;
    currentNum = currentNum % temp;
    int current = 0;
    if(fDigit == lDigit) current = 1;
    return checkPalindrome(currentNum, currentNum / (temp/10) , currentNum % 10, len-2) * (current);
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
    int len = numOfNumInX(num);
    return checkPalindrome(num, num / (powe(10, len - 1)), num % 10, len);
}