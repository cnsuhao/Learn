#include  <iostream>

using namespace std;

int main()
{
    int a=1,b=3,c=5,d=4,x;
    if(a>b)
    {
        if(c<d)     x=1;
        else
        {
            if(a<c)
            {
                if(b<d) x=2;
                else x=3;
            }
            else x=6;
        }

    }
    else x=7;
    cout<<x<<endl;
    return 0;
}
