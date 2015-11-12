#include<cstdio>
#include<cstring>
int T,N,M,in[110],out[110];
bool  c[110][110];

int main()
{
	int i,j,k,x,y,ans,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		memset(c,false,sizeof(c));
		for(i=1;i<=N;++i)
			c[i][i]=true;
		while(M--)
		{
			scanf("%d %d",&x,&y);
			c[x][y]=true;
		}
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					if(c[i][k]&&c[k][j])
						c[i][j]=true;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
				if(i!=j&&c[i][j])
				{
					in[j]++;
					out[i]++;
				}
		}
		ans=(N-1)/2;
		cnt=0;
		for(i=1;i<=N;++i)
			if(in[i]>ans||out[i]>ans)
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}