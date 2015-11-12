#include<stdio.h>
#include<string.h>
int m,n;
int p[20],ans[20],tmp[20],x[20],y[20];

int main()
{
	int i,j,k,t,c,flag;

	for(i=0;i<=18;i++)
		ans[i]=(1<<i);

	while(EOF!=scanf("%d %d",&m,&n))
	{
		for(i=0;i<m;i++)
		{
			p[i]=0;
			for(j=0;j<n;j++)
			{
				scanf("%d",&c);
				p[i]^=(c<<j);
			}
		}

		flag=0;
	

		for(i=0;i<ans[n];i++)
		{
			tmp[0]=i;

			memcpy(y,p,sizeof(p));

			for(j=1;j<=m;j++)
			{
				tmp[j]=0;

				y[j]^=tmp[j-1];


				for(k=0;k<n;k++)
					if(tmp[j-1]&ans[k])
						x[k]=1;
					else
						x[k]=0;

				for(k=0;k<n;k++)
				{
					t=x[k];
					if(k-1>=0)
						t^=x[k-1];
					if(k+1<n)
						t^=x[k+1];
					tmp[j]^=(t<<k);
				}

				tmp[j]^=y[j-1];
			}

			if(tmp[m]==0)
			{
				flag=1;
				break;
			}

		}

		if(flag)
		{
			for(i=0;i<m;i++)
			{
				for(j=0;j<n-1;j++)
					printf("%d ",(tmp[i]&ans[j])>0?1:0);
				printf("%d\n",(tmp[i]&ans[n-1])>0?1:0);
			}
		}
		else
			printf("IMPOSSIBLE\n");

	}

	return 0;
}
