#include<stdio.h> 
int main()
{
	double i,n,k,t,s;long m;
	while(EOF!=scanf("%lf%lf",&n,&k)&&(n||k))
	{    
	     if(k>n/2)
			 t=n-k;
		 else
			 t=k;
		 s=1.0;
		for(i=t;i>=1;i--)
                     
		{

			s=(s/i);
		    s=s*(n-t+i);
		}
		
	
		  m=long(s+0.1);
		  printf("%ld\n",m);
	}

    return 0; 
} 



