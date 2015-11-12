#include<stdio.h>
#include<math.h>
int n,T,result;

const double pi=acos(-1);
const double e=exp(1);

int main()
{
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d",&n);
         
         result=int(n*log10(n/e)+0.5*log10(2*pi*n));
         
         printf("%d\n",result+1); 
         
    }
    return 0;
} 
