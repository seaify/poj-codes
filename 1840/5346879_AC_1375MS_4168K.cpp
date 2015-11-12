#include<cstdio>
#include<algorithm>
using namespace std;
int a1,a2,a3,a4,a5,top,N,a[2000000],cnt[30000];
int i,j,k;
__int64 sum;

int main()
{
    while(EOF!=scanf("%d %d %d %d %d",&a1,&a2,&a3,&a4,&a5))
    {                    
          a3=-a3,a4=-a4,a5=-a5;
          top=0;
          for(i=-50;i<=50;++i)
              for(j=-50;j<=50;++j)
                    if(i*j!=0)
                           cnt[++top]=a1*i*i*i+a2*j*j*j;
          N=-1;
          for(i=-50;i<=50;++i)
             for(j=-50;j<=50;++j)
                for(k=-50;k<=50;++k)
                    if(i*j*k!=0)
                          a[++N]=a3*i*i*i+a4*j*j*j+a5*k*k*k;
          sort(a,a+N);
          sum=0;
          for(i=1;i<=top;++i)
                sum+=upper_bound(a,a+N,cnt[i])-lower_bound(a,a+N,cnt[i]);
          printf("%I64d\n",sum);
    }
    return 0;
}
