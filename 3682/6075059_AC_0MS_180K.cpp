#include<stdio.h>

int n;

double p;

int main()
{
    
    while(EOF!=scanf("%d",&n)&&n)
    {
         scanf("%lf",&p); 
         printf("%.3lf %.3lf\n",n/p,double(n*(n+1))/(p*p)-double(n)/p);
    }
    return 0;  
  
}
