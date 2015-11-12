#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
vector < int > edge[110],last[1010];
const int INF=100000000;
int map[210][210],p[1010],v[1010],value[1010],n,m,sum,q[500000];
bool  flag[1010];
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
            if(y==n+1)
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
  for(i=n+1;i!=0;i=p[i])
     if(map[p[i]][i]<minv)
         minv=map[p[i]][i];
  for(i=n+1;i!=0;i=p[i])
      map[p[i]][i]-=minv,map[i][p[i]]+=minv;
  sum+=minv;
  return 1;
}
int main()
{
   int i,j,x,y;
   while(EOF!=scanf("%d%d",&m,&n))// m为边数，n为点数。。。 
   {
     memset(map,0,sizeof(map));//记录流量 
     for(i=0;i<=n+1;++i)
         edge[i].clear();
	 for(i=1;i<=m;++i)
		 last[i].clear();
     for(i=1;i<=m;++i)
        scanf("%d",&v[i]);
     for(i=1;i<=n;++i)
     {
       scanf("%d",&x);
       while(x--)
       {
         scanf("%d",&j);
         last[j].push_back(i);
       }
       scanf("%d",&value[i]);
     } 
     for(i=1;i<=m;++i)
     {
        if(last[i].size()>=2)
        for(j=0;j+1<=last[i].size()-1;++j)//分为2步。。。 
        {
            x=last[i][j],y=last[i][j+1];
            if(map[x][y]==0&&map[y][x]==0)
            {
              edge[x].push_back(y);
              edge[y].push_back(x);
            }
            map[x][y]=INF;
        }
        if(!last[i].empty())
        {
         x=last[i][0];
         if(map[0][x]==0&&map[x][0]==0)
         {
              edge[x].push_back(0);
              edge[0].push_back(x);
         }
         map[0][x]+=v[i];
        }
     }
     for(i=1;i<=n;++i)
     {
        edge[i].push_back(n+1);
        edge[n+1].push_back(i);
        map[i][n+1]=value[i];
     } 
     sum=0;
     while(Ford());
     printf("%d\n",sum); 
   }
   return 0;
}

