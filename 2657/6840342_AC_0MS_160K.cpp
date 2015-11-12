#include<stdio.h>

int N,K,Z,M;
int a[2000],b[2000];

int main()
{
	int i,j,x;
	while(EOF!=scanf("%d %d %d",&N,&Z,&M))
	{
		for(i=1;i<=N;i++)
			a[i]=0;
		a[1]=1;a[Z]=2;
		for(i=1;i<=M;i++)
		{
			scanf("%d",&x);
			a[x]=-1;
		}
		if(M==0)
			printf("1\n");
		else
		{
			for(K=1;K<N;K++)
			{
				for(i=1;i<=N;i++)
					b[i]=a[i];
				b[1]=-1;
				j=K+1;
                while(b[j]==0)
				{
					b[j]=-1;
					j+=K;
					if(j>N)
						j-=N;
				}
                if(b[j]==2)
				{
                    printf("%d\n",K);
					break;
				}
			}
		}
	}
	return 0;
}