#include<stdio.h>
__int64 f(int n)
{
	if(n==1)
		return 2;
	if(n==2)
		return 3;
	return f(n-1)+f(n-2);
}
int main()
{
	int n,i,t,time=1;
	scanf("%d",&t);
    while(t--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",time++);
		printf("%I64d\n\n",f(n));
	}
	return 0;
}
