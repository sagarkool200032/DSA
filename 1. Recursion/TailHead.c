#include <stdio.h>
// Tail
void fun1(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun1(n-1);
    }
}

// Head
void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        printf("%d ", n);
    }
}

void main()
{
    int x = 3;
    fun1(x);
    printf("\n\n");
    fun2(x);
}