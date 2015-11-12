#include<stdio.h>

int p[30000];
int n;

int solve(int x)
{
	int i,ans=1;

	for(i=2;i<=x&&i<=20000;i++)
	{
		if(x%i==0)
		{
			ans=i;
			while(x%i==0)
				x/=i;
		}
	}

    return ans;

}


int main()
{
	
	int i,x,value,ans;

	p[1]=1;

	for(i=2;i<=20000;i++)
	{
	    p[i]=solve(i);
	//	printf("%d\n",p[i]);
	}
	
	while(EOF!=scanf("%d",&n))
	{
		value=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(p[x]>value)
			{
				ans=x;
				value=p[x];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
