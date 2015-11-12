#include<stdio.h>
#include<string.h>
int main()
{
	int a[15],b[15],flag[15],d[15],i,j,c,k,t;	
	memset(flag,1,sizeof(flag));
	for(i=1;i<=12;i++)
		scanf("%d",&d[i]);
	for(i=1;i<12;i++)
		for(j=i+1;j<=12;j++)
			if(d[i]<d[j])
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
			k=3;
   for(i=1;i<=k;i++)
   {
	   if(d[i]==d[i+1])
			c=1;
	    else
			c=0;
		if(i==3||i==7)
		{i+=1;k+=3;}
   }
   if(c)
   {   c=0;
   for(i=1;i<=6;i++)
		b[i]=d[2*i];
	for(i=1;i<=6;i++)
		a[i]=d[2*i-1];
	

	   for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
			if(i!=j&&flag[i]&&flag[j])
			{
				if((a[i]==a[j]&&b[i]==b[j])||(a[i]==b[j]&&b[i]==a[j]))
				{
				    flag[i]=0;flag[j]=0;c=1;
				}
			    else
			          	c=0;
			}
	  if(c)
		printf("POSSIBLE\n");
	  else
		printf("IMPOSSIBLE\n");
   }
   else
	   printf("IMPOSSIBLE\n");
		return 0;
}
			

			

     
   

   

  