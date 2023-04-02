#include<stdio.h>

int main(){
    int array[]={23,45,67,12,45,45};
    int i,n;
    int c;
    printf("Enter The Value You Want to Search:\t");
    scanf("%d",&n);
    c=0;
    for(i=0;i<=5;i++){
        if(array[i]==n);
        c++;
    }
    printf("\nYour Value is Found %d and %d time(s)\n",n,c);
    return 0;
}