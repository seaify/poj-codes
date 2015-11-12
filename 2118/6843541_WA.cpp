#include<stdio.h>
#include<string.h>

long long n,a[200],b[200],c[200][200],f[200][200],z[200][200];

void mul(long long x[200][200],long long y[200][200],long long  t)
{
	int i,j,k;
	memset(z,0,sizeof(z));
	for(k=1;k<=n;k++)
      for(i=1;i<=n;i++)
		  if(x[i][k]!=0)
		  {
		     for(j=1;j<=n;j++)
		          if(y[k][j]!=0)
				  {
                      z[i][j]+=x[i][k]*y[k][j];
				  
			          z[i][j]%=10000;
				  }
		  }
		     
    if(t==1)
		memcpy(f,z,sizeof(z));
	else
		memcpy(c,z,sizeof(z));
}

void solve(long long N)
{
    long long i,j,result=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[i][j]=0,f[i][j]=0;

	for(j=1;j<n;j++)
		c[j+1][j]=1;

	for(i=1;i<=n;i++)
		c[n-i+1][n]=b[i],f[i][i]=1;

	while(N)
	{
		if(N&1)
			mul(f,c,1);
		mul(c,c,2);
		N/=2;
	}
    
	for(i=1;i<=n;i++)
		result+=a[i-1]*f[i][n];
	printf("%lld\n",result%10000);

}

int main()
{
	long long i,N;
	while(EOF!=scanf("%lld",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
			
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			b[i]%=10000;
		}
		scanf("%lld",&N);
		if(i<n)
			printf("%lld\n",a[i]);
		else
			solve(N-n+1);
	}
	return 0;
}