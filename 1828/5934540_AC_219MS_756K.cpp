#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int x[51000],y[51000],p[51000];

int cmp(int i,int j)
{
    if(x[i]!=x[j])
         return x[i]<x[j];
    else
         return y[i]<y[j];
}

int main()
{
    int i,tmp,ans;
    while(EOF!=scanf("%d",&n))
    {
         if(n==0)
           break;
         for(i=0;i<n;i++)
         {
             scanf("%d %d",&x[i],&y[i]);
             p[i]=i;
         }
         sort(p,p+n,cmp);
         ans=1;
         tmp=y[p[n-1]];
         for(i=n-2;i>=0;i--)
         {
             if(tmp<y[p[i]])
             {
                 ans++;
                 tmp=y[p[i]];
             }
         }
         printf("%d\n",ans);
    }
}
