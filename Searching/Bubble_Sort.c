#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}

void Bubble_Sort(int arr[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
               if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
               }
        }
    }
}
void Print_array(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d",arr[i]);
        printf("\n");
    }
}
int main(){
    int arr[]={5,14,13,67,90,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    Bubble_Sort(arr,n);
    printf("Sorted array:\n");
    Print_array(arr,n);
    return 0;
}