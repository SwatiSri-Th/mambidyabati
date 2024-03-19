#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert();
void insertatbeg();
void insertatend();
void insertafternode();
void deleteatbeg();
void deleteatend();
void deleteafteranode();
void display();
int main()
{
    int choice, value;
    while(1)
    {
    printf("\n 1.Insert \n 2.Insertatbeg \n 3.Insertatend \n 4.Insertafternode \n 5.Deleteatbeg \n 6.Deleteatend \n 7.deleteafteranode \n 8.Display \n 9.Quit");
    printf("\n Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insert();
            break;
        case 2:
            insertatbeg();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertafternode();
            break;
        case 5:
            deleteatbeg();
            break;
        case 6:
            deleteatend();
            break;
        case 7:
            deleteafteranode();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default :
        printf("\n Wrong choice");
    }
    }
}
    void insert()
    {
        struct node *ptr;
        int value;
        ptr=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&value);
        ptr->data=value;
        ptr->next=NULL;
        head=ptr;
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
void insertatbeg()
    {
        struct node *ptr;
        int value;
        ptr=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&value);
        ptr->data=value;
        ptr->next=head;
        head=ptr;
    }
void insertatend()
    {
        struct node *temp,*ptr;
        int value;
        ptr=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&value);
        ptr->data=value;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
    }
void insertafternode()
{
    struct node *temp,*ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    temp=head;
    printf("Enter the newnode :");
    scanf("%d",&ptr->data);
    int data;
    printf("Take the data from the list :");
    scanf("%d",&data);
    while(temp->data!=data)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}
void deleteatbeg()
    {
        struct node *temp;
        temp=head;
        head=head->next;
        free(temp);
    }
void deleteatend()
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
    struct node *temp,*temp2;
    int data;
    printf("Take data from the list :");
    scanf("%d",&data);
    temp=head;
    while(temp->data!=data)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}