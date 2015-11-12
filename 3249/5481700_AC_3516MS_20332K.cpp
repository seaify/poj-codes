#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,in[110000],out[110000],last[110000],v[110000],tot,cnt;
bool flag[11000];

struct node
{
	int y,v;
};
node c;
vector < node > a[110000];

void DFS_visit(int i)
{
  int y;
  flag[i]=false;
  for( int k=0;k!=a[i].size();++k)
  {
	  y=a[i][k].y;
      if(flag[y])
         DFS_visit(y);
  }
  last[++tot]=i;
}

int main()
{
    int i,j,k,x,y;
    while(EOF!=scanf("%d %d",&n,&m))
	{
        for(i=0;i<=n+1;++i)
		{
             a[i].clear();
			 in[i]=0;
			 out[i]=0;
		}
		v[0]=0;	v[n+1]=0;
		for(i=1;i<=n;++i)
			scanf("%d",&v[i]);
		while(m--)
		{
			scanf("%d %d",&x,&y);
			++in[y];
			++out[x];
			c.y=y;c.v=v[y];
			a[x].push_back(c);
		}
		for(i=1;i<=n;++i)
		{
			if(in[i]==0)
			{
				c.y=i;c.v=v[i];
				a[0].push_back(c);
			}
			if(out[i]==0)
			{
				c.y=n+1;c.v=v[n+1];
				a[i].push_back(c);
			}
		}
	    memset(flag,true,(n+2)*sizeof(flag[1]));
        tot=-1;
        for(i=0;i<=n+1;++i)
            if(flag[i])
                DFS_visit(i);
		for(i=0;i<=n+1;++i)
			v[i]=-1000000000;
		v[0]=0;
		for(i=tot;i>=0;--i)  ///求出入度为0的点到出度为0的点的最长路。。。
		{
			k=last[i];
            for(j=0;j<a[k].size();++j)
			{
				y=a[k][j].y;
				if(v[k]+a[k][j].v>v[y])
					v[y]=v[k]+a[k][j].v;
			}
		}
		printf("%d\n",v[n+1]);
	}
    return 0;
}
