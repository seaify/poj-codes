#include<stdio.h>
const int maxn=20010;
__int64 a[maxn],t,s;
void min_heap(int i,int n)
{
int min,l,r;
l=2*i;
r=2*i+1;
if(l<=n&&a[l]<a[i])
   min=l;
else
   min=i;
if(r<=n&&a[r]<a[min])
   min=r;
if(min!=i)
{
   t=a[i];
   a[i]=a[min];
   a[min]=t;
   min_heap(min,n);
}
}
void build_heap(int n)
{
int i;
for(i=n/2;i>=1;i--)
   min_heap(i,n);
}
int main()
{
int i,n;
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
   build_heap(n);
   s=0;
   while(n!=1)
   {
	   t=a[1];a[1]=a[n];a[n]=t;
	   min_heap(1,n-1);
	   n--;
	   t=a[1];a[1]=a[n];a[n]=t;
	   min_heap(1,n-1);
	   a[n]=a[n]+a[n+1];
	   s=s+a[n];
   }
   printf("%I64d\n",s);
return 0;
}
