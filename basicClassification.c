

int powe(int x, int y)
{
    int sum = 1;
    for(int i = 1 ; i <= y ;i++)
    {
        sum *= x;
    }
    return sum;
}

int factorial(int f){
    if(f == 0) return 1;
    return f*factorial(f-1);
}

int isStrong(int n){
    int currentDigit,temp;
    temp = n;
    currentDigit = n%10;
    int sum=0;
    while(temp>0){
        sum= sum+factorial(currentDigit);
        temp = temp/10;
        currentDigit = temp%10;
    }
    if(sum == n)
    {
        return 1;
    }
    return 0;
}

int isPrime(int x)
{
    if(x < 1) return 0;
    for(int i = 2 ; i < x ; i++)
    {
        if(x % i == 0) return 0;
    }
    return 1;
}