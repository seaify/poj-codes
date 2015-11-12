#include<stdio.h>

const int maxn=210;

int n,N;
int a[maxn],c[maxn],last[maxn],len[maxn],pre[maxn],f[maxn][maxn][maxn];

int dfs(int i,int j,int k)
{
	int p,tmp;

	if(f[i][j][k]!=-1)
		return f[i][j][k];
	if(i>j&&k==0)
		return f[i][j][k]=0;

	f[i][j][k]=dfs(i,j-1,0)+(len[j]+k)*(len[j]+k);

	p=pre[j];
	while(p>=i)
	{
        tmp=dfs(i,p,len[j]+k)+dfs(p+1,j-1,0);
		if(tmp>f[i][j][k])
			f[i][j][k]=tmp;
		p=pre[p];
	}
	return f[i][j][k];

}

int main()
{
	int T,i,j,k,cc,tot;
	scanf("%d",&T);
	for(cc=1;cc<=T;cc++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			last[i]=-1;
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=0;k<=n;k++)
					f[i][j][k]=-1;

		N=0;tot=0;a[0]=a[1];a[n+1]=0;
		for(i=1;i<=n+1;i++)
			if(a[i]!=a[i-1])
			{
				++N;
				pre[N]=last[a[i-1]];
				last[a[i-1]]=N;
				len[N]=tot;
				tot=1;
			}
		    else
				 ++tot;
	//	for(i=1;i<=N;i++)
	//		printf("%d %d\n",pre[i],len[i]);
	//
		printf("Case %d: %d\n",cc,dfs(1,N,0));
    
	}
	return 0;
}