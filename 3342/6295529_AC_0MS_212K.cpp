#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
 
map < string ,int > W;
vector < int > v[210];

int n,tot,flag,result;
int f[210][2],num[210][2];
char a[210],b[210];

void dfs(int x,int father)
{
    int i,y;
    f[x][1]=1;
    f[x][0]=0;
    num[x][1]=1;
    num[x][0]=1;
    for(i=0;i<v[x].size();i++)
    {
        y=v[x][i];
        if(y==father)
           continue;
        dfs(y,x);
        if(f[y][0]==f[y][1])
             num[x][0]=0,f[x][0]+=f[y][0];
        else if(f[y][0]>f[y][1])
             num[x][0]&=num[y][0],f[x][0]+=f[y][0];
        else 
             num[x][0]&=num[y][1],f[x][0]+=f[y][1];
        f[x][1]+=f[y][0];
        num[x][1]&=num[y][0];
    }
}

int main()
{
    int i,x,y;
    while(EOF!=scanf("%d",&n)&&n)
    {
         W.clear();
         tot=0;
         flag=1;
         for(i=1;i<=n;i++)
             v[i].clear();
         scanf("%s",a);
         W[a]=++tot;
         for(i=1;i<n;i++)
         {
             scanf("%s %s",a,b);
             if(W.count(a)==0)
                W[a]=++tot;
             if(W.count(b)==0)
                W[b]=++tot;
             x=W[a];
             y=W[b];
             v[y].push_back(x);
         }
         
         dfs(1,-1);
         
         result=f[1][1]>f[1][0]?f[1][1]:f[1][0];
         printf("%d ",result);
         
       //  printf("%d %d\n",num[1][0],num[1][1]);
         
         if(f[1][1]==f[1][0])
               flag=0;
         else if(f[1][1]>f[1][0]&&num[1][1]==0)
               flag=0;
         else if(f[1][0]>f[1][1]&&num[1][0]==0)
               flag=0;
         
         if(flag)
             printf("Yes\n");
         else
             printf("No\n");   
    }
    return 0;
}

