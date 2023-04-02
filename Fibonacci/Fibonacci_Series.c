#include <stdio.h>
#include <stdlib.h>

static int count = 0;

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        count += 2;
        return n;
    }
    else
    {
        count++;
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the value:\n");
    scanf("%d", &n);
    ;
    count++;
    for (int i = 0; i < n; i++)
    {
        printf("%d", fibo(i));
    }
    printf("The Complexcity is:%d\n", count);
}
