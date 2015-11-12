#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
vector < int > edge[510];
const int INF=100000000;
int map[510][510],p[510],x[210],y[210],n,N,F,D,maxn,sum,q[900000];
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
            if(y==maxn)
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
  for(i=maxn;i!=0;i=p[i])
     if(map[p[i]][i]<minv)
         minv=map[p[i]][i];
  for(i=maxn;i!=0;i=p[i])
      map[p[i]][i]-=minv,map[i][p[i]]+=minv;
  sum+=minv;
  return 1;
}
void add(int i,int j)
{ 
   if(map[i][j]==0&&map[j][i]==0)
   {
       edge[i].push_back(j);
       edge[j].push_back(i);
    }
    map[i][j]=1;
}
int main()
{
   int i,j,a,b,k,value;
   while(EOF!=scanf("%d%d%d",&N,&F,&D))// m为边数，n为点数。。。 
   {
     memset(map,0,sizeof(map));//记录流量 
     for(i=0;i<=D+F+2*N+1;++i)
        edge[i].clear();
     for(i=1;i<=N;++i)
        add(D+F+i,D+F+N+i);
     for(i=1;i<=N;++i)
     {
       scanf("%d%d",&a,&b);
       for(j=1;j<=a;++j)
         scanf("%d",&x[j]);
       for(j=1;j<=b;++j)
       {
         scanf("%d",&y[j]);
         y[j]+=F;
       }
       if(a==0||b==0)
          continue;
       for(j=1;j<=a;++j)
         for(k=1;k<=b;++k)
             add(x[j],D+F+i),add(D+F+N+i,y[k]);
     }  
     for(i=1;i<=F;++i)
     {
         edge[0].push_back(i);
         edge[i].push_back(0);
         map[0][i]=1;
     }
     for(i=F+1;i<=F+D;++i)
     {
         edge[i].push_back(D+F+2*N+1);
         edge[D+F+2*N+1].push_back(i);
         map[i][D+F+2*N+1]=1;
     }
     sum=0;
     maxn=D+F+2*N+1;
     while(Ford());
     printf("%d\n",sum); 
   }
   return 0;
}

