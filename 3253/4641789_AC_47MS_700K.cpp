#include<stdio.h>
const int maxn=50010;
__int64 a[maxn],b[maxn],c[maxn];
__int64 open1,open2,closed1,closed2;
int n;
void counting_sort(__int64 k)
{
int i,j;
for(i=0;i<=k;i++)
       c[i]=0;
for(j=1;j<=n;j++)
   c[b[j]]++;
for(i=1;i<=k;i++)
   c[i]=c[i]+c[i-1];
for(j=n;j>=1;j--)
{
   a[c[b[j]]]=b[j];
   c[b[j]]--;
}
}
__int64 getmin()
{
	__int64 p;
	if(open1>closed1)
	{
		p=b[open2];open2++;
	}
	else if(open2>closed2)
	{
		p=a[open1];open1++;
	}
	else if(a[open1]<b[open2])
	{
		p=a[open1];open1++;
	}
	else
	{
		p=b[open2];open2++;
	}
    return p;
}
int main()
{
int i;
__int64 x,y,s,max;
scanf("%d",&n);
max=-1;
for(i=1;i<=n;i++)
 {
    scanf("%d",&b[i]);
    if(b[i]>max)
     max=b[i];
  }
counting_sort(max);
 s=0;
 open1=1;closed1=n;
 open2=1;closed2=0;
 s=0;
 for(i=1;i<n;i++)
 {
   x=getmin();
   y=getmin();
   s+=x+y;
   closed2++;
   b[closed2]=x+y;
 }
 printf("%I64d\n",s);
return 0;
}
