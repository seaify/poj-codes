#include<stdio.h>

int n,S,a[200000],sum[200000];

int check(int i)
{
    int left=1,right=i,mid;
    while(left<=right)
    {
         mid=(left+right)/2;
         if(sum[i]-sum[mid-1]>=S)
                left=mid+1;
         else
                right=mid-1;
    }
    return  i-right+1;
}

int main()
{
    int i,T,tmp,result;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d %d",&n,&S);
         sum[0]=0;
         for(i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
             sum[i]=sum[i-1]+a[i];
         }
         result=0;
         for(i=n;i>=1&&sum[i]>=S;i--)
         {
               tmp=check(i);
               if(result==0||tmp<result)
                  result=tmp;
         }
         printf("%d\n",result);
    }
    return 0;
}
