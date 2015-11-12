#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,c,d,e,flag[15],max,min;char a[15][15];
	i=1;
	while(1)
	{   memset(flag,0,sizeof(flag));
		scanf("%d",&n);
		if(n=0)break;
        gets(a[i]);
		if(i=1){max=10;min=1;c=1;d=1;e=1;}
		if(strcmp(a[i],"right on")==0)
		{
			if(n>max||n<min)
				c=0;
				  
			  
		  if(c)	 
			printf("Stan may be honest\n");
		else
			printf("Stan is dishonest\n");i=1;
			   
		}
		else if(strcmp(a[i],"too high")==0)
		{
			if(n>max)
			     max=n-1;
			else
				c=0;
		}
		else
		{	if(n<min)
		        min=n-1;
			else
				c=0;
		}
		
		i++;
	}
	return 0;
}

				
		
	
			
	

	
		
	

  
		

  
	
	