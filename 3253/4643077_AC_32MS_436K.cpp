#include<stdio.h>
#include<stdlib.h>
const int maxn=20010;
__int64 a[maxn],b[maxn];
int open1,open2,closed1,closed2;
int n;
int cmp(const void *a,const void *b)
{
	return(*(int *)a-*(int *)b);
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
__int64 x,y,s;
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
qsort(a+1,n,sizeof(a[1]),cmp);
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

