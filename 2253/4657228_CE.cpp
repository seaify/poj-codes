#include<stdio.h>
#include<math.h>
const int maxn=210;
double map[maxn][maxn],min[maxn],k;
bool flag[maxn];
int x[maxn],y[maxn];
int main()
{
 int i,j,n,c,t;
 t=1;
 while(EOF!=scanf("%d",&n)&&n)
 {
   for(i=1;i<=n;i++)
	   scanf("%d%d",&x[i],&y[i]);
   for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	   {
		   map[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
           flag[i]=false;
	   }
  for(i=2;i<=n;i++)
	  min[i]=map[1][i];
  min[1]=0;flag[1]=true;
  for(i=2;i<=n;i++)
  {
	k=2000;
	for(j=2;j<=n;j++)
	  if(!flag[j]&&min[j]<k)
	  {
		c=j;
		k=min[j];
	  }
	flag[c]=true;
	if(flag[2])
		break;
	for(j=2;j<=n;j++)
		if(!flag[j])
		{
			k=k>map[c][j]?k:map[c][j];
			if(k<min[j])
			   min[j]=k;
		}
  }
  printf("Scenario #%d\n",t++);
  printf("Frog Distance = %.3lf\n\n",min[2]);
 }
 return 0;
}