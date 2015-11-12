#include<stdio.h>
#include<math.h>

const int INF=1000000000;

int n,top;
int prime[100000],flag[100000];

void init()
{
    int i,j,N;
	N=(int)(sqrt(1.0*INF));
	top=1;
	prime[1]=2;
	for(i=3;i<=N;i+=2)
		flag[i]=1;  
	for(i=3;i<=N;i+=2)
		if(flag[i])
	    {
           j=i*i;
		   while(j<=N)
		   {
			  j+=2*i;
			  flag[j]=0;
		   }
		   prime[++top]=i;
	    }
}

void solve(int T,int n)
{
	int i,c;
	long long result=1;
	for(i=1;i<=top&&n!=1;i++)
	{
		c=0;
		while(n%prime[i]==0)
		{
			n/=prime[i];
			c++;
		}
		result*=(1+2*c);
	}
    if(n!=1)
		result*=3;
	result=(result+1)/2;
	printf("Scenario #%d:\n",T);
    printf("%lld\n\n",result);
}

int main()
{
	int i,T;

	init();
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n);
        solve(i,n);
	}
	return 0;
}