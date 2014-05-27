#include  <stdio.h>
#include  <string.h>

int main()
{
    char p1[10]="abc", p2[]="ABC", str[50]="xyz";
    strcpy(str+3, strcat(p1,p2));
    printf("%s\n", str);
    return 0;
}
