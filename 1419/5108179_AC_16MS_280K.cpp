#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > v[110];
int cnt[110],c[110],maxn,sum,n;
bool map[110][110];
void dfs(int cur,int depth)
{
  int i,j,k,flag,top; 
  if(cur==n+1)
  {
     if(depth>sum)
     {
      sum=depth;top=0;
      for(i=1;i<=n;++i)
        if(c[i])
         cnt[++top]=i;
     }
     return ;
  }
  flag=0;
  for(j=0;j<v[cur].size();++j)
      if(c[v[cur][j]])
      {
         flag=1;
         break;
      }
  if(!flag)
  {
     c[cur]=1;
     dfs(cur+1,depth+1);
     c[cur]=0;
  }
  if(depth+(n-cur)/2>sum)
     dfs(cur+1,depth);
}
int main()
{
  int T,i,j,k;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)
       v[i].clear();
    memset(map,false,sizeof(map));
    while(k--)
    {
      scanf("%d%d",&i,&j);
      if(!map[i][j])
      {
         v[i].push_back(j);
         v[j].push_back(i);
         map[i][j]=true;
         map[j][i]=true;
      }
    }
    sum=0;
    memset(c,0,sizeof(c));
    dfs(1,0);
    printf("%d\n",sum);
    for(j=1;j<sum;++j)
       printf("%d ",cnt[j]);
    printf("%d\n",cnt[sum]);
  }
}
