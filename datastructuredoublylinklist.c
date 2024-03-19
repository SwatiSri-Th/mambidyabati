#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
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
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&value);
        temp->data=value;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
}
void display()
{
     struct node *temp;
         temp=head;
         while(temp!=NULL)
         {
              printf(" %d ",temp->data);
             temp=temp->next;
         }   
}
void insertatthebeg()
{
    int value;
         struct node *temp;
         temp=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&value);
         temp->data=value;
         temp->prev=NULL;
         temp->next=head;
         head->prev=temp;
         head=temp;
}
void insertattheend()
{
    int value;
         struct node *temp,*ptr;
         ptr=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&value);
         ptr->data=value;
         temp=head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
         temp->next=ptr;
         ptr->prev=temp;
         ptr->next=NULL;
}
void insertafteranode()
{
    struct node *temp,*ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        temp=head;
        printf("Enter the data of a newnode :");
        scanf("%d",&ptr->data);
        int data;
        printf("Enter the data from the list :");
        scanf("%d",&data);
        while(temp->data!=data)
        {
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next->prev=ptr;
        ptr->prev=temp;
        temp->next=ptr;
}
void deleteatthebeg()
{
    struct node *temp;
         temp=head;
         head=head->next;
         free(temp);
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
    struct node *temp,*ptr;
         int data;
         printf("Enter data from the list: ");
         scanf("%d",&data);
         temp=head;
         while(temp->data!=data)
         {
             temp=temp->next;
         }
         ptr=temp->next;
         temp->next=ptr->next;
         ptr->next->prev=temp;
         free(ptr);
}