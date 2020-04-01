#include <stdio.h>
// Static

// power funtion using recursion
int fun1(int n)
{
    static int x=0;
    if(n > 0)
    {
        x+=1;
        return fun1(n-1)+x;  
    }
    return 0;
}

int main()
{
    int result;
    result = fun1(5);
    printf("%d\n\n",result);
    result = fun1(5);
    printf("%d\n\n", result);
    return 0; 
}

// // Multiplication Table Using Recursion
// #include <stdio.h>
// int x=1;
// int table(int n)
// {
//     if (x<=10)
//     {
//         int ans;
//         ans = n*x++;
//         printf("%d\n",ans);
//         table(n);
//     }
//     return 0;
// }

// int main()
// {
//     int number;
//     number = 4;
//     table(4);
//     return 0;
// }