#include<iostream>

int N,ans,sumx,sumy,top;

struct node
{
   int x,y;
};
node e[200],f[200];

void dfs(int i,int sumx,int sumy)
{
    if(i==top+1)
    {
       if(sumx>=0&&sumy>=0&&sumx+sumy>ans)
            ans=sumx+sumy;
       return ;
    }
    dfs(i+1,sumx+e[i].x,sumy+e[i].y);
    dfs(i+1,sumx,sumy);  
}

int main()
{
    int i,j;
    while(EOF!=scanf("%d",&N))
    {
          top=0;
          sumx=0;
          sumy=0;
          for(i=1;i<=N;i++)
          {
             scanf("%d %d",&e[i].x,&e[i].y);
             if(e[i].x+e[i].y<=0)
                  continue;
             else if(e[i].x>=0&&e[i].y>=0)
             {
                  sumx+=e[i].x;
                  sumy+=e[i].y;
             }
             else 
                  f[++top]=e[i];
          }
          
          ans=sumx+sumy;
          
          dfs(1,sumx,sumy);
          
          printf("%d\n",ans);
             
    }
    return 0;
}

