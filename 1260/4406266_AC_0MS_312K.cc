#include<stdio.h>
int main()
{
	int i,j,c,sum[101],f[101],a[101],b[101],t;
	scanf("%d",&t);
	while(t--)
	{
	  scanf("%d",&c);
	  for(i=1,sum[0]=0;i<=c;i++)
	  {
		scanf("%d%d",&a[i],&b[i]);
		sum[i]=sum[i-1]+a[i];
	  }
	  f[0]=0;
      for(i=1;i<=c;i++)
		 for(j=0;j<i;j++)
		    if(j==0||f[i]>f[j]+(sum[i]-sum[j]+10)*b[i])
			    f[i]=f[j]+(sum[i]-sum[j]+10)*b[i];
	  printf("%d\n",f[c]);
	}
    return 0;
}