#include<stdio.h>
#include<string.h> 
#include<vector>
#include<algorithm>
using namespace std; 
vector < int > edge[210];
const int INF=100000000;
int map[210][210],p[210],pow[210],con[210],n,nc,np,m,sum,q[500000];
int temp,value;
bool  flag[210];char ch[100];
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
void add()
{
   int k,len;
   scanf("%s",ch);
   len=strlen(ch);
   temp=0;
   for(k=1;ch[k]!=')';++k)
   {
        temp*=10;
        temp+=(ch[k]-'0');
   }
   ++temp;
   value=0;
   for(++k;k<len;++k)//注意的地方。。。。 
    {
        value*=10;
        value+=(ch[k]-'0');
    }
}
int main()
{
   int i,j,k,len;
   while(EOF!=scanf("%d %d %d %d",&n,&np,&nc,&m))// m为边数，n为点数。。。 
   {
     memset(map,0,sizeof(map));//记录流量 
     for(i=0;i<=n+1;++i)//(1,0)10 
        edge[i].clear();
     while(m--)
     {
       scanf("%s",ch);
       len=strlen(ch); 
       i=0,j=0;
       for(k=1;ch[k]!=',';++k)
       {
          i*=10;
          i+=(ch[k]-'0');
       }
       for(++k;ch[k]!=')';++k)
       {
          j*=10;
          j+=(ch[k]-'0');
       }
       value=0;
       for(++k;k<len;++k)//注意的地方。。。。 
       {
          value*=10;
          value+=(ch[k]-'0');
       }
       ++i;++j;
       if(map[i][j]==0&&map[j][i]==0)
       {
           edge[i].push_back(j);
           edge[j].push_back(i);
       }
       map[i][j]=value;
     //  printf("%d %d %d\n",i,j,value);
     } 
     for(i=1;i<=np;++i)
     {
       add();
       edge[0].push_back(temp);
       edge[temp].push_back(0);
       map[0][temp]=value;
    //   printf("%d %d\n",temp,value);
     }
     for(i=1;i<=nc;++i)
     {
       add();
       edge[n+1].push_back(temp);
       edge[temp].push_back(n+1);
       map[temp][n+1]=value;
    //   printf("%d %d\n",temp,value);
     }
     sum=0;
     while(Ford());
     printf("%d\n",sum); 
   }
   return 0;
}
