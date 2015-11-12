#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
vector < int > edge[210];
const int INF=100000000;
int map[210][210],p[210],n,m,sum,q[500000];
bool  flag[210];
int find_path()
{
  int i,x,y,beg,end;
  memset(flag,false,sizeof(flag));
  q[0]=1;beg=0;end=1;flag[1]=true;
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
            if(y==n)
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
  for(i=n;i!=1;i=p[i])
     if(map[p[i]][i]<minv)
         minv=map[p[i]][i];
  for(i=n;i!=1;i=p[i])
      map[p[i]][i]-=minv,map[i][p[i]]+=minv;
  sum+=minv;
  return 1;
}
int main()
{
   int i,j,value;
   while(EOF!=scanf("%d%d",&m,&n))// m为边数，n为点数。。。 
   {
     memset(map,0,sizeof(map));//记录流量 
     for(i=1;i<=n;++i)
        edge[i].clear();
     while(m--)
     {
       scanf("%d%d%d",&i,&j,&value);
       if(map[i][j]==0&&map[j][i]==0)
       {
           edge[i].push_back(j);
           edge[j].push_back(i);
       }
       map[i][j]+=value;
     } 
     sum=0;
     while(Ford());
     printf("%d\n",sum); 
   }
   return 0;
}
