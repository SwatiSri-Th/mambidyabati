//#include<stdio.h>
int main()
{
    struct a
    {
        char ch[7];
        char *str;
    };
    struct b
    {
        char *c;
        struct a ssd;
        struct b s2={"Raipur","Kanpur","Jaipur"};
        printf("%s",s2.ssd.str);
        printf("%s %s",++s2.c,++s2ssd.str);
    }
}