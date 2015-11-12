#include<stdio.h>
#include<algorithm>
using namespace std; 
int i,j,k,m,n;
int map[400][400],x[110],y[110],sum;
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
  sum=0;
  for(i=1;i<=n;++i)
      if(x[i]+y[i]==n-1)
         ++sum;
  printf("%d\n",sum);
  return 0;
} 
