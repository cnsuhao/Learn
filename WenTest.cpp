#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double x1,y1,x2,y2,r1,r2;
	while(cin>>x1)
	{
		cin>>y1>>r1>>x2>>y2>>r2;
		if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1+r2)*(r1+r2)||(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==((r1-r2)*(r1-r2)))
		{
			cout<<"1";
		}
		if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>(r1+r2)*(r1+r2)*(r1+r2))
		{
			cout<<"2";
		}
		if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<r1+r2&&(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>((r1-r2)*(r1-r2)))
		{
			cout<<"4";
		}
		if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>((r1-r2)*(r1-r2)))
		{
			cout<<"3";
		}
	}
	return 0;
}
