#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[10000],d[10000],f[10000],set[10000],tot,cnt,t;
bool flag[10000],tag[5000][5000];;
vector< int > a[10000],b[10000],c[10000],edge[10000];
void DFS_visit(int i)
{
  flag[i]=false;
  ++t;
  d[i]=t;
  for( int k=0;k!=a[i].size();++k)
     if(flag[a[i][k]])
         DFS_visit(a[i][k]);
  ++t;
  f[i]=t;
  last[++tot]=i;
}
void dfs(int i)
{
  flag[i]=false;
   for( int k=0;k!=b[i].size();++k)
     if(flag[b[i][k]])
         dfs(b[i][k]);
  set[i]=tot;
}
void DFS()
{
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  t=0;tot=0;
  for(i=1;i<=2*n;++i)
    if(flag[i])
        DFS_visit(i);
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  tot=0;
  for(i=2*n;i>=1;--i)
     if(flag[last[i]])
     {
       ++tot;
       dfs(last[i]);
     }       
}
void color(int x)
{
	int i,y;
    d[x]=2;
    for (i=0;i<a[x].size();i++)
     {
          y=a[x][i];
         if (d[y]==-1)
         {
             color(y);
         } 
     }          
}
void solve()
{
    int i,j,k,x,ans;
    for(i=1;i<=n;++i)
       if(set[2*i-1]==set[2*i])
        {
           printf("bad luck\n");
           return ;
        }
	for(i=1;i<=2*n;++i)
		c[i].clear(),edge[i].clear();
	memset(tag,true,sizeof(tag));
    for(i=1;i<=2*n;++i)
    {
      for(j=0;j<a[i].size();++j)
	  {
		   x=a[i][j];
           if(set[i]!=set[x]&&tag[set[i]][set[x]])  ////构造缩点后的逆图。。。。
           {
              c[set[x]].push_back(set[i]);   
			  // c[set[i]].push_back(set[x]);
			  tag[set[i]][set[x]]=false;
           }
	  }
    }
    for(i=1;i<=2*n;++i)   /////将一个强连通分量中的点统计出来。。。。,强连通
        edge[set[i]].push_back(i);
    for(i=1;i<=2*n;++i)//tot为强连通分量个数 
    {    
      a[i].clear();
      a[i]=c[i];
    }
    memset(flag,true,(2*n+1)*sizeof(flag[1]));  ///再次拓补排序.....
    t=0;k=tot;tot=0;   //t,tot为全局。。
    for(i=1;i<=k;++i)
       if(flag[i])
           DFS_visit(i);
    for(i=1;i<=tot;++i)
         d[i]=-1;//表示颜色 
	/*for(i=tot;i>=1;--i)
		printf("%d ",last[i]);
	printf("\n");*/
    for(i=tot;i>=1;--i)    // 逆图的拓补排序序列。。。
    {
        if(d[last[i]]==-1)  //last[i]已经是强连通分量的
        {
           x=edge[last[i]][0]; 
           if(x%2==0)
			   x=x-1;
		   else
			   x=x+1;
           d[last[i]]=1;
           if(d[set[x]]==-1)
               color(set[x]);
        }
    }
	ans=d[set[1]]; ///最终的颜色...,但只标记了强连通分量的颜色。。。
	for(i=3;i<=2*n-2;++i)
	{
		if(d[set[i]]==ans)
		{
			if(i%2==0)
				printf("%dh ",i/2-1);
			else
				printf("%dw ",i/2);
		}
	}
	if(d[set[2*n-1]]==ans)
		printf("%dw\n",n-1);
	else
		printf("%dh\n",n-1);
}
int main()
{
    char ch1[5],ch2[5];
	int t1,t2;
  while(EOF!=scanf("%d %d",&n,&m))
    {
      if(n==0&&m==0)
            break;
      for(i=1;i<=2*n;++i)
      {
        a[i].clear();
        b[i].clear();
      }
	 a[2].push_back(1);
	 b[1].push_back(2);
     while(m--)
     {
       scanf("%s %s",ch1,ch2);
       i=ch1[0]-'0';
       j=ch2[0]-'0';
       ++i;++j;
       if(ch1[1]=='h') /////第i个group。。。。。
           i=2*i;
	   else
		   i=2*i-1;
       if(ch2[1]=='h')
           j=2*j;
	   else
		   j=2*j-1;
	   if(i%2==0)
		   t1=i-1;
	   else
		   t1=i+1;
	   if(j%2==0)
		   t2=j-1;
	   else
		   t2=j+1;

	   a[i].push_back(t2);
	   b[t2].push_back(i);

	   a[j].push_back(t1);
	   b[t1].push_back(j);
	   	   
     }
    DFS();
    solve();
   }
   return 0;
}


