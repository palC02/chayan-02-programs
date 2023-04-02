#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
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
    int *arr = (int *)malloc(sizeof(int) * size);
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting the array is:\n");
    print_array(arr, size);

    Selection_sort(arr, size);

    printf("After appling Selection Sort:\n");
    print_array(arr, size);
}