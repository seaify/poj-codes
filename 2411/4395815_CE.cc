#include<stdio.h>
#include<string.h>
__int64 a[2][3000];
int t,n,m,tmp;
void dfs(int d,int mm)
{
	if(d==m)
	{
		a[0][mm]++;
		return;
	}
	if(d+1<=m)
		dfs(d+1,mm<<1);
	if(d+2<=m)
		dfs(d+2,mm<<2|3);
}
void DFS(int d,int mm,int nn)//mm表示上一层状态，nn表示下一层状态
{
	if(d==m)
	{
		a[t][nn]+=a[1-t][mm];
		return ;
	}
	if(d+1<=m)
	{
		DFS(d+1,mm<<1,nn<<1|1);
		DFS(d+1,mm<<1|1,nn<<1);
	}
	if(d+2<=m)
		DFS(d+2,mm<<2|3,nn<<2|3);
}
int main()
{
	int i;
	while(EOF!=scanf("%d%d",&m,&n)&&m&&n)
	{
		if((m*n)%2)
		{
			printf("0\n");
		    continue;
		}
		if(m>n)
		{
			tmp=m;
			m=n;
			n=tmp;
		}
		memset(a,0,sizeof(a));
		dfs(0,0);
		for(i=2;i<=m;i++)
		{
			t=(i+1)%2;
			DFS(0,0,0);
			memset(a[1-t],0,sizeof(a[0]));
		}
    printf("%I64d\n",a[(n+1)%2][(1<<m)-1]); //输出最后一行全部放满的结果。
    }
    return 0;
}

	}
	return 0;
}