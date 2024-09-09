#include<stdio.h>
#include<stdlib.h>

int LinearSearch(int *arr, int x, int size){
int i;
for(i=0;i<size;i++){
    if(arr[i]==x){
        return i;
    }
    return -1;
}
}

int main(){
    int size;
    int *arr=(int*)malloc(size*sizeof(int));
    int x,c;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    printf("Enter rhe array elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number you want to search:\n");
    scanf("%d",&x);
    LinearSearch(arr,x,size);
    c=LinearSearch(arr,x,size);

    if(c==-1){
        printf("Number is not present in the array\n");
    }
    else{
        printf("Number is present at index: %d",c);
    }
}