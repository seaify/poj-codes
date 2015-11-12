#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
vector < int > edge[510];
const int INF=100000000;
int map[510][510],p[510],n,m,sum,q[500000];
bool  flag[510];
int find_path()
{
  int i,x,y,beg,end;
  memset(flag,false,sizeof(flag));
  q[0]=0;beg=0;end=1;flag[0]=true;
  for(;beg<end;++beg)
  {
     x=q[beg];
     if(!edge[x].empty())
     for(i=0;i<edge[x].size();++i)
     {
         y=edge[x][i];
         if(map[x][y]>0&&flag[y]==false)
         {
            flag[y]=true;
            p[y]=x;
            if(y==n+m+1)
              return 1;
            q[end++]=y;
         }
     }                  
  }
  return 0;
}
int Ford()
{
  int minv,i;
  if(find_path()==0)
      return 0;
  minv=INF;
  for(i=n+m+1;i!=0;i=p[i])
     if(map[p[i]][i]<minv)
         minv=map[p[i]][i];
  for(i=n+m+1;i!=0;i=p[i])
      map[p[i]][i]-=minv,map[i][p[i]]+=minv;
  sum+=minv;
  return 1;
}
int main()
{
   int i,j,c,value;
   while(EOF!=scanf("%d%d",&n,&m))// m为边数，n为点数。。。 
   {
     memset(map,0,sizeof(map));//记录流量 
     for(i=0;i<=m+n+1;++i)
        edge[i].clear();
     for(i=1;i<=n;++i)
     {
       scanf("%d",&c);
       while(c--)
       {
         scanf("%d",&j);
         j+=n;
         if(map[i][j]==0&&map[j][i]==0)
         {
           edge[i].push_back(j);
           edge[j].push_back(i);
         }
         map[i][j]=1;
       }
     } 
     for(i=1;i<=n;++i)
     {
         edge[0].push_back(i);
         edge[i].push_back(0);
         map[0][i]=1;
     }
     for(i=n+1;i<=n+m;++i)
     {
         edge[i].push_back(n+m+1);
         edge[n+m+1].push_back(i);
         map[i][n+m+1]=1;
     }
     sum=0;
     while(Ford());
     printf("%d\n",sum); 
   }
   return 0;
}
