#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *start;
    struct node *head=NULL;
    struct node *newnode;
    int n, i;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0;i<n; i++)
{
    newnode= (struct node *)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    if(head==NULL)
{
    head=start=newnode;
}
else
{
    start->next=newnode;
    start=newnode;
}
}
    printf("The creation of the list :");
    newnode=head;
     while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
    printf("\n Insert a node at the beginning of the list :");
    struct node *new;
 new=(struct node*)malloc(sizeof(struct node));
 printf("\n Enter the data of the new node:");
 scanf("%d",&new->data);
 new->next=head;
 head=new;
    newnode=head;
     while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
    printf("\n Insert a node at the end of the list: ");
    struct node *temp;
    new=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data of the new node: ");
    scanf("%d",&new->data);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->next=NULL;
    newnode=head;
    while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
    printf("\n Insert a node after a node :");
    new=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data of a new node :");
    scanf("%d",&new->data);
    temp=head;
    int data;
    printf("Enter the data from the list :");
    scanf("%d",&data);
    while(temp->data!=data)
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
     newnode=head;
    while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
     printf("\n Insert a node before a node :");
    struct node *newtemp;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data of a new node :");
    scanf("%d",&new->data);
    temp=head;
    printf("Enter the data from the list :");
    scanf("%d",&data);
    while (temp->data!=data)
    {
        temp=temp->next;
    }
    newtemp=head;
    while(newtemp->next!=temp)
    {
        newtemp=newtemp->next;
    }
    new->next=newtemp->next;
    newtemp->next=new;
     newnode=head;
    while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
    printf("\n Insert a node at a specific position: ");
    int pos,j=1;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter the position: ");
    scanf("%d",&pos);
        temp=head;
        while(j<pos-1)
        {
            temp=temp->next;
            j++;
        }
        printf("Enter data :");
        scanf("%d",&new->data);
        new->next=temp->next;
        temp->next=new;
     newnode=head;
    while(newnode!=NULL)
    {
        printf("%d ",newnode->data);
        newnode=newnode->next;
    }
}
