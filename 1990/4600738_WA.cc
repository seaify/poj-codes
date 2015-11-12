#include<stdio.h>
#define INF -10000
#define maxn 30010 
__int64 c;
struct node
{
__int64 x,v;
}a[maxn];
int count[maxn];
__int64 sum1[maxn],sum2[maxn];
node L[maxn],R[maxn],b[maxn],t;
void merge(int p,int q,int r)
{
    int m,n,i,j,k;
   if(r-p+1<=8)
	{
		for(i=p;i<=q;i++)
		 for(j=q+1;j<=r;j++)
            if(a[i].v>=a[j].v)
				c+=a[i].v*(a[j].x-a[i].x);
			else
			{
				c+=a[j].v*(a[j].x-a[i].x);
				t=a[i];
				a[i]=a[j];
				a[j]=t;	
			}
	   return ;
	}
    m=q-p+1;
    n=r-q;
sum1[0]=0;
    for(i=1;i<=m;i++)
{
   L[i]=a[p+i-1];
   sum1[i]=sum1[i-1]+L[i].x;
}
sum2[0]=0;
    for(j=1;j<=n;j++)
{
   R[j]=a[q+j];
   sum2[j]=sum2[j-1]+R[j].x;
}
    L[m+1].v=INF;
    R[n+1].v=INF;
    i=1;j=1;
    for(k=p;k<=r;k++)
{
   if(L[i].v>R[j].v)
       {
            a[k]=L[i];
    if(j<=n)
     c+=L[i].v*(sum2[n]-sum2[j-1]-(n-j+1)*L[i].x);
            i++;
       }
       else
       {
            a[k]=R[j];
            if(i<=m)
     c+=R[j].v*((m-i+1)*R[j].x-sum1[m]+sum1[i-1]);
            j++;
       }
}
}
void merge_sort(int p,int r)
{
    int q;
    if(p<r)
    {
       q=(p+r)/2;
       merge_sort(p,q);
       merge_sort(q+1,r);
       merge(p,q,r);
    }
}
void counting_sort(int k,int h)
{
	int i;
	for(i=1;i<=k;i++)
		count[i]=0;
	for(i=1;i<=h;i++)
        count[b[i].x]++;
	for(i=2;i<=k;i++)
		count[i]=count[i]+count[i-1];
	for(i=h;i>=1;i--)
		a[count[b[i].x]]=b[i];
}
int main()
{
    int i,h,max;
    scanf("%d",&h);
	max=INF;
    for(i=1;i<=h;i++)
	{
	 scanf("%I64d%I64d",&b[i].v,&b[i].x);
	 if(b[i].x>max)
		 max=b[i].x;
	}
	counting_sort(max,h);
    c=0;
    merge_sort(1,h);
    printf("%I64d\n",c);
return 0;
}

 

