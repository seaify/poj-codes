#include<iostream>

int n,result;
int f[1600][2],map[1600][16],num[1600];

void dfs(int x,int father)
{
    int i,y;
    f[x][1]=1;
    f[x][0]=0;
    for(i=1;i<=num[x];i++)
    {
        y=map[x][i];
        if(y==father)
           continue;
        dfs(y,x);
        f[x][0]+=f[y][1];
        if(f[y][0]<f[y][1])
            f[x][1]+=f[y][0];
        else
            f[x][1]+=f[y][1];
    }
}

int main()
{
    int i,x,y,c;
    while(EOF!=scanf("%d",&n))
    {
         for(i=0;i<n;i++)
              num[i]=0;
         for(i=0;i<n;i++)
         {
             scanf("%d:(%d)",&x,&c);
             while(c--)
             {
                  scanf("%d",&y);
                  map[x][++num[x]]=y;
                  map[y][++num[y]]=x;
             }
         }
         dfs(0,-1);
         result=f[0][0]<f[0][1]?f[0][0]:f[0][1];
         printf("%d\n",result);
    }
    return 0;
}

