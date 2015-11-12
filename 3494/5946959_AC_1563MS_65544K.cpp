#include<stdio.h>
int m,n;
int a[2100][2100],h[2100][2100],left[2100][2100],right[2100][2100];


/*void debug(int a[2100][2100])
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");
}*/

int main()
{
	int i,j,k,flag,ans,tmp;
	while(EOF!=scanf("%d %d",&m,&n))
	{
		flag=1;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j])
					flag=0;
			}
		if(flag)
		{
			printf("0\n");
			continue;
		}

		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(a[i][j])
				{
                    if(i!=1&&a[i-1][j])
						h[i][j]=h[i-1][j]+1;
					else
						h[i][j]=1;
				}
				else
					h[i][j]=0;
			
			
		for(i=1;i<=m;i++)             //left[i][j],求解时必须先
			for(j=1;j<=n;j++)
				if(a[i][j])
				{
                    if(j!=1&&h[i][j]<=h[i][j-1])
					{
                         k=j-1;    
						 while(left[i][k]>1&&h[i][j]<=h[i][left[i][k]-1])
							 k=left[i][k]-1;
						 left[i][j]=left[i][k];
					}
					else
						left[i][j]=j;
				}

	   for(i=1;i<=m;i++)
		   for(j=n;j>=1;j--)
			   if(a[i][j])
			   {
                   if(j!=n&&h[i][j]<=h[i][j+1])
				   {
					   k=j+1;
					   while(right[i][k]<n&&h[i][j]<=h[i][right[i][k]+1])
						   k=right[i][k]+1;
					   right[i][j]=right[i][k];
				   }
				   else
					   right[i][j]=j;
			   }

		ans=0;
      /*  printf("\n");
		debug(h);
		debug(left);
		debug(right);*/

		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(a[i][j])
				{
					tmp=(right[i][j]-left[i][j]+1)*h[i][j];
					if(tmp>ans)
						ans=tmp;
				}

		printf("%d\n",ans);


	}
	return 0;
}