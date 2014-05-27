#include <stdio.h>
#include <stdlib.h>
#define  N  8

typedef struct list
{
    int data;
    struct list *next;
}SLIST;

void fun(SLIST *h)
{
    SLIST *p,*q;
    p=h->next;
    if(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->data==q->data)
            {
                p->next = q -> next;
                free(q);
                q=p->next;
            }
            else
            {
                p=q;
                q=q->next;
            }
        }
    }
}

SLIST *creatlist(int *a)
{
    SLIST *h,*p,*q;
    int i;
    h=p=(SLIST *)malloc(sizeof(SLIST));
    for(i=0;i<N;i++)
    {
        q=(SLIST *)malloc(sizeof(SLIST));
        q->data=a[i];
        p->next=q;
        p=q;
    }
    p->next=0;
    return h;
}

void outlist(SLIST *h)
{
    SLIST *p;
    p=h->next;
    if(p==NULL)
        printf("\nThe list is NULL! \n");
    else
    {
        printf("\nHead");
        do
        {
            printf("->%d", p->data);
            p=p->next;
        }
        while(p!=NULL);
        printf("->End\n");
    }
}

int main()
{
    SLIST *head;
    int a[N]={1,2,2,3,4,4,4,5};
    head = creatlist(a);
    printf("\nThe list before deleting :\n");
    outlist(head);
    fun(head);
    printf("\nThe list after deleting :\n");
    outlist(head);
}
