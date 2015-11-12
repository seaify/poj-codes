#include<stdio.h>
#include<math.h>
const int maxn=1000005;
int min[maxn][20],max[maxn][20],p[22],i,j,n,t,x[maxn],y[maxn];
void init()
{
 int m;
 m=int(log((double)n)/log(2.0));
 for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
   {
	   max[j][i]=max[j][i-1]>max[j+p[i-1]][i-1]?max[j][i-1]:max[j+p[i-1]][i-1];
	   min[j][i]=min[j][i-1]<min[j+p[i-1]][i-1]?min[j][i-1]:min[j+p[i-1]][i-1];
   }
}
int RMQ(int i,int j)
{
  int m,a,b;
  m=int(log((double)(j-i+1))/log(2.0));
  a=max[i][m]>max[j-p[m]+1][m]?max[i][m]:max[j-p[m]+1][m];
  b=min[i][m]<min[j-p[m]+1][m]?min[i][m]:min[j-p[m]+1][m];
  x[i]=a,y[i]=b;
}
int main()
{
 for(i=0;i<=21;i++)
	 p[i]=(1<<i);
 while(EOF!=scanf("%d%d",&n,&t))
 {
  for(i=1;i<=n;i++)
  {
	scanf("%d",&min[i][0]);
	max[i][0]=min[i][0];
  }
  init();
  for(i=1;i<=n-t+1;++i)
   RMQ(i,i+t-1);
  for(i=1;i<n-t+1;++i)
    printf("%d ",y[i]);
    printf("%d\n",y[i]);
  for(i=1;i<n-t+1;++i)
    printf("%d ",x[i]);
  printf("%d\n",x[i]);
 
 }
 return 0;
}
