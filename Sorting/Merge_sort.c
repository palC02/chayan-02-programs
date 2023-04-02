#include<stdio.h>
#include<stdlib.h>


void merge(int *arr,int low, int mid, int high){
    int sz1=(mid-low)+1;
    int sz2=high-mid;
    int *a=(int*)malloc(sz1*sizeof(int));
    int *b=(int*)malloc(sz2*sizeof(int));
    int i,j,k;
    for(i=0;i<sz1;i++){
        a[i]=arr[i+low];
    }
    for(j=0;j<sz2;j++){
        b[j]=arr[j+mid+1];
    }
    i=0,j=0,k=low;
    while(i<sz1 && j<sz2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            i++;
            k++;
        }
    }
    while(i<sz1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<sz2){
        arr[k]=b[j];
        j++;
        k++;
    }
}

void merged_sort(int *arr,int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        merged_sort(arr,low,mid);
        merged_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void print_array(int *arr,int size){
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int size;
    printf("Enter the size of the Array:\n");
    scanf("%d",&size);
    int *arr=(int*)malloc(size*sizeof(int));
    printf("Enter the Array elements:\n");
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    printf("Before Merged_Sort the array looks like:\n");
    print_array(arr,size);
    printf("\n");
    merged_sort(arr,0,size-1);
    printf("Merged_Sort:\n");
    print_array(arr,size);
}