#include<stdio.h>   
#include<math.h>  
#define EXP 1e-9  
int main()  
{  
    int n;double k,p;  
    long m;  
    while(EOF!=scanf("%d%lf",&n,&p))  
    {  
        k=pow(p,1.0/n);  
        m=long(k+0.1);  
        if(fabs(m-k)<EXP||fabs(m+1-k)<EXP)  
            printf("%.0lf\n",k);  
    }   
    return 0;      
}     

