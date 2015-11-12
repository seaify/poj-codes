#include<iostream>

const int INF=100000000;

int d[1100],path[1100],flag[1100],map[1100][1100];
int m,n;

void dfs(int x)
{
     if(x!=1)
        dfs(path[x]);
     printf("%d\n",x);
}

void Dijkstra()
{
    int i,j,x,min;
    
    for(i=1;i<=n;i++)
         d[i]=INF,flag[i]=1;
    d[1]=0;
    
    for(i=1;i<=n;i++)
    {
         x=-1;
         min=INF;
         for(j=1;j<=n;j++)
             if(flag[j]&&d[j]<min)
                min=d[j],x=j;
         if(x==-1)
         {
              printf("-1\n");
              return ;
         }
         if(x==n)
         {
              printf("%d\n",d[n]+1);
              dfs(n);
         }
         flag[x]=0;
         for(j=1;j<=n;j++)
             if(flag[j]&&d[x]+map[x][j]<d[j])
                  d[j]=d[x]+map[x][j],path[j]=x;
    }
}

int main()
{
    int i,j,x,y;
    while(EOF!=scanf("%d %d",&m,&n))
    {
         for(i=1;i<=n;i++)
         {
            for(j=1;j<=n;j++)
                  map[i][j]=INF;
            map[i][i]=0;
         }
         
         while(m--)
         {
              scanf("%d %d",&x,&y);
              if(x==y)
                  continue;
              map[x][y]=1;
         }
         
         Dijkstra(); 
                         
    }
    
    return 0;
    
}
