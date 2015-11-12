#include<cstdio>
int x,y,a[11000],use[110000],num[20],v[20];
bool flag[110000];
int cash,N,ans;

int main()
{
	int i,j;
	while(EOF!=scanf("%d %d",&cash,&N))
	{
		for(i=1;i<=N;++i)
			scanf("%d %d",&num[i],&v[i]);
		for(i=1;i<=cash;i++)
			flag[i]=false;
		flag[0]=true;
		for(i=1;i<=N;i++)
		{
            for(j=0;j<=cash;j++)
				use[j]=0;
			for(j=0;j+v[i]<=cash;j++)
				if(flag[j]&&!flag[j+v[i]]&&use[j]<num[i])
				{
					flag[j+v[i]]=true;
					use[j+v[i]]=use[j]+1;
				}
		}
		for(i=cash;i>=0;i--)
			if(flag[i])
			{
				ans=i;
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}