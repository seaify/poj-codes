#include<stdio.h>
#include<string.h>
#define MAX 120
int x[MAX];
void f(char *a)
{   int len1,i,j,y[MAX];
	len1=strlen(a);
	memset(y,0,sizeof(y));
	j=0;
	for(i=len1-1;i>=0;i--)
          y[j++]=a[i]-'0';
	for(i=0;i<MAX;i++)
	{
		x[i]+=y[i];
		if(x[i]>=10)
		{
			x[i]-=10;
			x[i+1]++;
		}
	}
}
int main()
{   int i,c;char a[MAX];
    memset(x,0,sizeof(x));
	while(EOF!=scanf("%s",a))
	{
		if(strcmp(a,"0")==0)
		{
			c=0;
			for(i=MAX;i>=0;i--)
				if(c)
					printf("%d",x[i]);
				else  if(x[i])
				{
					printf("%d",x[i]);
					c=1;
				}
		 if(!c)	
			printf("0");
		 printf("\n");
		 break;
		}		
		f(a);
	}
	return 0;
}

		

	
	




