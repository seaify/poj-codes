#include<stdio.h>
long f(int m,int n)
{
	if(n==1||m==0)return 1;
	if(n>m)
		return f(m,m);
	else
		return f(m,n-1)+f(m-n,n);
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		printf("%ld\n",f(m,n));
	}
	return 0;
}
		





	

