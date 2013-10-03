#include<stdio.h>


int main()
{
    char n[255]= {},m[255]= {};
    int n1[255]= {},m1[255]= {},s[510]= {};
    int i,j,k=0,t,x=0,dig;
    int lenn,lenm;
    scanf("%s%s",&n,&m);
    lenn=strlen(n);
    lenm=strlen(m);
    for(i=0; i<lenn; i++)
        n1[i]=n[i]-48;
    for(j=0; j<lenm; j++)
        m1[j]=m[j]-48;
    for(j=lenm-1; j>=0; j--)
    {
        t=k;
        for(i=lenn-1; i>=0; i--)
        {
            s[t]+=n1[i]*m1[j];
            t++;
        }
        ++k;
        dig=t;
    }
    for(i=0; i<dig; i++)
        while(s[i]>=10)
        {
            s[i]-=10;
            ++s[i+1];
        }
    if(s[dig]!=0)
        for(i=dig; i>=0; i--)
            printf("%d",s[i]);
    else
        for(i=dig-1; i>=0; i--)
            printf("%d",s[i]);
    return 0;
}
