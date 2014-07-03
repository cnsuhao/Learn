#include<iostream>
using namespace std;
int main()
{
    int N,K,i,j;
    double temp;
    cin>>N>>K;
    double *p=new double[N];
    for(i=0;i<N;i++)
    {
        cin>>p[i];
    }
    for(i=0;i<N;i++)
    {
        for(j=N-1;j>1;j++)
        {
            if(p[j-1]<p[j])
            {
                temp=p[j-1];
                p[j-1]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        if(i==0 ||i==K-1)
            cout<<p[i];
    }
    delete p;
    return 0;
}