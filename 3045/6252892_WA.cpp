#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int w,s;
};
node a[51000];

int n;
__int64 sum,ans;

int cmp(node a,node b)
{
    return a.w+a.s>b.w+b.s;
}

int main()
{
    int i;
    while(EOF!=scanf("%d",&n))
    {
         sum=0;
         for(i=0;i<n;i++)
         {
             scanf("%d %d",&a[i].w,&a[i].s);
             sum+=a[i].w;
         }
         
         sort(a,a+n,cmp);
         
         printf("%I64d\n",sum-a[0].w-a[0].s);
               
    }
    return 0;
}
