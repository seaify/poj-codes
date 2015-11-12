#include<stdio.h>
#include<math.h>
const int maxn=50005;
int min[maxn][18],max[maxn][18],p[20],i,j,n,t;
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
 return a-b;
}
int main()
{
 for(i=0;i<=16;i++)
	 p[i]=(1<<i);
 scanf("%d%d",&n,&t);
 for(i=1;i<=n;i++)
 {
	scanf("%d",&min[i][0]);
	max[i][0]=min[i][0];
 }
 init();
 while(t--)
 {
   scanf("%d%d",&i,&j);
   printf("%d\n",RMQ(i,j));
 }
 return 0;
}