#include<stdio.h>
#include<stdlib.h>

int n;

void dfs(int n)
{
	int t=(abs(n)&1);

	if(n==0)
		return ;

	n-=t;
	dfs(n/(-2));

	printf("%d",t);
}

int main()
{
	while(EOF!=scanf("%d",&n))
	{
		if(n!=0)
		   dfs(n);
		else
			printf("0");
		printf("\n");
	}
}