#include <stdio.h>
#include <stdlib.h>

static int count = 0;

int fibo(int n, int a, int b)
{
    if (n == 0 || n == 1)
    {
        count += 2;
        return n;
    }
    printf("%d", &a + b);

    count += 2;
    return fibo(n - 1, b, a + b);
}

int main()
{
    int a, b, n;

    printf("Enter the value:\n");
    scanf("%d", &n);
    printf("0 , 1 ");
    fibo(n, 0, 1);

    printf("\nThe Complexity is:%d\n", count);
}
