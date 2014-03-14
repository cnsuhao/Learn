#include  <cstdio>
#include  <iostream>

using namespace std;

int main()
{
    int a=2,b;
    if(a<0) b=0;
    else if((a<5)&&(a!=2))      b=1;
    else if(a<10)       b=5;
    else        b=10;
    cout<<b<<endl;
    return 0;
}
