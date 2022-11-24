#include <stdio.h>
#include "NumClass.h"

int main()
{
    int x, y;
    while(scanf("%d%d", &x, &y) != 2)
    {
        char c;
        scanf("%c", &c);
    }
    if(x>0 && y>0)
    {
        int big = y, small = x;
        if(x > y)
        {
            small = y;
            big = x;
        }
        printf("The Armstrong numbers are:");
        for(int i = small ; i<= big;i++ )
        {
            if(isArmstrong(i) == 1)
            {
                printf(" %d", i);
            }
        }
        printf("\nThe Palindromes are:");
        for(int i = small ; i<= big;i++ )
        {
            if(isPalindrome(i) == 1)
            {
                printf(" %d", i);
            }
        }
        printf("\nThe Prime numbers are:");
        for(int i = small ; i<= big;i++ )
        {
            if(isPrime(i) == 1)
            {
                printf(" %d", i);
            }
        }
        printf("\nThe Strong numbers are:");
        for(int i = small ; i<= big;i++ )
        {
            if(isStrong(i) == 1)
            {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}