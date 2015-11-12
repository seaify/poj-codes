#include<iostream>

int N,ans,sumx,sumy,top;
int sum[200];

struct node
{
   int x,y;
};
node e[200],f[200];

void dfs(int i,int sumx,int sumy)
{
    if(i==N+1)
    {
       if(sumx>=0&&sumy>=0&&sumx+sumy>ans)
            ans=sumx+sumy;
       return ;
    }
  //  if(sumx+sumy+sum[N]-sum[i-1]<ans)
     //  return ;
    dfs(i+1,sumx+f[i].x,sumy+f[i].y);
    dfs(i+1,sumx,sumy);  
}

int main()
{
    int i,j;
    while(EOF!=scanf("%d",&N))
    {
        /*  top=0;
          sumx=0;
          sumy=0;*/
          for(i=1;i<=N;i++)
          {
             scanf("%d %d",&e[i].x,&e[i].y);
          /*   if(e[i].x+e[i].y<=0)
                  continue;
             else if(e[i].x>=0&&e[i].y>=0)
             {
                  sumx+=e[i].x;
                  sumy+=e[i].y;
             }
             else 
                  f[++top]=e[i];*/
             f[i]=e[i];
          }
          
          sum[0]=0;
          
          for(i=1;i<=N;i++)
             sum[i]=sum[i-1]+f[i].x+f[i].y;
          
          
          ans=-2000000;
          
          dfs(1,0,0);
          
          if(ans==-2000000)
               printf("0\n");
          else
               printf("%d\n",ans);
             
    }
    return 0;
}

