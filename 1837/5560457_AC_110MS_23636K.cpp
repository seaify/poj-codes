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
	    memset(f,0,sizeof(f));
		f[0][7500]=1;
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=M;++j)
			{
				cnt=W[i]*T[j];
				if(cnt<0)
				{
			      for(k=0;k<=15000;k++)
					if(f[i-1][k])
					{
					   	   f[i][k+cnt]+=f[i-1][k];
					}
				}
				else
				{
                  for(k=15000;k>=0;k--)
					if(f[i-1][k])
					{
						f[i][k+cnt]+=f[i-1][k];
					}
				}
			}
		}
		printf("%d\n",f[N][7500]);
	}
	return 0;
}