#include <stdio.h>

// method 1  time: O(n^2)
float e(float x,float n)
{
    static float p=1,f=1;
    float r=0;
    if (n == 0)
        return 1;
    else
    {
        r = e(x,n-1);
        p = p*x;
        f = f*n;
        return r+(p/f);
    } 
}

// method 2 taylor series using horner's rule (taking common) time: O(n)
float e2(float x, float n)
{
    static float s=1;
    if (n == 0)
        return s;
    s=1+(x/n)*s;
    return e2(x,n-1);
}

int main()
{
    printf("%lf \n\n", e(4,10));
    printf("%lf \n", e2(2, 10000));
    return 0;
}