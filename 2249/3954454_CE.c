#include<stdio.h> 
int main()
{
	double i,n,k,t,s;long m;
	while(EOF!=scanf("%lf%lf",&n,&k)&&(n||k))
	{
		t=n-k;s=1.0;
		for(i=1;i<=k;i++)

	
			s=s*(t+i)/i;
		
	
		  m=long(s+0.1);
		  printf("%ld\n",m);
	}

    return 0; 
} 



