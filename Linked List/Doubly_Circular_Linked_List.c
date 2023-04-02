#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;
void insert_at_end(node **head, node **last, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    if (*head == NULL && *last == NULL)
    {
        *head = new_node;
        *last = *head;
        (*head)->next = *last;
        (*head)->prev = *last;
    }
    else
    {
        (*last)->next = new_node;
        new_node->prev = *last;
        new_node->next = *head;
        *last = new_node;
        (*head)->prev = *last;
    }
}
void insert_at_begining(node **head, node **last, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    if (*head == NULL && last == NULL)
    {
        insert_at_end(head, last, data);
    }
    else
    {

        new_node->next = *head;
        (*head)->prev = new_node;
        new_node->prev = *last;
        (*last)->next = new_node;
        *head = new_node;
    }
}

void display(node *head)
{
    node *tmp;
    tmp = head;

    do
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
    printf("\n");
}
void insert_at_pos(node **head, node **last, int data, int pos)
{

    if (pos == 1 || *head == NULL)
    {
        insert_at_begining(head, last, data);
    }
    else
    {
        int count = 1;
        node *tmp = *head;
        while (tmp != *last && count < pos - 1)
        {
            tmp = tmp->next;
            count++;
        }
        if (tmp == *last)
        {
            insert_at_end(head, last, data);
        }

        else
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = data;
            new_node->next = tmp->next;
            new_node->prev = tmp;
            tmp->next->prev = new_node;
            tmp->next = new_node;
        }
    }
}
void delete_begining(node **head, node **last)
{
    node *tmp = *head;
    if (*head != NULL)
    {

        (*head) = (*head)->next;
        (*head)->prev = *last;
        (*last)->next = *head;
        free(tmp);
    }
}
void delete_end(node **head, node **last)
{
    if (*head != NULL)
    {
        node *tmp = *last;
        (*last) = (*last)->prev;
        (*last)->next = (*head);
        (*head)->prev = (*last);
        free(tmp);
    }
}
void delete_entire_list(node **head, node **last)
{
    while (*head != *last)
    {
        delete_end(head, last);
    }
    free(head);
    printf("Entire list deleted\n");
}
void delete_at_pos(node **head, node **last, int pos)
{
    if (pos == 1)
    {
        delete_begining(head, last);
    }
    else
    {
        int count = 1;
        node *tmp = *head;
        while (tmp != *last && count < pos - 1)
        {
            tmp = tmp->next;
            count++;
        }
        if (tmp == *last && count < pos - 1)
        {
            return;
        }
        else
        {
            if (tmp->next == *last)
            {
                delete_end(head, last);
            }
            else
            {
                node *temp = tmp->next;
                tmp->next = tmp->next->next;
                tmp->next->next->prev = tmp;
                free(temp);
            }
        }
    }
}
int main()
{
    node *head;
    node *last;
    last = NULL;
    head = NULL;
    int choice, d, pos;
    while (1)
    {
        printf("\n*****press*****\n");
        printf("1--> to enter an element at end\n");
        printf("2--> to enter an element at begining\n");
        printf("3--> to enter an element at position\n");
        printf("4--> to delete an element at position\n");
        printf("5--> to delete the head element\n");
        printf("6--> to delete the last element\n");
        printf("7--> to exit from menu\n");
        printf("8--> to delete entire list\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert at end\n");
            scanf("%d", &d);
            insert_at_end(&head, &last, d);
            display(head);
            break;
        case 2:
            printf("Enter the element to insert\n");
            scanf("%d", &d);
            insert_at_begining(&head, &last, d);
            display(head);
            break;
        case 3:
            printf("Position:");
            scanf("%d", &pos);
            printf("Enter element:");
            scanf("%d", &d);

            insert_at_pos(&head, &last, d, pos);
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
                delete_at_pos(&head, &last, pos);
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
                delete_begining(&head, &last);
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
                delete_end(&head, &last);
            }
            display(head);
            break;
        case 7:
            printf("Thanks for using:)");
            exit(1);
        case 8:
            printf("Entire List is Deleted\n");
            delete_entire_list(&head, &last);
            break;
        default:
            printf("Wrong input enter again");
        }
    }
}
