#include<iostream>
const int INF=10000000;

int map[400][400];
int n,m,t;

int main()
{
    int i,j,k,x,y,tmp,value;
    while(EOF!=scanf("%d %d %d",&n,&m,&t))
    {
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=n;j++)
                 map[i][j]=INF;
             map[i][i]=0;
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
                 tmp=map[i][k]>map[k][j]?map[i][k]:map[k][j];
                 if(tmp<map[i][j])
                   map[i][j]=tmp; 
             } 
         while(t--)
         {
            scanf("%d %d",&x,&y);
            if(map[x][y]==INF)
                 printf("-1\n");
            else
                 printf("%d\n",map[x][y]); 
         }
    }
    return 0; 
}
