#include <stdio.h>
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return sum(n-1)+n;
}
int main()
{
    int ans = sum(5);
    printf("%d \n",ans);
    return 0;
}