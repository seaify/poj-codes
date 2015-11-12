#include<stdio.h>
#include<algorithm>
using namespace std;

long long v[2000],f[2000];
long long N,C,sum;

int main()
{
	long long i,j,T,cc,ans;
	scanf("%lld",&T);
	for(cc=1;cc<=T;cc++)
	{
		scanf("%lld %lld",&N,&C);
		for(i=1;i<=N;i++)
			scanf("%lld",&v[i]);

		sort(v+1,v+N+1);
       
		if(C<v[1])
		{
            printf("%lld 0\n",cc);
			continue;
		}

		sum=0;
		for(i=1;i<=N;i++)
			sum+=v[i];
		for(i=1;i<=C;i++)
			f[i]=0;
		f[0]=1;

		ans=0;
		for(i=N;i>=1;i--)
		{
			sum-=v[i];
			for(j=C-sum;j>=0&&j>=C-sum-v[i]+1;j--)
				ans+=f[j];
            for(j=C;j>=v[i];j--)
                f[j]+=f[j-v[i]];
		}

        printf("%lld %lld\n",cc,ans);

	}
	return 0;
}