#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,in[110000],out[110000],last[110000],v[110000],tot,cnt,ans;
bool flag[110000];

struct node
{
	int y,v;
};
node c;
vector < node > a[110000];

int dfs(int x)
{
	int i,y,v;
    flag[x]=false;
	for(i=0;i<a[x].size();++i)  ///对于叶子，直接跳过....
		if(flag[a[x][i].y])
		{
			y=a[x][i].y;
			v=dfs(y)+a[x][i].v;     ////返回的是经该点的最大距离....
			if(v<=out[x])
				continue;
			else if(v>=in[x])
			{
                out[x]=in[x];
				in[x]=v;
			}
			else
				out[x]=v;
		}
	if(in[x]+out[x]>ans)
		ans=in[x]+out[x];
	return in[x];
}

int main()
{
    int i,x,y,value;
	char ch;
    while(EOF!=scanf("%d %d",&n,&m))
	{
        for(i=1;i<=n;++i)
		{
             a[i].clear();
			 in[i]=0;
			 out[i]=0;
			 flag[i]=true;
		}
		while(m--)
		{
			scanf("%d %d %d %c",&x,&y,&value,&ch);
			c.y=y;
			c.v=value;
			a[x].push_back(c);
			c.y=x;
			a[y].push_back(c);
		}
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
    return 0;
}

