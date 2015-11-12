#include<stdio.h>
#include<string.h>
int n,min,flag[20],map[20][20];
void dfs(int v,int h,int cost)
{
	int i;
	if(h>=n)
	{
		if(min==-1||min>cost+map[n][0])
			min=cost+map[n][0];
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			if(min>0&&cost+map[v][i]+map[i][0]>min)
				continue;
			flag[i]=1;
			dfs(i,h+1,cost+map[v][i]);
			flag[i]=0; 
		}
	}
}

int main()
{
	int i,j,k;
	while(EOF!=scanf("%d",&n)&&n)
    {
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				scanf("%d",&map[i][j]);
		for(i=0;i<=n;i++)
			flag[i]=0;
		flag[0]=1;
		for(i=0;i<=n;i++)
	 		for(j=0;j<=n;j++)
	     		for(k=0;k<=n;k++)
					if(map[i][j]>map[i][k]+map[k][j])
						map[i][j]=map[i][k]+map[k][j];
	    min=-1;
		dfs(0,0,0);
		printf("%d\n",min);
	}
  return 0 ;
}

