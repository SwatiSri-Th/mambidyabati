#include<stdio.h>
int main()
{
    int i,j,s[7][5];
    printf("Enter the values : ");
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    for(i=1;i<=5;i++)
    {
        printf("P%d   ",i);
        for(j=1;j<=3;j++)
        {
            printf("%d  ",s[i][j]);
        }
        printf("\n");
    }

}