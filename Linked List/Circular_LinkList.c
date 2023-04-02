#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void find_last(node **head, node **last)
{
    if (*head != NULL)
    {
        node *temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        *last = temp;
    }
}
void Insert_at_Beginning(node **head, node **last, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        temp->next = temp;
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *last->next = temp;
        *head = temp;
    }
    printf("\nNode Inserted.\n");
}
void Insert_at_End(node **head, node **last, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        temp->next = temp;
        *head = temp;
    }
    else
    {
        *last->next = temp;
        temp->next = *head;
    }
    printf("\nNode Inserted.\n");
}
void Insert_at_any_Position(node **head, node **last, int data, int pos)
{

    if (pos == 1)
    {
        Insert_at_Beginning();
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        temp->data = data;
        if (*head == NULL)
        {
            temp->next = temp;
            *head = temp;
        }
        else
        {
            node *ttm = *head;
            int n = 1;
            while (ttm->next != *head && n < pos - 1)
            {
                ttm = ttm->next;
                n++;
            }
            temp->next = ttm->next;
            ttm->next = temp;
        }
        printf("\nNode Inserted.\n");
    }
}
void Delete_at_Begining(node **head, node **last)
{
    if (*head == NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        if (*head->next != *head)
        {
            *last->next = *head->next;
            node *temp = *head;
            *head = *head->next;
            free(temp);
        }
        else
            *head = *last = NULL;
    }
}
void Delete_at_End(node **head, node **last)
{
    if (*head == NULL)
        printf("\nList is empty...\n");
    else
    {
        if (*head->next != *head)
        {
            node *temp = *head;
            while (temp->next != *last)
                temp = temp->next;
            temp->next = *head;
            free(*last);
        }
        else
            *head = *last = NULL;
    }
}
void Delete_at_any_Position(node **head, node **last, int pos)
{
    if (head != NULL)
    {
        if (pos == 1)
        {
            deletebegin();
            printf("\nNode deleted...\n");
        }
        else
        {
            int n = 1;
            node *temp = *head;
            while (n < pos - 1 && temp->next != *head)
            {
                temp = temp->next;
                n++;
            }
            if (temp->next != *head)
            {
                node *ttm = temp->next;
                temp->next = ttm->next;
                free(ttm);
                printf("\nNode deleted...\n");
            }
            else
            {
                printf("\nYou enter a number greater than the number of node!!\n");
            }
        }
    }
    else
        printf("\nList is empty...\n");
}
void display(node **head)
{
    node *ptr;
    if (*head != NULL)
    {
        printf("\n printing values: ");
        ptr = *head;
        while (ptr->next != *head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
    else
        printf("\nList is not created yet!!\n");
}
int main()
{
    node *head, *last;
    int choice, data, pos;
    while (choice != 8)
    {
        printf("\n****Main Menu****\n");
        printf("\n1.Insert at begining\n2.Insert at last\n3.Insert at specifed position.\n4.Show\n5.Delete at begin.\n6.Delete at end.\n7.Delete at specified position.\n8.Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        find_last();
        switch (choice)
        {
        case 1:
            printf("\nEnter value: ");
            scanf("%d", &data);
            Insert_at_Beginning(&head, last, data);
            printf("This is Your Linked List\n");
            display(&head);
            break;
        case 2:
            printf("\nEnter value: ");
            scanf("%d", &data);
            Insert_at_End(&head, last, data);
            printf("This is Your Linked List\n");
            display(&head);
            break;
        case 3:
            printf("\nEnter the Position:");
            scanf("%d", &pos);
            printf("\nEnter value: ");
            scanf("%d", &data);
            Insert_at_any_Position(&head, last, pos, data);
            printf("\nThis is Your Linked List\n");
            display(&head);
            break;
        case 4:
            display(&head);
            break;
        case 5:
            Delete_at_Begining(&head, last);
            printf("\nThis is Your Linked List\n");
            display(&head);
            break;
        case 6:
            Delete_at_End(&head, last);
            printf("\nThis is Your Linked List\n");
            display(&head);
            break;
        case 7:
            printf("\nPosition:\n");
            scanf("%d", &pos);
            Delete_at_any_Position(&head, last, pos);
            printf("\nThis is Your Linked List\n");
            display(&head);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nPlease enter valid choice..\n");
        }
    }
}