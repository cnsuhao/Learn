#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{	
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int com=gcd(a*b,c-b);
       // cout<<com<<endl;
        cout<<a*b/com<<"/"<<(c-b)/com<<endl;
    }
    return 0;
}
