#include <stdio.h>
#include <math.h>
#define CONST 1.42e8
int main(void)
{
    int i=0;
    
    double sum=0;
    double volum=0;
    
    for (i=0; i<64; i++) {
        sum+=pow(2,i);
        
    }
    
    volum=sum/CONST;
    
    printf("sum = %1.6e\nvolum = %1.6e",sum,volum);
    return 0;
}