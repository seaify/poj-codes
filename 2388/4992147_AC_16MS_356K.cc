#include<stdio.h>
#include<algorithm>
using namespace std;
int a[11000],i,n;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
       scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    n=(n+1)/2;
    printf("%d\n",a[n]);
    return 0;
}
