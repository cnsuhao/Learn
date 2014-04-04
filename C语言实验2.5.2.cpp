#include<stdio.h>
main()
{
    int score,c;
    scanf("%d",&score);
    c=score/10;
    switch(c)
    {
        case 10: printf("excellent");break;
        case 9:printf("great");break;
        case 8:printf("good");break;
        case 7:printf("not bad");break;
        case 6:printf("fighting");break;
        default :printf("get out");

    }
    return 0;
}
