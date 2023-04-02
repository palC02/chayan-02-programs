#include <stdio.h>
#include <stdlib.h>

int Insertion_sort(int *arr, int size)
{
    int key, j;
    for (int i = 0; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return arr;
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

    printf("Before sorting the array looks like:\n");
    print_array(arr, size);

    Insertion_sort(arr, size);

    printf("After calling the Insertion sort\nThe Looks Like:\n");
    print_array(arr, size);
}