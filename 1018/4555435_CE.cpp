#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=100000000;
int i,j,t,m,n,k,a[1000],x[10000];
int maxx,d;
double total,max,temp;
struct node
{
	int b,p;
};
node c[100][100];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
      scanf("%d",&n);
	  k=1;
	  for(i=1;i<=n;i++)
	  {
		  scanf("%d",&a[i]);//每一个装置的个数
		  for(j=1;j<=a[i];j++)
		  {
			scanf("%d%d",&c[i][j].b,&c[i][j].p);	
			x[k++]=c[i][j].b;
		  }
	  }
	  sort(x+1,x+k);
	  m=k-1;max=0;
	  for(i=1;i<=m-n+1;i++)
	  {
		  total=0;
		  for(j=1;j<=n;j++)
		  {
			  temp=INF;
			  for(k=1;k<=a[j];k++)
			  {
			     if(c[j][k].b>=x[i]&&c[j][k].p<temp)
					 temp=c[j][k].p;	
			  }
			  if(temp==INF)
				  break;
			  else
				  total+=temp;
		  }
		  if(j==n+1&&x[i]*1.0/total>max)
			  max=x[i]*1.0/total;
	}
	 printf("%.3lf\n",max);
	}
	return 0;
}