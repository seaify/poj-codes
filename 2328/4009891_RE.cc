#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,c,max,min;char a[15][15];
	i=1;	max=0;min=11;c=1;
	while(1)
	{  
		scanf("%d",&n);
		if(n==0)break;
        gets(a[i]);

		if(strcmp(a[i],"right on")==0)
		{
			if(max==0||min==11)
				printf("Stan may be honest\n");
			else if(n>max||n<min)
			{
				c=0;
			if(c)	 
			printf("Stan may be honest\n");
		     else
			printf("Stan is dishonest\n");
			}
		i=1;	max=0;min=11;c=1;
			   
		}
		else if(strcmp(a[i],"too high")==0)
		{
			if(n>max)
			     max=n-1;
			else
				c=0;
		}
		else if(strcmp(a[i],"too low")==0)
		{	if(n<min)
		        min=n-1;
			else
				c=0;
		}
		i++;
	}
	return 0;
}

				  
			  
		 
		
		
				
		
