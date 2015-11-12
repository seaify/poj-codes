#include <stdio.h>


const int maxn=200000;

int n,tot;
int flag[1000],first[1000],d[1000];

struct cc
{
      int y,v,next;
};
//node f[2*1000];

cc e[1000];

void add(int x,int y,int v)
{
     ++tot;
     e[tot].y=y;
     e[tot].v=v;
     e[tot].next=first[x];
     first[x]=tot;
}

void dfs(int x,int dis)
{
     int tmp;
     d[x]=dis;
     flag[x]=0;
     for(tmp=first[x];tmp!=-1;tmp=e[tmp].next)
          if(flag[e[tmp].y])
             dfs(e[tmp].y,dis+e[tmp].v);
}


int main()
{
      int i,x,y,v;
      while(EOF!=scanf("%d",&n))
      {
            for(i=0;i<n;i++)
                first[i]=-1,flag[maxn]=1;
            tot=0;
            for(i=1;i<n;i++)
            {
                scanf("%d %d %d",&x,&y,&v);
                add(x,y,v);
                add(y,x,v);
            }
            dfs(0,0);
            for(i=0;i<n;i++)
                printf("%d\n",d[i]);
      }
    
      return 0;
}
