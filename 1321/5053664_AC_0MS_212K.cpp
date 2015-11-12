#include<stdio.h>
#include<string.h>
char map[100][100];
int n,k,sum;
bool C[100],R[100];
void  dfs(int x,int y,int depth)
{
  int i,j;
  if(depth==k)
  {
    ++sum;
    return ;
  }
  for(i=x+1;i<=n+1+depth-k;++i)
    if(!R[i])
    for(j=1;j<=n;++j)
        if(!C[j]&&map[i][j]=='#')
        {
             R[i]=true,C[j]=true;
             dfs(i,j,depth+1);
             R[i]=false,C[j]=false;
        } 
}
int main()
{
   int i,j;
   while(EOF!=scanf("%d%d",&n,&k))
   {
      if(n==-1&&k==-1)
          break;
      for(i=1;i<=n;++i)
         scanf("%s",&map[i][1]);
      sum=0;
      for(i=1;i<=n+1-k;++i)
        for(j=1;j<=n;++j)
          if(map[i][j]=='#')
          {
             memset(R,false,sizeof(R));
             memset(C,false,sizeof(C));
             R[i]=true,C[j]=true;
             dfs(i,j,1);
          }
      printf("%d\n",sum);
   }
   return 0;
}
