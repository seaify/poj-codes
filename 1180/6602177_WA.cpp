#include<stdio.h>

int n,S;
int sumF[11000],sumT[11000],st[40000],dp[11000];

int check(int a,int b,int c)
{
     return (dp[b]-dp[a])*(sumT[c]-sumT[b])>(dp[c]-dp[b])*(sumT[b]-sumT[a]);
}

int main()
{
	int i,j,a,b,l,r;

	while(EOF!=scanf("%d",&n))
	{
		scanf("%d",&S);
		sumF[n+1]=sumT[n+1]=0;
		for(i=1;i<=n;i++)
			scanf("%d %d",&sumT[i],&sumF[i]);

		for(i=n;i>=1;i--)
			sumT[i]+=sumT[i+1],sumF[i]+=sumF[i+1];

		l=1,r=0;
		dp[n]=(S+sumT[n])*sumF[n];
		st[++r]=n;
		for(i=n-1;i>=1;i--)
		{

			while(r-l+1>=2)
			{
				a=st[l],b=st[l+1];
				if((dp[b]-dp[a])>=(sumT[b]-sumT[a])*sumF[i])
					break;
				l++;
			}

			j=st[l];
			dp[i]=dp[j]+(S+sumT[i]-sumT[j])*sumF[i];

			st[++r]=i;
			while(r-l+1>=3&&check(st[r-2],st[r-1],st[r]))
				st[--r]=i;
		}

        printf("%d\n",dp[1]);
	}
	return 0;
}