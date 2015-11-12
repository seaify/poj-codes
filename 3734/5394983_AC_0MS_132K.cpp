#include<cstdio>
int N,T;

int solve(int N)
{
    int result=1,a=2;
	while(N)
	{
		if(N&1)
			result=(result*a)%10007;
		a=(a*a)%10007;
		N>>=1;
	}
     return result;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		N--;
		printf("%d\n",(solve(N)+solve(2*N))%10007);
	}
	return 0;
}