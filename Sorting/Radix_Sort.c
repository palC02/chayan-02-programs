#include <stdio.h>
#include <stdlib.h>

int Maxvalue(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int *arr, int size)
{

    int max = Maxvalue(arr, size);
    int i;

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

void Radix_sort(int *arr, int size)
{
    int pos;
    int max = Maxvalue(arr, size);

    for (pos = 1; max / pos; pos = pos * 10)
    {
        count_sort(arr, size);
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
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before Sorting:\n");
    print_array(arr, size);

    Radix_sort(arr, size);

    printf("After soting:\n");
    print_array(arr, size);
}