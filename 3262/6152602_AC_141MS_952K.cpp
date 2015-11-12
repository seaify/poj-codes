#include<iostream>
#include<algorithm>
using namespace std;

int n;
__int64 sum,ans;

struct node
{
    int d,t; 
};
node e[110000];

int cmp(node a , node b)
{
    return a.t*b.d<b.t*a.d; 
}

int main()
{
    int i;
    while(EOF!=scanf("%d",&n))
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
          scanf("%d %d",&e[i].t,&e[i].d);
          e[i].t*=2;
          sum+=e[i].d;
        }
        sort(e+1,e+n+1,cmp); 
        ans=0;
        for(i=1;i<n;i++)
        {
            ans+=(sum-e[i].d)*e[i].t;
            sum-=e[i].d;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
