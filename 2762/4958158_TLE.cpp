#include<stdio.h>
#include<string.h>
int T,i,j,k,m,n,x,y;
bool map[1100][1100],last;
int main()
{
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    memset(map,false,sizeof(map));
    for(i=1;i<=n;++i)
        map[i][i]=true;
    while(m--)
    {
      scanf("%d%d",&x,&y);
      map[x][y]=true;
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
         for(j=1;j<=n;++j)
            map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
   last=true;
   for(i=1;i<n;++i)
      for(j=i+1;j<=n;++j)
         if(!map[i][j]&&!map[j][i])
         {
           last=false;
           break;
         }
    if(last)
       printf("Yes\n");
    else
       printf("No\n");
  }
}
