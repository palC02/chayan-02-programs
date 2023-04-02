#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
void insert_at_pos(struct node **head, int pos, int n)
{
    int count = 1;
    node *tmp = (node *)malloc(sizeof(node));
    node *temp = *head;
    while (temp->link != NULL && count < pos - 1)
    {
        temp = temp->link;
        count++;
    }
    tmp->data = n;
    tmp->link = temp->link;
    temp->link = tmp;
}
void insert(struct node **head, int n)
{

    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = n;
    tmp->link = NULL;
    if (*head == NULL)
    {
        *head = tmp;
    }
    else
    {
        node *temp = *head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = tmp;
    }
}
void insert_at_begining(node **head, int n)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = n;
    if (*head == NULL)
    {
        *head = tmp;
        tmp->link = NULL;
    }
    else
    {
        tmp->link = *head;
        *head = tmp;
    }
}
void delete_begining_element(node **head)
{
    node *temp;
    temp = *head;
    *head = temp->link;
    free(temp);
}
void delete_at_end(node **head)
{
    node *ttm;
    ttm = *head;
    while (ttm->link->link != NULL)
    {
        ttm = ttm->link;
    }
    node *temp = ttm->link->link;
    ttm->link = NULL;
    free(temp);
}
void delete_at_pos(node **head, int pos)
{
    node *tmp = *head;
    int count = 1;
    while (tmp->link != NULL && count < pos - 1)
    {
        tmp = tmp->link;
        count++;
    }
    node *temp = tmp->link;
    tmp->link = tmp->link->link;
    free(temp);
}
void delete_entire_list(node **head)
{
    while ((*head) != NULL)
    {
        delete_begining_element(head);
    }
    printf("Entire list deleted\n");
}
void display(node *head)
{
    node *tmp = head;

    while (tmp != NULL)
    {

        printf("%d\t", tmp->data);
        tmp = tmp->link;
    }
}
int main()
{
    node *head;
    head = NULL;
    int choice, n, pos;
    while (1)
    {
        printf("\npress\n");
        printf("1---> to enter an element at end\n");
        printf("2---> to enter an element at begining\n");
        printf("3---> to enter an element at position\n");
        printf("4---> to delete an element at position\n");
        printf("5---> to delete the head element\n");
        printf("6---> to delete the last element\n");
        printf("7---> to exit from menu\n");
        printf("8---> to delete entire list\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert at end\n");
            scanf("%d", &n);
            insert(&head, n);
            display(head);
            break;
        case 2:
            printf("Enter the element to insert\n");
            scanf("%d", &n);
            insert_at_begining(&head, n);
            display(head);
            break;
        case 3:
            printf("Position:");
            scanf("%d", &pos);
            printf("Enter element:");
            scanf("%d", &n);

            if (pos == 1 || head == NULL)
            {
                insert_at_begining(&head, n);
            }
            else
            {
                insert_at_pos(&head, pos, n);
            }
            display(head);
            break;
        case 4:
            printf("Enter position:");
            scanf("%d", &pos);
            printf("\n");
            if (head == NULL)
            {
                printf("You can not perform deletion on an empty array\n");
            }
            else
            {
                if (pos == 1)
                {
                    delete_begining_element(&head);
                }
                else
                {
                    delete_at_pos(&head, pos);
                }
            }
            display(head);
            break;
        case 5:
            printf("Deleting the head element\n");
            if (head == NULL)
            {
                printf("Head is already NULL\n");
            }
            else
            {
                delete_begining_element(&head);
            }
            display(head);
            break;
        case 6:
            printf("Deleting the last element\n");
            if (head == NULL)
            {
                printf("Head is already NULL\n");
            }
            else
            {
                delete_at_end(&head);
            }
            display(head);
            break;
        case 7:
            printf("Thanks for using:)");
            exit(1);
            break;
        case 8:
            delete_entire_list(&head);
            break;

        default:
            printf("Wrong input enter again");
        }
    }
    return 0;
}
