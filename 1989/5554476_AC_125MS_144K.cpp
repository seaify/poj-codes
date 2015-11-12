#include<cstdio>
#include<cstring>
bool flag[11000];
int N,K;

int main()
{
	int i,c,sum,x;
	while(EOF!=scanf("%d %d",&N,&K))
	{
		memset(flag,true,sizeof(bool)*(K+1));
		c=0;
		sum=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&x);
			if(flag[x])
			{
				flag[x]=false;
				c++;
			}
			if(c==K)
			{
				c=0;
				sum++;
				memset(flag,true,sizeof(bool)*(K+1));
			}
		}
		printf("%d\n",sum+1);
	}
	return 0;
}