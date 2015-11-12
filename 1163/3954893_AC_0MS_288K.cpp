#include<stdio.h> 
int main()
{
	int a[105][105],i,j,f[105][105],max,n;
	while(EOF!=scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++)
				scanf("%d",&a[i][j]);
			f[1][1]=a[1][1];
			for(i=2;i<=n;i++)
			{
				f[i][1]=f[i-1][1]+a[i][1];
				f[i][i]=f[i-1][i-1]+a[i][i];
			}
			for(i=3;i<=n;i++)
				for(j=2;j<i;j++)
					if(f[i-1][j]<f[i-1][j-1])
						f[i][j]=f[i-1][j-1]+a[i][j];
					else
						f[i][j]=f[i-1][j]+a[i][j];
               max=0;
	                 for(j=1;j<=n;j++)
		                    if(f[n][j]>max)
			                       max=f[n][j];
							printf("%d\n",max);
	}  
	return 0; 
} 




	
  


