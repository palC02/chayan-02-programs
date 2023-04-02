#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
void insert_at_end(node **head, int n)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = n;
    node *tmp = *head;
    if (*head == NULL)
    {
        *head = new_node;
        (*head)->next = *head;
    }
    else
    {
        while (tmp->next != *head)
        {
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
}
void insert_at_begining(node **head,int n)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = n;
    node *tmp = *head;
    if (*head == NULL)
    {
        *head = new_node;
        (*head)->next = *head;
    }
    else
    {
        while (tmp->next != *head)
        {
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
        *head=new_node;
    }
}
void display(node *head)
{
    node *tmp;
    tmp = head;
    
    do{
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }while(tmp!=head);
     printf("\n");
}
void insert_at_pos(node ** head,int n,int pos)
{
    
    if(pos==1||*head==NULL)
    {
        insert_at_begining(head, n);
    }
    else{
        int count = 1;
        node *hr=*head;
        while(hr->next!=*head &&count<pos-1)
        {
            hr=hr->next;
            count ++;
        }
        if(hr->next==*head)
        {
            insert_at_end(head, n);
        }
        else{
            node *new_node=(node *)malloc(sizeof(node));
            new_node->data=n;
            new_node->next=hr->next;
            hr->next=new_node;
        }
    }
}
void delete_begining(node **head)
{
    if(*head!=NULL){
    node *hr=*head;
    while (hr->next!=*head)
    {
        hr=hr->next;
    }
    node* temp=hr->next;
    hr->next=hr->next->next;
    *head=hr->next;
    free(temp);
    }
}
void delete_end(node **head)
{
    if(*head!=NULL){
    node *hr=*head;
    while (hr->next->next!=*head)
    {
        hr=hr->next;
    }
    node* temp=hr->next;
    hr->next=hr->next->next;
    
    free(temp);
    }
}
void delete_at_pos(node **head,int pos)
{
   if(pos==1)
    {
        delete_begining(head);
    }
    else{
        int count = 1;
        node *temp=*head;
        while(temp->next!=*head &&count<pos-1)
        {
            temp=temp->next;
            count ++;
        }
        if(temp->next==*head)
        {
            delete_end(head);
        }
        else{
           node *tmp=temp->next; 
           temp->next=temp->next->next;
            free(tmp);
        }
    } 
}
int getSize(node *head){
    int size=1;
    node *tmp=head;
    while (tmp->next!=head)
    {
        size++;
        tmp=tmp->next;
    }
    return size;
}

int main()
{
    node *head;
    head=NULL;
    int ch,d,pos;
    while(1)
    {
        printf("\npress\n");
        printf("1--> to enter an element at end\n");
        printf("2--> to enter an element at begining\n");
        printf("3--> to enter an element at position\n");
        printf("4--> to delete an element at position\n");
        printf("5--> to delete the head element\n");
        printf("6--> to delete the last element\n");
        printf("7--> to exit from menu\n");
        scanf("%d",&ch);
        
       switch(ch)
       {
          case 1:printf("Enter the element to insert at end\n");
                 scanf("%d",&d);
                 insert_at_end(&head,d);
                 display(head);
                 break;
          case 2:printf("Enter the element to insert\n");
                 scanf("%d",&d);
                 insert_at_begining(&head,d);
                 display(head);
                 break;
          case 3:printf("Position:");
                 scanf("%d",&pos);
                 printf("Enter element:");
                 scanf("%d",&d);
                
                 insert_at_pos(&head,d,pos);
                 display(head);
                 break;
          case 4: printf("Enter position:");
                scanf("%d",&pos);
                printf("\n");
                if(head==NULL)
                {
                    printf("You can not perform deletion on an empty array\n");
                }
                  else{
                    delete_at_pos(&head,pos);
                   }
                
                display(head);
                break;
          case 5:printf("Deleting the head element\n");
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                delete_begining(&head);
               }
               display(head);
               break;
          case 6:printf("Deleting the last element\n");
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                delete_end(&head);
               }
               display(head);
               break;
          case 7:printf("Thanks for using:)");
                 exit(1);
          default:printf("Wrong input enter again");
        }
    }
}
