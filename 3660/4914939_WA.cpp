#include<stdio.h>
#include<algorithm>
using namespace std; 
int i,j,k,m,n;
int map[400][400],flag[110],x[110],y[110],sum;
int cmp(int a,int b)
{
   return a>b;///为什么会这样呢 
}
int main()
{
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
   {
   for(j=1;j<=n;j++)
           map[i][j]=0;
   }
 while(m--)
 {
   scanf("%d%d",&i,&j);
   map[i][j]=1;
 }
 for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
             map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
  for(i=1;i<=n;++i)
  {
     x[i]=0;y[i]=0;
     for(j=1;j<=n;++j)
     {
         x[i]+=map[i][j];
         y[i]+=map[j][i];//每一列的和 
     }
  }   
  sort(x+1,x+n+1,cmp);
  sort(y+1,y+n+1);
  memset(flag,false,sizeof(flag));
  for(i=1;i<=n;++i)
  {
     if(x[i]==n-i)
         flag[i]=true;
     else
         break;
  }
  for(i=n;i>=1;--i)
  {
     if(y[i]==i-1)
         flag[i]=true;
     else
         break;
  }
  sum=0;
  for(i=1;i<=n;++i)
      if(flag[i])
         ++sum;
  printf("%d\n",sum);
  return 0;
} 
