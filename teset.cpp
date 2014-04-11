#include<stdio.h>
 int main()

{
    int x,y,z=0;
    for(x=0;x<=100;x++)
    {
        for(y=0;y<=100;y++)
        {
            for(z=0;z<=50;z++)
            {
                if(3*x+2*y+z==100&&x+y+2*z==100)
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
            }
        }
    }
}
