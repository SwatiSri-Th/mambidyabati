#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert();
void delete();
void display();
int main()
{
	struct node *head=NULL;
	int choice,value;
	while(1)
	{
		printf("\n 1.Insert \n 2. Delete \n 3. Display \n 4. Quit");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
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
	void insert()
	{
		int value;
		printf("\n Creation of a nodes :");
		struct node *ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the nodes:\n");
		scanf("%d",&value);
		ptr->data=value;
		ptr->next=NULL;
		head=ptr;
		
		int n;
		printf("\nInsertion at the beginning:");
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the number to be inserted:\n");
		scanf("%d",&n);
		temp->data=n;
		temp->next=head;
		head=temp;
		
		int m;
		printf("\nInsertion at the end:");
		struct node *ap=(struct node*)malloc(sizeof(struct node));
		ptr=head;
		printf("\nEnter the number to be inserted:\n");
		scanf("%d",&m);
		ap->data=m;
		ptr->next=ap;
		ap->next=NULL;
		
		int item;
		printf("\nInsertion after a node:");
		struct node *tmp2;
		temp=(struct node*)malloc(sizeof(struct node));
		tmp2=head;
		printf("\nEnter the node to be inserted:\n");
		scanf("%d",&item);
		while(tmp2!=NULL)
		{
			if(tmp2->data==value)
			{
				temp->data=item;
				temp->next=tmp2->next;
				tmp2->next=temp;
			}
			tmp2=tmp2->next;
		}
		
		int no;
		printf("\n Transversing node and insert at the end :");
		struct node *temp2;
		temp=(struct node *)malloc(sizeof(struct node));
		temp2=head;
		printf("\nEnter the node to be inserted at end :\n");
		scanf("%d",&no);
		temp->data=no;
		while(temp2->next!=NULL)
		{
			temp2=temp2->next;
		}
		temp2->next=temp;
		temp->next=NULL;
	}
	
	void delete()
	{
		/*struct node *tmp;
		tmp=head;
		free(tmp);
		head=NULL;*/
		int ptr;
		printf("\nDeleting a single node at a beginning:");
		ptr=head;
		head=head->next;
		free(ptr);
		
		printf("\nDeleting a single node at end:");
		struct node *prev;
		prev=head;
		while(prev->next->next!=NULL)
		{
			prev=prev->next;
		}
		free(prev->next);
		prev->next=NULL;
	}
	
void display()
{
	struct node *p;
	p=head;
	printf("\nDisplay the nodes:\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}