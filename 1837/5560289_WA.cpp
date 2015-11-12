#include<cstdio>
#include<cstring>
const int INF=1000000000;
int T[30],W[30],f[30][200000];
int N,M;

int main()
{
	int i,j,k,cnt;
	while(EOF!=scanf("%d %d",&M,&N))
	{
		for(i=1;i<=M;++i)
			scanf("%d",&T[i]);
		for(i=1;i<=N;++i)
			scanf("%d",&W[i]);
	    for(i=0;i<=15000;++i)
	        for(j=0;j<=N;++j)
				f[j][i]=-1;
		f[0][7500]=0;
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=M;++j)
			{
				cnt=W[i]*T[j];
			    for(k=15000;k>=0;k--)
					if(f[i-1][k]!=-1)
					{
						if(f[i][k+cnt]==-1)
							f[i][k+cnt]=1;
						else
					   	    f[i][k+cnt]++;
					}
			}
		}
		printf("%d\n",f[N][7500]);
	}
	return 0;
}