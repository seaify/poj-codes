#include<cstdio>
#include<cmath>
const double eps=1e-9;
double x[1100];
int up[1100],down[1100],ans,N;

int main()
{
	int i,j;
	while(EOF!=scanf("%d",&N))
	{
		for(i=1;i<=N;++i)
			scanf("%lf",&x[i]);
		up[1]=1;
		for(i=2;i<=N;++i)
		{
			up[i]=1;
			for(j=1;j<i;++j)
				if(x[i]>x[j]+eps)   /////严格单调递增
				{
					if(up[j]+1>up[i])
						up[i]=up[j]+1;
				}
		}
		down[N]=1;
		for(i=N-1;i>=1;i--)
		{
			down[i]=1;
			for(j=i+1;j<=N;++j)  /////////严格单调递增
				if(x[i]>x[j]+eps)
				{
					if(down[j]+1>down[i])
						down[i]=down[j]+1;
				}
		}
		ans=0;
	    for(i=1;i<N;++i)
			for(j=i+1;j<=N;++j)
				if(up[i]+down[j]>ans)
					ans=up[i]+down[j];
		printf("%d\n",N-ans);
	}
	return 0;
}