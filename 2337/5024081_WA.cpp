#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool flag[30];
int first,in[30],map[30][30],minx,out[1100],tot;
char a[30];
vector < string > edge[30][30];
void dfs(int cur)
{
   int i;
   flag[cur]=true;
   ++first;
   for(i=0;i<26;++i)
      if(!flag[i]&&map[cur][i])
         dfs(i);
} 
void DFS(int cur)
{
   int i;
   for(i=0;i<26;++i)
      if(map[cur][i]!=0)
       {
          --map[cur][i];
          DFS(i);
       }
   ++tot;
   out[tot]=cur;
}
void solve(int k)
{
   int i,j;
   tot=0;
   if(k!=-1)
       DFS(k);
   else
       DFS(minx);
   for(i=0;i<26;++i)
     for(j=0;j<26;++j)
        sort(edge[i][j].begin(),edge[i][j].end());
   memset(map,0,sizeof(map));
   for(i=tot;i>=3;--i)
   {
        k=map[out[i]][out[i-1]];
        cout<<edge[out[i]][out[i-1]][k]<<".";
        ++map[out[i]][out[i-1]];
   }
   cout<<edge[out[2]][out[1]][map[out[2]][out[1]]]<<endl;
}
int main()
{
   int i,j,T,x,y,tag,n,k,last;
   scanf("%d",&T);
   while(T--)
   {
     scanf("%d",&n);
     for(i=0;i<26;++i)
        for(j=0;j<26;++j)
           edge[i][j].clear();
     memset(map,0,sizeof(map));
     memset(in,0,sizeof(in)); 
     memset(flag,false,sizeof(flag));
     tot=0;//顶点个数。。。。 
     minx=100;
     while(n--)
     {
        scanf("%s",a);
        k=strlen(a);
        x=a[0]-'a';//下标从0出发。。。。 
        y=a[k-1]-'a';
        ++in[y],--in[x];//入度。。。。 
        ++map[x][y];
        edge[x][y].push_back(a);
        if(x<minx)
            minx=x;
        if(y<minx)
            minx=y;
        if(!flag[x])
        {
           ++tot;
           flag[x]=true;
        }
        if(!flag[y])
        {
           ++tot;
           flag[y]=true;
        }
     }
     for(i=0;i<26;++i)
     {
        memset(flag,false,sizeof(flag));
        first=0;
        dfs(i);
        if(first==tot)
           break;
     }
     if(i==26)
     {
        printf("***\n");
        continue;
     } 
     tag=1;first=0;last=0;k=-1;
     for(i=0;i<26;++i)
        if(in[i]==0)
           continue;
        else if(in[i]==1)
           ++first;
        else if(in[i]==-1)
           {
             ++last;
             k=i;
           }
        else 
        {
           tag=0;
           break;
        }
     if(tag&&first==last&&first<=1)
         solve(k);
     else
     {
         printf("***\n"); 
         continue;
     }      
   }
   return 0;
}

