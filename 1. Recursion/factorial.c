#include <stdio.h>
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return sum(n - 1) * n;
}
int fact()
{
    int ans = sum(5);
    printf("%d \n", ans);
    return 0;
}