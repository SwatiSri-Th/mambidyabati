#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int queue_arr[MAX];
int front = -1;
int rear = -1;
void push();
void pop();
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Quit");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\n Wrong choice.");
		}
    }
}
void display()
{
    int i;
    if(front>rear)
    {
        printf("\nDisplaying the element : ");
        for(i=front;i<rear;i++)
        {
            printf("%d",queue_arr[i]);
        }
    }
}
void push()
{
    int n;
    rear=front=0;
    printf("Enter the value : ");
    scanf("%d",&n);
    rear=rear+1;
    queue_arr[rear]=n;
}
void pop()
{
    if(front>rear)
    {
        printf("\n UNDERFLOW");
    }
    front=front-1;
}