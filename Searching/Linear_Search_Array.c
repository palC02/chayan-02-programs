#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    int arr[5];
    int i,n;
    printf("Enter The Number of The Elements:\n");
    scanf("%d",&size);
    printf("Enter The Data:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter The Data You Want to Match:\n");
    scanf("%d",&n);
    //int k;
    for(i=0;i<size;i++){
        if(arr[i]==n){
            printf("The Data is Existed\n");
        }
        else if(arr[i]!=n){
            printf("The Data is not Existed\n");
        }
        
    }
    return 0;
}