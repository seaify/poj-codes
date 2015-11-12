#include<stdio.h>
int a[100005],f[100005],i,len,n,left,mid,right,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	f[1]=a[1];len=1;
	for(i=2;i<=n;i++)
	{
	  if(a[i]>f[len])
	  {
	    len++;
	    f[len]=a[i];
	  }
	  else
	  {
		left=1;
		right=len;
		while(left<=right)
		{
		  mid=(left+right)/2;
		  if(a[i]>=f[mid])
		     left=mid+1;
		  else
		     right=mid-1;
		}
		f[left]=a[i];
	  }
	} 
	printf("%d\n",len);	
   }

	return 0;
}
