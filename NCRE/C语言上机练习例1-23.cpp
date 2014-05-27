#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *fun()
{
    struct node *t1, *t2, *t3;
    char ch;
    t1=(struct node *)malloc(sizeof(struct node));
    t3=t2=t1;
    ch=getchar();
    while(ch!='\n')
    {
        t2=(struct node *)malloc(sizeof(struct node));
        t2->data=ch;
        t3->next=t2;
        t3=t2;
        ch=getchar();
    }
    p->next='\0';
    return t1;
};
