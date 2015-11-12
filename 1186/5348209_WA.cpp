#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,T,N,M,ans,top,sum,p[10],k[10],x[10],v[10],a[4000000],cnt[4000000];

int test(int a, int n)
{
	int result=1;
	while(n)
	{
		if(n&1)
			result*=a;
		a*=a;
		n>>=1;
	}
	return result;
}

void dfs(int cur,int depth)
{
	int i;
     if(depth==ans+1)
	 {
		 if(ans<n)
		    cnt[++N]=cur;
		 else
			a[++N]=cur;
		 return ;
	 }
	 for(i=1;i<=M;++i)
		  dfs(cur+k[depth]*test(i,p[depth]),depth+1);
	 return ;
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&n))
	{
		scanf("%d",&M);
		for(i=1;i<=n;++i)
			scanf("%d %d",&k[i],&p[i]);
		m=0;T=1;
        for(i=1;i<=n;++i)
			if(k[i]==0)
				T*=M;
			else
				v[++m]=i;
		if(m==0)
		{
			printf("%d\n",T);
			continue;
		}
		for(i=1;i<=m;++i)
			p[i]=p[v[i]],k[i]=k[v[i]];
		n=m;
		ans=n/2;
		for(i=ans+1;i<=n;++i)
			k[i]=-k[i];
		N=0;
		dfs(0,1);
		top=N;
		N=-1,ans=n;
		dfs(0,n/2+1);
		sort(a,a+N);
        sum=0;
        for(i=1;i<=top;++i)
                sum+=upper_bound(a,a+N,cnt[i])-lower_bound(a,a+N,cnt[i]);
		sum*=T;
        printf("%d\n",sum);
	}
    return 0;
}