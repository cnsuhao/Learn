#include  <stdio.h>

int main()
{
    int a,b,c;
    for(a=0;a<101;a++)
        for(b=0;b<101;b++)
            for(c=0;c<101;c+=2)
                if(a+b+c==100&&3*a+2*b+c/2==100)
                    printf("%d %d %d\n", a, b, c);
    return 0;
}
