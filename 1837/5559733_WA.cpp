#include<cstdio>
#include<cstring>
const int INF=1000000000;
int T[30],W[30];
int N,M;

struct node 
{
	int v,co;
};
node f[20000],c[20000];

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
		{
			f[i].v=-1;  ///表示组成其的元素个数,只取最大值..
			f[i].co=0;  ///方案数
			c[i].v=-1;
			c[i].co=0;
		}
		c[7500].v=0;
		f[7500].v=0;
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=M;++j)
			{
				cnt=W[i]*T[j];
				for(k=0;k<=15000;++k)  ///更新...
				   if(f[k].v==i-1)
				   {
                      c[k+cnt].co++;
					  c[k+cnt].v=i;
				   }
			    for(k=0;k<=15000;++k)
				{
					f[k].v=c[k].v;
					f[k].co=c[k].co;
				}
			}
		}
		printf("%d\n",f[7500].co);
	}
	return 0;
}