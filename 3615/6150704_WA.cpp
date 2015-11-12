#include<iostream>
const int INF=1000000;

int map[400][400],dis[400][400];
int n,m,t;

int main()
{
    int i,j,k,x,y,tmp,value;
    while(EOF!=scanf("%d %d %d",&n,&m,&t))
    {
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=n;j++)
                 map[i][j]=INF,dis[i][j]=INF;
             map[i][i]=0;
             dis[i][i]=0;
         }
         while(m--)
         {
            scanf("%d %d %d",&x,&y,&value);
            if(value<map[x][y])
               map[x][y]=value;
         }
         for(k=1;k<=n;k++)
           for(i=1;i<=n;i++)
             for(j=1;j<=n;j++)
             {
                 tmp=dis[i][k]>map[k][j]?dis[i][k]:map[k][j];
                 if(tmp<dis[i][j])
                   dis[i][j]=tmp; 
             } 
         while(t--)
         {
            scanf("%d %d",&x,&y);
            if(dis[x][y]==INF)
                 printf("-1\n");
            else
                 printf("%d\n",dis[x][y]); 
         }
    }
    return 0; 
}
