#include<cstdio>
#include<algorithm>
using namespace std;
int n,N,M,ans,top,sum,p[10],k[10],x[10],a[4000000],cnt[4000000];

int test(int a, int n)
{
	int result=1;
	while(n)
	{
		if(n&1)
			result*=a;
		a*=a;
	    n/=2;
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
		if(n==1)
		{
			if(k[1]==0)
				printf("%d\n",M);
			else
				printf("0\n");
			continue;
		}
		ans=n/2;
		for(i=ans+1;i<=n;++i)
			k[i]=-k[i];
		N=0;
		dfs(0,1);
		top=N;
		N=-1,ans=n;
		dfs(0,n/2+1);
		++N;
		sort(a,a+N);
        sum=0;
	/*	printf("%d %d\n",top,N);
		for(i=1;i<=top;++i)
			printf("%d ",cnt[i]);
		printf("\n");
		for(i=0;i<N;++i)
			printf("%d ",a[i]);
		printf("\n");*/
        for(i=1;i<=top;++i)
                sum+=upper_bound(a,a+N,cnt[i])-lower_bound(a,a+N,cnt[i]);
        printf("%d\n",sum);
	}
    return 0;
}
