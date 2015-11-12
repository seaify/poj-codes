#include<stdio.h>
#include<stdlib.h>
#define INF -10000
#define maxn 500002 
__int64 c;
struct node
{
	__int64 x,v;
}a[maxn];
int sum1[maxn],sum2[maxn],h;
node L[maxn],R[maxn];
int cmp(const void *a,const void *b)
{
	struct node *aa=(node *)a;
    struct node *bb=(node *)b;
    return aa->x-bb->x;
}
void merge(int p,int q,int r)
{
    __int64 m,n,i,j,k;
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
				c+=R[j].v*((n-i+1)*R[j].x-sum1[n]+sum1[i-1]);//用于求逆序数,算法导论习题
            j++;
       }
	}
}
void merge_sort(__int64 p,__int64 r)
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
int main()
{
    int i,n;
    scanf("%I64d",&h);
    for(i=1;i<=h;i++)
       scanf("%I64d%I64d",&a[i].v,&a[i].x);
	qsort(a+1,h,sizeof(a[1]),cmp);
    c=0;
    merge_sort(1,h);
    printf("%I64d\n",c);
	return 0;
}
