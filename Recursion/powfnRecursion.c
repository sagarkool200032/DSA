#include <stdio.h>

// method 1
int powerfn1(int n, int m)
{
    if(m==0)
        return 1;
    return powerfn1(n,m-1)*n;
}

// method 2 fast
int powerfn2(int n,int m)
{
    if(m==0)
        return 1;
    if(m%2==0)
        return powerfn2(n*n,m/2);
    else
        return powerfn2(n*n,(m-1)/2)*n;
}
int main()
{
    printf("%d \n",powerfn1(2,9));
    printf("%d \n", powerfn2(2,9));
    return 0;
}