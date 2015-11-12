#include<stdio.h>
#include<string.h>
#include<algorithm>
const int maxn=100001;
struct type{
	int an,cn;
}s[101];
bool a[maxn];
int b[maxn][2];

int main()
{
	int n,m,i,j,sum,max,all;
	while(EOF!=scanf("%d%d",&n,&m)&&(n||m))
	{
		memset(b,-1,sizeof(b));
		for(i=1;i<=m;i++)
			a[i]=false;
		a[0]=true;
		for(i=1;i<=n;i++)
			scanf("%d",&s[i].an);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i].cn);
		max=0;sum=0;all=0;
	
		for(j=1;j<=n;j++)
		{
			all+=s[j].an*s[j].cn;
			if(all>m)
				all=m;
			for(i=s[j].an;i<=all;i++)
			{
				if(a[i])
					continue;
				int temp=i-s[j].an;
				if(temp<0)
					continue;
				if(!a[temp])
					continue;
				if(b[temp][0]==j&&b[temp][1]>=s[j].cn)
					continue;
				b[i][0]=j;
				if(b[temp][0]==j)
					b[i][1]=b[temp][1]+1;
				else
					b[i][1]=1;
				    a[i]=true;
					sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}