#include <stdio.h>
#include <math.h>
int main(void)
{
    int T=0;
    scanf("%d",&T);
    double a[1000],b[1000],c[1000];
    double S,area_0,area;
    
    for (int i=0; i<T; i++) {
        scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
    }
    for (int j=0; j<T; j++) {
        S=(a[j]+b[j]+c[j])/2;
        area_0=S*(S-a[j])*(S-b[j])*(S-c[j]);
        area=sqrt(1.0*area_0);
        printf("%.3lf\n",area);
    }
    return 0;
    
}