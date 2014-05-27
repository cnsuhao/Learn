/*

#include <math.h>
#include <stdio.h>
double  fun(int  n)
{



}
int  main()
{
	int  n;
	double  s;
	printf("\n\nIput n:  ");
	scanf("%d",&n);
	s=fun(n);
	printf("\n\ns=%f\n\n",s);
}
**/

#include <math.h>
#include <stdio.h>
double  fun(int  n)
{

	int i;
	double s=1,p=1;
	for (i=2;i<=n;i++)
	{
		p+=pow(i,0.5);
		s+=p;
	}
	return s;

}

int main()
{
	int  n;
	double  s;
	printf("\n\nIput n:  ");
	scanf("%d",&n);
	s=fun(n);
	printf("\n\ns=%f\n\n",s);
}
