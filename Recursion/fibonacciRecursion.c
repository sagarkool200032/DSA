#include <stdio.h>
int F[10];
// time: O(2^n)  Method 1
int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-2)+fib(n-1);
}

// time: O(n)  Method 2 (Memoization)
int mfib(int n)
{
    if (n <= 1)
    {    F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            mfib(n-2);
        if (F[n - 1] == -1)
            mfib(n-1);
        F[n] = fib(n - 2) + fib(n - 1);
    }
    return fib(n - 2) + fib(n - 1);
}


int main()
{
    for(int i=0;i<10;i++)
        F[i]=-1;
    printf("%d\n",fib(10));
    printf("%d\n",mfib(7));
}