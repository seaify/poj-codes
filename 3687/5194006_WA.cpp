#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector < int > v[500];
priority_queue < int > q;
int in[500],flag[500][500],cnt[500],N,M,T,top,tag;
int main()
{
  int i,j;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;++i)
       v[i].clear(),in[i]=0;
    memset(flag,0,sizeof(flag));
    tag=1;
    while(M--)
    {
      scanf("%d %d",&i,&j); 
      if(i==j)
        tag=0;
      if(tag==0)
        continue;
      if(!flag[i][j])
      {
          flag[i][j]=1;
          v[i].push_back(j);
          ++in[j];
      }
    }
    if(tag==0)
    {
       printf("-1\n");
       continue;
    }
    for(i=1;i<=N;++i)
      if(in[i]==0)
         q.push(-i);
    top=0;
    while(!q.empty())
    {
       i=-q.top();
       q.pop();
       cnt[i]=++top;
       if(!v[i].empty())
       for(j=0;j<v[i].size();++j)
       {
          --in[v[i][j]];
          if(in[v[i][j]]==0)
             q.push(-v[i][j]);
       }   
    }
    if(top<N)
       printf("-1\n");
    else
    {
       for(i=1;i<N;++i)
          printf("%d ",cnt[i]);
       printf("%d\n",cnt[N]);
    }
  }
}
