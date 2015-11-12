#include<stdio.h>
#include<math.h>

const int maxn=(1<<30)-1+(1<<30);

int n,m,top;
int prime[200000],flag[200000];

void init()
{
	int i,j,N;
	N=(int)sqrt(1.0*maxn);
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
				flag[j]=0;
				j+=2*i;
			}
			prime[++top]=i;
		}
}

int solve(int n,int m)
{
	int i,t,num;
	for(i=1;i<=top&&m!=1;i++)
	{
		t=n;num=0;
		while(t/prime[i])
		{
			num+=t/prime[i];
			t/=prime[i];
		}
		while(m%prime[i]==0)
		{
			m/=prime[i];
			num--;
		}
		if(num<0)
			return 0;
	}
    return n>=m;
}

int main()
{
	int flag;
	init();
	while(EOF!=scanf("%d %d",&n,&m))
	{
		if(n==0)
			 flag=1;
		else if(m==0)
			 flag=0;
		else if(n>=m)
			 flag=1;
		else
			 flag=solve(n,m);
		if(flag)
		     printf("%d divides %d!\n",m,n);
		else
             
			 printf("%d does not divide %d!\n",m,n);
	}
	return 0;
}