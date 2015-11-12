#include<stdio.h>
const int maxn=100005;
int a[maxn],left[maxn],right[maxn];
int i,j,x,y,n;
__int64 sum[maxn],max;
int main()
{
 scanf("%d",&n);
 sum[0]=0;
 for(i=1;i<=n;i++)
 {
	 scanf("%d",&a[i]);
	 sum[i]=sum[i-1]+a[i];
 }
 left[1]=1;
 for(i=2;i<=n;i++)
 {
  if(a[i-1]>=a[i])
  {
	j=i-1;
	while(left[j]>1&&a[left[j]-1]>=a[i])
		j=left[j]-1;
	left[i]=left[j];
  }
  else
	left[i]=i;
 }
 right[n]=n;
 for(i=n-1;i>=1;i--)
 {
  if(a[i+1]>=a[i])
  {
	j=i+1;
	while(right[j]<n&&a[right[j]+1]>=a[i])
		j=right[j]+1;
	right[i]=right[j];
  }
  else
	right[i]=i;
 }
 for(i=1;i<=n;i++)
 {
  if(i==1||(sum[right[i]]-sum[left[i]-1])*a[i]>max)
  {
	max=(sum[right[i]]-sum[left[i]-1])*a[i];
	x=left[i];
	y=right[i];
  }
 }
 printf("%I64d\n",max);
 printf("%d %d\n",x,y);
 return 0;
}