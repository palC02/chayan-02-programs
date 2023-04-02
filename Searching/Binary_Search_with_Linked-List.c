#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *head = NULL;

void Binary_Search()
{
    node *start;
    node *end;
    node *mid;

    head = start;

    int First_Data;
    int Last_Data;
    int Mid_Data;
    start = (node *)malloc(sizeof(node));
    printf("Enter The Value:\n");
    scanf("%d", &First_Data);
    start->data = First_Data;

    end = (node *)malloc(sizeof(node));
    printf("Enter The Value:\n");
    scanf("%d", &Last_Data);
    end->link = Last_Data;

    Mid_Data = (Last_Data - First_Data) / 2;

    int n, position;
    printf("Enter The Position:\n");
    scanf("%d", &position);
    while (start != NULL && n > position)
    {
        start = start->link;
        n++;
    }
    end = start->link;
}

int main()
{
}