#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int data;
 struct node *link;
}node;
void insert_at_pos(struct node **head,int pos,int n)
{
 int count=1;
 node *tmp= (node*)malloc(sizeof(node));
 node *temp=*head;
 while(temp->link!=NULL&&count<pos-1)
 {
 temp=temp->link;
 count++;
 }
 tmp->data=n;
 tmp->link=temp->link;
 temp->link=tmp;
}
void insert(struct node **head ,int n)
{

 node* new_node = (node*)malloc(sizeof(node));
 new_node->data=n;
 new_node->link=NULL;
 if (*head==NULL)
  {
 *head=new_node;
 }
 else{
 node *ttm=*head;
 while(ttm->link!=NULL)
 {
 ttm=ttm->link;
 }
 ttm->link=new_node;
}
}
void insert_at_begining(node** head,int n)
{
 node* new_node=(node*)malloc(sizeof(node));
 new_node->data=n;
 if(*head==NULL)
 {
 *head=new_node;
 new_node->link=NULL;
 }
 else{
 new_node->link=*head;
 *head=new_node;
 }
}
int getSize(node* head){
 int size=1;
 node *tmp=head;
 while (tmp->link!=NULL)
 {
 size++;
 tmp=tmp->link;
 }
 return size;
}
void display( node* head)
{
 node* tmp=head;
 while(tmp!=NULL)
 {
 printf("%d\t",tmp->data);
 tmp=tmp->link;
 }
}
void reverse_list(node **head)
{
 int size,i,j;
 size=getSize(*head);
 for(i=0;i<size-1;i++)
 {
 node* tmp,*ttm;
 tmp=*head;
 ttm=(*head)->link;
 for(j=1;j<=size-1-i;j++)
 {
 int temp=tmp->data;
 tmp->data=ttm->data;
 ttm->data=temp;
 tmp=tmp->link;
 ttm=ttm->link;
 }
 }
}
int main()
{
 node* head;
 head=NULL;
 int choice,n,pos;
 while(1)
 {
 printf("\npress\n");
 printf("1--> to enter an element at end\n");
 printf("2--> to enter an element at begining\n");
 printf("3--> to enter an element at position\n");
 printf("4--> to reverse the linked list\n");
 printf("5--> to exit from menu\n");
 scanf("%d",&choice);

 switch(choice)
 {
 case 1:printf("Enter the element to insert at end\n");
 scanf("%d",&n);
 insert(&head,n);
 display(head);
 break;
 case 2:printf("Enter the element to insert\n");
 scanf("%d",&n);
 insert_at_begining(&head,n);
 display(head);
 break;
 case 3:printf("Position:");
 scanf("%d",&pos);
 printf("Enter element:");
 scanf("%d",&n);

 if(pos==1||head==NULL)
 {
 insert_at_begining(&head,n);
 }
 else{
 insert_at_pos(&head,pos,n);}
 display(head);
 break;
 case 4:printf("Reversing the linked list\n");
 reverse_list(&head);
 display(head);
 break;
 case 5:printf("Thanks for using:)");
 exit(1);
 break;
 default:printf("Wrong input enter again");
 }
 }
 return 0;
}