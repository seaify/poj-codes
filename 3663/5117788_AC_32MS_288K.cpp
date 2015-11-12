#include<stdio.h>
#include<algorithm>
using namespace std;
int x[21000],n,sum,cnt;
int Bsearch(int beg,int v)
{
   int left=beg,mid,right=n-1;
   while(left<=right)
   {
      mid=(left+right)/2;
      if(v>=x[mid])
          left=mid+1;
      else
          right=mid-1;
   }
   return right-beg+1;
}
int main()
{
  int i;
  while(EOF!=scanf("%d%d",&n,&sum))
  {
     for(i=0;i<n;++i)
        scanf("%d",&x[i]);
     sort(x,x+n);
     cnt=0;
     for(i=0;i<n-1;++i)
     {
        if(sum<2*x[i])
           break;
        cnt+=Bsearch(i+1,sum-x[i]);
     }
     printf("%d\n",cnt);
  }
}
