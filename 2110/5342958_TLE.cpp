#include<cstdio>
#include<cstring>

bool flag[110][110];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int N,test,mid,a[200][200];

void dfs(int minv,int maxv,int x,int y,int v)
{
	int i,x1,y1,v1,v2;
	if(v>mid)
		return ;
	if(x==N&&y==N)
	{
		test=1;
		return ;
	}
	for(i=0;i<=3;++i)
	{
		x1=x+dir[i][0];
		y1=y+dir[i][1];
		if(x1>=1&&x1<=N&&y1>=1&&y1<=N&&!flag[x1][y1])
		{
            v1=minv<a[x1][y1]?minv:a[x1][y1];
			v2=maxv>a[x1][y1]?maxv:a[x1][y1];
			flag[x1][y1]=true;
			dfs(v1,v2,x1,y1,v2-v1);
			flag[x1][y1]=false;
		}
	}
	return ;
}

int main()
{
	int i,j,minv,maxv,left,right;
	while(EOF!=scanf("%d",&N))
	{
		minv=200,maxv=-1;
		for(i=1;i<=N;++i)
			for(j=1;j<=N;++j)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]<minv)
					minv=a[i][j];
				if(a[i][j]>maxv)
					maxv=a[i][j];
			}
	    left=0;right=maxv-minv;
		while(left<=right)
		{
            mid=(left+right)/2;
			memset(flag,false,sizeof(flag));
			test=0;
			dfs(a[1][1],a[1][1],1,1,0);
			if(test)
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%d\n",left);
	}
	return 0;
}