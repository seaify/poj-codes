#include<stdio.h>
#include<string.h>
int main()
{
	int a[15],b[15],flag[15],d[15],i,j,c,t;	

	for(i=1;i<=12;i++)
		scanf("%d",&d[i]);
	 for(i=1;i<=6;i++)
          b[i]=d[2*i];
	for(i=1;i<=6;i++)
    	a[i]=d[2*i-1];
	for(i=1;i<12;i++)
		for(j=i+1;j<=12;j++)
			if(d[j]<d[i])
			{
				t=d[i];
				d[i]=d[j];
				d[j]=t;
			}
		
	for(i=1;i<=12;i++)
		printf("%d ",d[i]);
	if((d[1]==d[2]&&d[2]==d[3]&&d[3]==d[4])&&(d[5]==d[6]&&d[6]==d[7]&&d[7]==d[8])&&(d[9]==d[10]&&d[10]==d[11]&&d[11]==d[12]))
		c=1;
	else
		c=0;
	

   
   if(c)
   {   c=0;
  
		memset(flag,1,sizeof(flag));

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
			

			

     
   

   

  