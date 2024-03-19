#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node * head = NULL;
void insert();
void delete();
void display();
int main()
{
int value;
int choice=value ;
while(1)
{
    printf("\n1.Insert\n2.Insertatthebeg\n3.Insertattheend\n4.Delete\n5.Display\n6.Quit\n");
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
       /* case 4 :
            delete();