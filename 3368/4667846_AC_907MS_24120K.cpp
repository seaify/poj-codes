#include<stdio.h>
#include<math.h>
const int maxn=100005;
int f[maxn][20],left[maxn][20],right[maxn][20],h[maxn],p[30],n;
void init()
{
 int m,i,j;
 m=int(log((double)n)/log(2.0));
 for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
   {
	   f[j][i]=f[j][i-1]>f[j+p[i-1]][i-1]?f[j][i-1]:f[j+p[i-1]][i-1];
	   if(h[j+p[i-1]-1]==h[j+p[i-1]])
	   {
		 f[j][i]=f[j][i]>right[j][i-1]+left[j+p[i-1]][i-1]?f[j][i]:right[j][i-1]+left[j+p[i-1]][i-1];
		 if(h[j]==h[j+p[i-1]-1])
			 left[j][i]=left[j][i-1]+left[j+p[i-1]][i-1];
		 else
			 left[j][i]=left[j][i-1];
		 if(h[j+p[i-1]]==h[j+p[i]-1])
			 right[j][i]=right[j+p[i-1]][i-1]+right[j][i-1];
		 else
			 right[j][i]=right[j+p[i-1]][i-1];
	   }
	   else
	   {
		left[j][i]=left[j][i-1];
		right[j][i]=right[j+p[i-1]][i-1];
	   }
   }
}
int Bsearch(int l,int r,int R)
{
   int mid;
   while(l<=r)
   {  
    mid=(l+r)/2;
    if(R>=h[mid])
      l=mid+1;
    else
      r=mid-1;
   }
   return r;
}
int Msearch(int l,int r,int R)
{
   int mid;
   while(l<=r)
   {  
    mid=(l+r)/2;
    if(R<=h[mid])
     r=mid-1;
    else
     l=mid+1;
   } 
   return l;
}
int RMQ(int i,int j)
{
 int m,max,s;
 m=int(log((double)(j-i+1))/log(2.0));
 max=f[i][m]>f[j-p[m]+1][m]?f[i][m]:f[j-p[m]+1][m];
 if(h[i+p[m]-1]==h[i+p[m]])
 {
   s=Bsearch(i+p[m],j,h[i+p[m]])-(i+p[m])+1;
   max=max>s+right[i][m]?max:s+right[i][m];
 }
 if(h[j-p[m]]==h[j-p[m]+1])
 {
   s=j-p[m]-Msearch(i,j-p[m],h[j-p[m]])+1;
   max=max>s+left[j-p[m]+1][m]?max:s+left[j-p[m]+1][m];
 }
 return max;
}
int main()
{
 int i,j,t;
 for(i=0;i<=20;i++)
	 p[i]=(1<<i);
 while(EOF!=scanf("%d",&n)&&n)
 {
 scanf("%d",&t);
 for(i=1;i<=n;i++)
 {
	scanf("%d",&h[i]);
	f[i][0]=1;
	right[i][0]=left[i][0]=1;
 }
 init();
 while(t--)
 {
   scanf("%d%d",&i,&j);
   printf("%d\n",RMQ(i,j));
 }
 }
 return 0;
}
