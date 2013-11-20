/*
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
void main()
{
	double a[200],b[200],c[200],s,z;
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<x;i++)
	{
	s=(a[i]+b[i]+c[i])/2;
	z=sqrt(double(s*(s-a[i])*(s-b[i])*(s-c[i])));
    printf("%.3lf",z);
	cout<<endl;
	}

}
*/

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    double a[100],b[100],c[100],s,z;
    int x;
    cin>>x;
    for(int i=0; i<x; i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=0; i<x; i++)
    {
        s=(a[i]+b[i]+c[i])/2;
        z=sqrt((s*(s-a[i])*(s-b[i])*(s-c[i])));
        printf("%.3lf",z);
        cout<<endl;
    }
    return 0;
}
