#include<stdio.h>
#include<string.h>
int i;
bool a[50005];
int main()
{
	memset(a,true,sizeof(a));
	for(i=1;i<10000;i++)
	{				  
		a[i+i%10+(i%100)/10+(i%1000)/100+i/1000]=false;		
	  if(a[i])
	   printf("%d\n",i);
	} 
}

