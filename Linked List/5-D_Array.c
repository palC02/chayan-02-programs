#include <stdio.h>
#include <stdlib.h>

int main(){

int *****arr;
int i,j,k,l,m;
arr=(int*****)malloc(2*sizeof(int*));
for(i=0;i<2;i++){
    arr[i]=(int****)malloc(2*sizeof(int*));
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        arr[i][j]=(int***)malloc(2*sizeof(int*));
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        for(k=0;k<2;k++){
            arr[i][j][k]=(int**)malloc(2*sizeof(int*));
        }
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        for(k=0;k<2;k++){
            for(l=0;l<2;l++){
                arr[i][j][k][l]=(int*)malloc(2*sizeof(int));
            }
        }
    }
}
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    for(m=0;m<2;m++)
                    {
                      arr[i][j][k][l][m]=rand()%100;
                    }
                }
            }
        }
    }
    printf("The array---\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                for(l=0;l<2;l++)
                {
                    for(m=0;m<2;m++)
                    {
                     printf("%d\t",arr[i][j][k][l][m]);
                    }
                    printf("\n");
                }
                 printf("\n");
            }
             printf("\n");
        }
         printf("\n");
    }
}


