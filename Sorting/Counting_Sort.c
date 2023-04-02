#include <stdio.h>
#include <stdlib.h>

void count_sort(int *arr, int size)
{
    int max = arr[0];
    int i;
    for (i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int *count = (int *)calloc((max + 1), sizeof(int));
    int *brr = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    for (i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (i = size - 1; i >= 0; i--)
    {
        brr[--count[arr[i]]] = arr[i];
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = brr[i];
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter the size of the arrray:\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting the array looks like:\n");
    print_array(arr, size);

    count_sort(arr, size);

    printf("After implement of count sort the array looks like:\n");
    print_array(arr, size);
}