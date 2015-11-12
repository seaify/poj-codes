#include<stdio.h>

int a[400],d[20],v[20];
int n,result;

void dfs(int num,int depth)
{
	int i,x,y;

	if(depth==n+1&&num<result)
	{
         for(i=1;i<=num;i++)
			 if(d[i]<=0)
				 return ;
		 result=num;
		 return ;
	}

	for(i=1;i<=num;i++)
	{
        x=d[i],y=v[i];


		if(d[i]<0)
			d[i]=0;
		else if(d[i]==0)
		{
			if(a[depth]-v[i]<=0)
				continue;
			d[i]=a[depth]-v[i];
		}
		else
		{
			if(a[depth]!=v[i]+d[i])
				continue;
			
		}
		v[i]=a[depth];
		dfs(num,depth+1);
		d[i]=x,v[i]=y;
	}
    
	if(num+1>=result)
		return ;

	d[num+1]=0;
	v[num+1]=a[depth];
	dfs(num+1,depth+1);
	d[num+1]=-1;
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&n))
	{
		  for(i=1;i<=n;i++)
			  scanf("%d",&a[i]);
		  result=18;
		  for(i=1;i<=20;i++)
			  d[i]=-1;
		  dfs(0,1);
		  printf("%d\n",result);
	}
	return 0;
}