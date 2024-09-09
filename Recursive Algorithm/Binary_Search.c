#include<stdio.h>
#include<stdlib.h>

int Binary_Search(int *arr, int low, int high, int x){
    int mid;
    if(low<=high){
        mid=(low+high)/2;
    }
    if(arr[mid]==x){
        return mid;
    }
    else{
        if(arr[mid]>x){
            return Binary_Search(arr,low,mid-1,x);
        }
        else{
            return Binary_Search(arr,mid-1,high,x);
        }
    }
}

int main(){
    int s,x,low,high;
    int *arr=(int*)malloc(s*sizeof(int));
    printf("Enter the size: \n");
    scanf("%d",&s);
    printf("Enter the array elements:\n");
    for(int i=0;i<s;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of x: \n");
    scanf("%d",&x);
    Binary_Search(arr,0,s-1,x);

    /*if(x==Binary_Search(arr,0,s-1,x)){
        printf("The Number is present in the array\n");
    }
    else{
        printf("The number is not present in the array\n");
    }*/
   int c=Binary_Search(arr,0,s-1,x);
   if(c==-1){
    printf("Not Found\n");
   }
   else{
    printf("Found at index: %d",c);
   }
}
