#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int));
    printf("Enter the Elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int gap, i, j, key;
    for (gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            key = a[i];
            for (j = i - gap; j >= 0 && a[j] > key; j = j - gap)
            {
                a[j + gap] = a[j];
            }
            a[j + gap] = key;
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    return 0;
}