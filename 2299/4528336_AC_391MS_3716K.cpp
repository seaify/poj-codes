#include<stdio.h>
#define INF 1000000000
#define maxn  500002 
int L[maxn],R[maxn],a[maxn];
__int64 c;
void merge(int p,int q,int r)
{
    int m,n,i,j,k;
    m=q-p+1;
    n=r-q;
    for(i=1;i<=m;i++)
       L[i]=a[p+i-1];
    for(j=1;j<=n;j++)
       R[j]=a[q+j];
    L[m+1]=INF;
    R[n+1]=INF;
    i=1;j=1;
    for(k=p;k<=r;)
       if(L[i]<R[j])
       {
            a[k]=L[i];
            i++;
            k++;
       }
       else if(L[i]>R[j])
       {
            a[k]=R[j];
            if(i<=m)
               c+=m-i+1;
            j++;
            k++;
       }
       else
       {
          a[k]=a[k+1]=L[i];
          k=k+2;
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
int main()
{
    int i,n;
    while(EOF!=scanf("%d",&n)&&n)
    {
      for(i=1;i<=n;i++)
         scanf("%d",&a[i]);
      c=0;
      merge_sort(1,n);
     // for(i=1;i<=n;i++)
         //printf("%d ",a[i]);
      //printf("\n");
      printf("%I64d\n",c);
    }
}
