#include <stdio.h>
#include <stdlib.h>
 typedef struct node
{
    struct node *prev, *next;
    int data;
}node;

void insertion(node **head,int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(*head == NULL)
    {
        
        *head=new_node;
    }
    else{
        node *tmp=*head;
        while (tmp->next!=NULL)
        {
         tmp=tmp->next;   
        }
        tmp->next=new_node;
        new_node->prev=tmp;
        
    }
}
void insert_at_end(node **head,int pos,int data)
{
    node *tmp=*head;
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    int count=1;
    while(tmp->next!=NULL&&count<pos)
    {
        tmp=tmp->next;
        count++;
    }
     new_node->prev=tmp->prev;
     tmp->prev->next=new_node;
    new_node->next=tmp;
    tmp->prev=new_node;
   
}

void insert_at_begining(node **head,int data)
{
    node *new_node=(node *)malloc((sizeof(node)));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(*head == NULL)
    {
        
        *head=new_node;
    }
    else{
        new_node->next=*head;
        (*head)->prev=new_node;
        *head=new_node;
    }

}
void display( node *head)
{
     node* tmp=head;

    while(tmp!=NULL)
    {
        
        printf("%d\t",tmp->data);
        tmp=tmp->next;
    }
}
void Delete_head(node **head)
{
    node* tmp=*head;
    if(*head==NULL)
    {
        printf("you cannot perform deletion in an empty linked list\n");
    }
    else{
        if (tmp->next!=NULL)
        {
            (*head)=(*head)->next;
            (*head)->prev=NULL;
            free(tmp);
        }
        else{
            free(*head);
        }
        
      }
}
void Delete_last(node **head)
{
    node *tmp= *head;
    while(tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }
    if(tmp->next!=NULL){
    node *temp;
    temp=tmp->next;
    tmp->next=NULL;
    free(temp);
    }
    else{
        Delete_head(head);
    }
}
void insertAtPosition(node **head,int data,int pos){
   node *temp = (node*)malloc(sizeof(node));
   int n=1;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        node *sbb =*head;
        while(sbb->next!=NULL && n<pos-1){
            sbb = sbb->next;
            n++;
        }
        temp->next=sbb->next;
        temp->prev=sbb;
        sbb->next=temp;
    }
    printf("Successful\n");
}
void Delete_at_pos(node **head,int pos)
{
   int count = 1;
   node *tmp=*head;
   while(count<pos&& tmp->next!=NULL)
   {
    tmp=tmp->next;
    count++;
   }
   if(tmp->next!=NULL)
   {
    tmp->prev->next=tmp->next;
    tmp->next->prev=tmp->prev;
    free(tmp);
   }
   else{
    if(count==pos)
    {
        Delete_last(head);
    }
   }
}
void reverse_doubly(node **head)
{
    node *tmp;
    tmp=*head;
    node *temp;
    while(tmp->next!=NULL)
    {
        
        temp->next=tmp->next;
        tmp->next=tmp->prev;
        tmp->prev=temp->next;
        tmp=temp->next;
    }
    temp->next=tmp->next;
    tmp->next=tmp->prev;
    tmp->prev=temp->next;
    *head=tmp;
    free(temp);
}
void deleteEntireDoublyLinkedList(node *head)
{
    while (head != NULL)
    {
        Delete_head(head);
        head = head -> next;
    }
    if (head == NULL)
    {
        printf("\n Entire Doubly Linked List has been Deleted \n");
    }
}
int main()
{
    node *head;
    head=NULL;
    int choice,d,pos;
    while(1)
    {
        printf("\n*****press*****\n");
        printf("1--> to enter an element at end\n");
        printf("2--> to enter an element at begining\n");
        printf("3--> to enter an element at any position\n");
        printf("4--> to delete an element at position\n");
        printf("5--> to delete the head element\n");
        printf("6--> to delete the last element\n");
        printf("7--> to reverse the doubly linkedlist\n");
        printf("8--> to delete the entire list\n");
        printf("9--> to exit from menu\n");
        scanf("%d",&choice);
        
       switch(choice)
       {
          case 1:printf("Enter the element to insert at end\n");
                 scanf("%d",&d);
                 insertion(&head,d);
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
                
                 
                 if(pos==1||head==NULL)
                 {
                    insert_at_begining(&head,d);
                 }
                 else
                 insertAtPosition(&head,d,pos);

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
                   if(pos==1)
                   {
                    Delete_head(&head);
                   }
                   else{
                    Delete_at_pos(&head,pos);
                   }
                }
                if(head!=NULL)
               display(head);
               else
               printf("Entire list has been deleted\n");
                break;
        
               
        case 5:printf("Deleting the head element\n");
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                Delete_head(&head);
               }
               if(head!=NULL)
               display(head);
               else
               printf("Entire list has been deleted\n");
               break;
        case 6:printf("Deleting the last element\n");
               if(head==NULL)
               {
                printf("Head is already NULL\n");
               }
               else{
                Delete_last(&head);
               }
               if(head!=NULL)
               display(head);
               else
               printf("Entire list has been deleted\n");
               break;
        case 7: printf("The Linkedlist has been reversed\n");
                reverse_doubly(&head);
                display(head);
                break;
        case 8: printf("The Linked List is Totally Deleted\n");
                deleteEntireDoublyLinkedList(&head);
                display(head);
                break;        
        case 9:printf("Thanks for using:)");
                 exit(1);
          default:printf("Wrong input enter again");
        }
    }
    return 0;
}
