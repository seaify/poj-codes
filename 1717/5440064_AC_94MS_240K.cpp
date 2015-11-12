#include<cstdio>
#include<cstring>
const int INF=1000000000;
int a[1100],b[1100],f[20000],s[20000],N,sum,left,right,i,j,ans;

int main()
{
	while(EOF!=scanf("%d",&N))  ////偏移量为6000,范围为-6000到6000
	{
	   sum=0;right=0;
       for(i=1;i<=N;++i)
	   {
		   scanf("%d %d",&a[i],&b[i]);
		   a[i]=a[i]-b[i];
		   if(a[i]>=0)
			   right+=a[i];
		   else
			   right+=-a[i];
		   sum+=a[i];
	   }
	   for(i=1;i<=N;++i)
		   a[i]=-2*a[i];
	   left=-right;
	   left=left+6000;
	   right=right+6000;
	   for(i=left;i<=right;++i)
		   f[i]=s[i]=INF;
	   f[sum+6000]=s[sum+6000]=0;
	   for(i=1;i<=N;++i)
	   {
		   for(j=left;j<=right;++j)
		   {
			   if(f[j]!=INF&&f[j]+1<s[j+a[i]])
				   s[j+a[i]]=f[j]+1;
		   }
		   for(j=left;j<=right;++j)
			   f[j]=s[j];
	   }
	   for(i=0;;++i)
	   {
		   if(f[6000+i]==INF&&f[6000-i]==INF)
			   continue;
		   if(f[6000+i]!=INF)
			   ans=f[6000+i];
		   if(f[6000-i]<ans)
			   ans=f[6000-i];
		   break;
	   }
	   printf("%d\n",ans);
	}
	return 0;
}