#include<cstdio>
#include<cstring>

bool flag[110][110],tag[120];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int N,test,mid,a[200][200],ans[120],top,low,high;

void dfs(int x,int y)
{
	int i,x1,y1;
	if(x==N&&y==N)
	{
		test=1;
		return ;
	}
	for(i=0;i<=3;++i)
	{
        if(test)
           return ;
		x1=x+dir[i][0];
		y1=y+dir[i][1];
		if(x1>=1&&x1<=N&&y1>=1&&y1<=N&&!flag[x1][y1]&&a[x1][y1]>=low&&a[x1][y1]<=high)
		{
			flag[x1][y1]=true;
			dfs(x1,y1);
			///flag[x1][y1]=false;
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
		memset(tag,false,sizeof(tag));
		for(i=1;i<=N;++i)
			for(j=1;j<=N;++j)
			{
				scanf("%d",&a[i][j]);
				tag[a[i][j]]=true;
				if(a[i][j]<minv)
					minv=a[i][j];
				if(a[i][j]>maxv)
					maxv=a[i][j];
			}
		top=0;
		for(i=0;i<=maxv;++i)
			if(tag[i])
			   ans[++top]=i;
	    left=a[N][N]-a[1][1];right=maxv-minv;
		while(left<=right)
		{
            mid=(left+right)/2;  //////// 枚举最低点。。。。。
			test=0;
			for(i=1;i<=top&&ans[i]<=a[1][1]&&ans[i]<=a[N][N];++i)
			{
			   memset(flag,false,sizeof(flag));
			   flag[1][1]=true;
			   low=ans[i];
			   high=ans[i]+mid;
			   dfs(1,1);
			   if(test)
				   break;
			}
			if(test)
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%d\n",left);
	}
	return 0;
}

