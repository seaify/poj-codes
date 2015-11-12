#include<stdio.h> 
int main()
{
	double i,n,k,t,s;long m;
	while(EOF!=scanf("%lf%lf",&n,&k)&&(n||k))
	{  
	     t=n-k;s=1.0;
		for(i=k;i>=1;i--)
                     
		{

			s=(s/i);
		    s=s*(t+i);
		}
		
	
		  m=long(s+0.1);
		  printf("%ld\n",m);
	}

    return 0; 
} 



