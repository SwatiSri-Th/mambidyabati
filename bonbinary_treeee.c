#include <stdio.h>
#include <stdlib.h>
struct  node
{
    int data;
    struct node *left_child,*right_child;
};
struct node *newnode(int info);
struct node *creation(struct node *root);
struct node *insertion(struct node *root,int info);
struct node *deletion(struct node *root,int info);
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
int main()
{
    struct node *root=NULL;
    int choice,info;
    while(1)
    {
        printf("\n1.Creation\n2.Insertion\n3.Display Preorder\n4.Display Postorder\n5.Display Inorder\n6.Deletion\nEnter a choice :- ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            root=creation(root);
            break;
        case 2:
            printf("Enter the data :- ");
            scanf("%d",&info);
            root=insertion(root,info);
            break;
        case 3:
          printf("Preorder:- ");
            preorder(root);
            break;
        case 4:
        printf("Postorder:- ");
            postorder(root);
            break;
        case 5:
         printf("Inorder:- ");
            inorder(root);
            break;        
        case 6:
            printf("Enter the data to be deleted:- ");
            scanf("%d",&info);
            root=deletion(root,info);
            break;
        default:
            printf("Invalid");
            break;
        }
    }
}
struct node *creation(struct node *root)
{
    int i,n,info;
    printf("Enter the no. of elements:- ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the data %d :- ",i);
        scanf("%d",&info);
        root=insertion(root,info);
    }
    return root;
}
struct node *newnode(int info)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=info;
    new->left_child=new->right_child=NULL;
    return new;
}
struct node *insertion(struct node *root,int info)
{
    if(root==NULL)
    {
        return newnode(info);
    }
    else
    {
        if(info<root->data)
        {
            root->left_child=insertion(root->left_child,info);
        }
        else if(info>root->data)
        {
            root->right_child=insertion(root->right_child,info);
        }
        else
        {
            printf("Duplicate elements");
        }
    }
    return root;
}
struct node *deletion(struct node *root,int info)
{
    struct node *temp,*succ;
    if(root==NULL)
    {
        printf("%d is not found",info);
    }
    else
    {
        if(info<root->data)
        {
            root->left_child=deletion(root->left_child,info);
        }
        else if(info>root->data)
        {
            root->right_child=deletion(root->right_child,info);
        }
        else
        {
            if(root->left_child!=NULL && root->right_child!=NULL)
            {
                succ=root->right_child;
                while(succ->left_child!=NULL)
                {
                    succ=succ->left_child;
                }
                root->data=succ->data;
                root->right_child=deletion(root->right_child,succ->data);
            }
            else
            {
                temp=root;
                if(root->left_child!=NULL)
                {
                    root=root->left_child;
                }
                else if(root->right_child!=NULL)
                {
                    root=root->right_child;
                }
                else
                {
                    root=NULL;
                }
                free(temp);
                return root; 
            }
        }
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left_child);
		preorder(root->right_child);
		
	}
}
void postorder(struct node *root)
{
    
	if(root!=NULL)
	{
		postorder(root->left_child);
		postorder(root->right_child);
		printf("%d ",root->data);
	}
}
void inorder(struct node *root)
{
   
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf("%d ",root->data);
        inorder(root->right_child);
    }
}
