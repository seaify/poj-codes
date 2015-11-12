#include<stdio.h>   
#include<math.h>  
int main()  
{  
	long i,k,n,min;
	while(EOF!=scanf("%ld",&n))
	{
		printf("TERM %ld IS ",n);
		min=sqrt(2*n+1.0/4)-1.5;
		for(i=min; ;i++)
			if(i*i+i>=2*n)
				break;   
				k=(i*(i+1))/2-n;
			if(i%2==0)
                  printf("%ld/%ld\n",i-k,k+1);
			else
				printf("%ld/%ld\n",k+1,i-k);

	}
   
    return 0;      
}     
			
			    
			 
		


