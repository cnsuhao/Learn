#include  <stdio.h>


strcmp(char  ___(9)_____, char *p2)
/*两个字符串比较的函数*/
{
    int i；
    ____(10)______；
    while (*(pl + i) == *(p2 + i))
        if (*(p1 + i++) == '\0')
            return (0)；
                   return (*(pl + i) - * (p2 + i)); /*不等时返回结果为第一个不等字符ASCII码的差值*/
}


int main()
{
    int m；
    char  ___(6)____，str2[20]，*p1, *p2；
    printf("Input two string：\n")；
    scanf("%s", strl)；
    scanf("%s"，___(7)______);
    p1 = &strl[0];
    p2 = _____(8)_____;
    m = strcmp(p1, p2)；
        printf("result:%d,\n", m);
    return 0;
}
