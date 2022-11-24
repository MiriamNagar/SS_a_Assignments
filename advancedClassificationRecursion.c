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

int countArmstrong(int x, int reminder, int inX)
{
    int sum = 0;
    if(inX - reminder <= 0) return 0;
    sum = powe(x%10, inX);
    return sum + countArmstrong(x/10, reminder+1, inX);
}

int isArmstrong(int x)
{
    int sum = countArmstrong(x, 0, numOfNumInX(x));
    if(x == sum) return 1;
    return 0;
}


int checkPalindrome(int x, int fDigit, int lDigit, int len)
{
    if(len == 1) return 1;
    if(len == 2)
    {
        if(fDigit == lDigit) return 1;
        return 0;
    }
    int temp = powe(10, len - 2);
    int currentNum = x/10;
    currentNum = currentNum % temp;
    int current = 0;
    if(fDigit == lDigit) current = 1;
    return checkPalindrome(currentNum, currentNum/(temp/10) , currentNum%10, len-2)*current;
}

int isPalindrome(int x)
{
    int len = numOfNumInX(x);
    return checkPalindrome(x, x/(powe(10, len - 1)), x%10, len);
}