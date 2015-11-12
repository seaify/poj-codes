#include<stdio.h>
#include<math.h>

const int INF=(1<<30)-1+(1<<30);

int L,U,top;
int prime[200000],flag[200000],a[2000000],c[2000000];

void init()
{
    int i,j,N;
	N=(int)sqrt(1.0*INF);
    prime[1]=2;
	top=1;
	for(i=3;i<=N;i+=2)
		flag[i]=1;
	for(i=3;i<=N;i+=2)
		if(flag[i])
		{
			j=i*i;
			while(j<=N)
			{
				flag[j]=0;
				j+=2*i;
			}
			prime[++top]=i;
		}
}

void solve()
{
	int i,j,k,l,r,lv,rv,n;

	for(i=L;i<=U;i++)
		a[i-L+1]=1;

    for(i=1;i<=top&&U>=prime[i];i++)
	{
        k=L/prime[i];
		if((L%prime[i])!=0)
			k++;
		if(k==1)
			k++;
		for(j=k*prime[i];j<=U;j+=prime[i])
		        a[j-L+1]=0;
	}

	n=0;
	for(i=L;i<=U;i++)
		if(a[i-L+1])
			c[++n]=i;

    if(n<=1)
		printf("There are no adjacent primes.\n");
	else
	{
		l=INF;r=0;
		for(i=2;i<=n;i++)
		{
			if(c[i]-c[i-1]<l)
			{
				l=c[i]-c[i-1];
				lv=i;
			}
			if(c[i]-c[i-1]>r)
			{
				r=c[i]-c[i-1];
				rv=i;
			}
		}
		printf("%d,%d are closest, %d,%d are most distant.\n",c[lv-1],c[lv],c[rv-1],c[rv]);
	}
}

int main()
{
	init();
	while(EOF!=scanf("%d %d",&L,&U))
          solve();
	return 0;
}