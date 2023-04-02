#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void Quick_Sort(int *arr, int low, int high){
    if(low<high){
        int i = Partition(arr,low,high);
        Quick_Sort(arr,low,i-1);
        Quick_Sort(arr,i+1,high);
    }
}

int Partition(int *arr, int low, int high){
    int pivot=arr[high];
    int k=low-1;
    int j=low;
    for(;j<high;j++){
        if(arr[j]<pivot){
            k++;
            swap(&arr[k],&arr[j]);
        }
    }
    k++;
    swap(&arr[k],&arr[high]);
    return k;
}

void Print_array(int *arr, int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
        printf("\n");
    }
}

int main(){
    int size;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("Enter the array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("The Unsorted Array is:\n");
    Print_array(arr,size);

    Quick_Sort(arr,0,size-1);

    printf("The Sorted Array is:\n");
    Print_array(arr,size);
}