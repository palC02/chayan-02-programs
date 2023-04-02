#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, size, largest);
    }
}

void Heap_sort(int *arr, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        Heapify(arr, size, 0);
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

    Heap_sort(arr, size);

    printf("After heapsort:\n");
    print_array(arr, size);
}