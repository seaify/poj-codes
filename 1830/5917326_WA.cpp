#include<stdio.h>
#include<string.h>
int c[100];
int n,ans;

int solve()
{
	int i,j,tmp;
	ans=0;
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(c[j]==(1<<n))
				return -1;
        if(c[i]&(1<<i))
			j=i;
		else
		{
			for(j=i+1;j<n;j++)
				if(c[j]&(1<<i))
				{
					tmp=c[j];
					c[i]=c[j];
					c[j]=tmp;
					break;
				}
		}

		if(j==n) ///
		{
			ans++;
			continue;
		}

		for(j=i+1;j<n;j++)
			if(c[j]&(1<<i))
			     c[j]^=c[i];
	}
	return (1<<ans);
}

int main()
{
	int T,i,x,y,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
			c[i]=(1<<i);

		for(i=0;i<n;i++)
		{                                
			scanf("%d",&x);
			c[i]^=(x<<n);
		}

		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			c[i]^=(x<<n);
		}
    
		while(1)
		{
			scanf("%d %d",&x,&y);
			if(x==0&&y==0)
				break;
			x--;
			y--;
			c[y]|=(1<<x);
		}

		sum=solve();

		if(sum==-1)
			printf("Oh,it's impossible~!!\n");
		else
		{
			printf("%d\n",sum);
		}
	}
	return 0;
}