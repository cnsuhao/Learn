#include  <stdlib.h>
#include  <time.h>
#include  <math.h>
#include  <stdio.h>

int main()
{
    int n,i=1,x;
    srand(time(0));
    n = labs(rand())%90+10;
    while(i<=20)
    {
        scanf("%d", &x);
        if(x==n)
        {
            printf("%d\n", i);
            break;
        }
        else
        {
            if(x>n)
            {
                printf("逗比，太大了！\n");
                i++;
            }
            else
            {
                printf("逗比，太小了！\n");
                i++;
            }
        }
    }
    if(i>20)
    printf("傻吊，这都不会！");
    return 0;
}
