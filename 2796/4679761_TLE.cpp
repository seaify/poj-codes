#include<stdio.h>
#include<math.h>
const int maxn=100005;
int min[maxn][18],p[20],n,a[maxn];
__int64 sum[maxn],s,max;
void init()
{
 int m,i,j;
 m=int(log((double)n)/log(2.0));
 for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
   {
	   min[j][i]=min[j][i-1]<min[j+p[i-1]][i-1]?min[j][i-1]:min[j+p[i-1]][i-1];
   }
}
int RMQ(int i,int j)
{
 int m,a;
 m=int(log((double)(j-i+1))/log(2.0));
 a=min[i][m]<min[j-p[m]+1][m]?min[i][m]:min[j-p[m]+1][m];
 return a;
}
int main()
{
 int i,l,r,x,y,left,right,mid;
 for(i=0;i<=18;i++)
	 p[i]=(1<<i);
 scanf("%d",&n);
 sum[0]=0;
 for(i=1;i<=n;i++)
 {
	scanf("%d",&a[i]);
	min[i][0]=a[i];
	sum[i]=sum[i-1]+a[i];
 }
 init();
 for(i=1;i<=n;i++)
 {
  left=i;
  right=n;
  while(left<=right)
  {
	mid=(left+right)/2;
	if(RMQ(i,mid)>=a[i])
		left=mid+1;
	else
		right=mid-1;
  }
  r=right;
  left=1;
  right=i;
  while(left<=right)
  {
	mid=(left+right)/2;
	if(RMQ(mid,i)<a[i])
		left=mid+1;
	else
		right=mid-1;
  }
  l=left;
  s=(sum[r]-sum[l-1])*a[i];
  if(i==1||s>max)
  {
	max=s;
	x=l;
	y=r;
  }
 }
 printf("%I64d\n",max);
 printf("%d %d\n",x,y);
 return 0;
}
