#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert();
void insertatthebeg();
void insertattheend();
void insertafteranode();
void deleteatthebeg();
void deleteattheend();
void deleteafteranode();
void display();
int main()
{
int choice,value ;
while(1)
{
    printf("\n1.Insert\n2.Insertatthebeg\n3.Insertattheend\n4.Insertafteranode\n5.Deleteatthebeg\n6.Deleteattheend\n7.Deleteafteranode\n8.Display\n9.Quit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
         case 1:
             insert();
             break;
        case 2:
            insertatthebeg();
            break;
        case 3:
            insertattheend();
            break;
        case 4:
            insertafteranode();
            break;      
        case 5 :
            deleteatthebeg();
            break;
        case 6:
            deleteattheend();  
            break;
        case 7:
            deleteafteranode();  
            break;
        case 8:
            display();  
            break;       
        case 9:
            exit(0);
        default:
        printf("\n wrong choice");   
    }
}
}   
void insert()
    {
        int value;
        struct node *ptr;
        ptr = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        ptr->data=value;
        ptr->next=NULL;
        head=ptr;
     }
     void display()
     {
         struct node *ptr;
         ptr=head;
         while(ptr!=NULL)
         {
             printf(" %d ",ptr->data);
             ptr=ptr->next;
         }
     }
     void insertatthebeg()
     {
         int value;
         struct node *temp;
         temp=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&value);
         temp->data=value;
         temp->next=head;
         head=temp;
     }
     void insertattheend()
     {
         int value;
         struct node *ptr,*temp;
         temp=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&value);
         temp->data=value;
         ptr=head;
         while(ptr->next!=NULL)
         {
             ptr=ptr->next;
         }
         ptr->next=temp;
         temp->next=NULL;
     }
     void insertafteranode()
     {
        struct node *temp,*new;
        new=(struct node *)malloc(sizeof(struct node));
        temp=head;
        printf("Enter the data of a newnode :");
        scanf("%d",&new->data);
        int data;
        printf("Enter the data from the list :");
        scanf("%d",&data);
        while(temp->data!=data)
       {
           temp=temp->next;
       }
       new->next=temp->next;
       temp->next=new;
     }
     void deleteatthebeg()
     {
         struct node *ptr;
         ptr=head;
         head=head->next;
         free(ptr);
     }
     void deleteattheend()
     {
         struct node *temp;
         temp=head;
         while(temp->next->next!=NULL)
         {
             temp=temp->next;
         }
         free(temp->next);
         temp->next=NULL;
     }
     void deleteafteranode()
     {
         struct node *temp,*newnode;
         int data;
         printf("Enter data from the list: ");
         scanf("%d",&data);
         temp=head;
         while(temp->data!=data)
         {
             temp=temp->next;
         }
         newnode=temp->next;
         temp->next=newnode->next;
         free(newnode);
     }
     