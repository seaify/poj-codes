#include<stdio.h>  
int main()
{
	double a[1005],av,k;
	int i,n,casen,c;char d;d=37;
	scanf("%d",&casen);
	while(casen--)
	{
		scanf("%d",&n);av=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			av+=a[i];
		}
		av=av/n;c=0;
		for(i=1;i<=n;i++)
			if(a[i]>av)
				c++;
			k=(c*100.0)/n;
			printf("%.3lf%c\n",k,d);
	}

     return 0;  
 }  


	
