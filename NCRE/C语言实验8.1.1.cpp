#include  <stdio.h>

int main()
{
    char a[] = "-123456";
    int k=0,symbol,m;
    if(a[k]=='+'||a[k]=='-')
        symbol=(a[k]=='+')?1:-1;
    for(m=0,k=1;a[k]>='0'&&a[k]<='9';k++)
    {
        m=m*10+a[k]-'0';
    }
    printf("number=%d\n", symbol*m);
    return 0;
}
