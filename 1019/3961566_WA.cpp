#include<stdio.h>
#include<math.h>
int main()
{
	long max,min,i,j,k,t;
    __int64 c,d;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&i); d=2*i;
		min=sqrt(d-1.0/4)-1.5;
		max=sqrt(d-1.0/4)-0.5;
		for(j=min;j<=max;j++)
		{
			c=j*j+j;
		    c=c/2;
			if(c>i)
				break; 
		}
		j=j-1;
		c=((j+1)*j)/2;   
			printf("%ld\n",i-c);
	}
	return 0;
}
			
	
           
