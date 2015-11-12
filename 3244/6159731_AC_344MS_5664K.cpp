#include<iostream>
#include<algorithm>
using namespace std;

int n;
int x[210000],y[210000],z[210000];
__int64 add[210000],tmp[210000];
__int64 sum;

void solve()
{
     int i;
     
     sort(tmp,tmp+n);
     
     add[0]=tmp[0];
     for(i=1;i<n;i++)
        add[i]=add[i-1]+tmp[i];
     
     for(i=1;i<n;i++)
        sum+=(tmp[i]*i-add[i-1]);

}

int main()
{
    int i;
    
    while(EOF!=scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
           scanf("%d %d %d",&x[i],&y[i],&z[i]);
           
        sum=0;
        
        for(i=0;i<n;i++)
           tmp[i]=x[i]-y[i];
        solve();

	
        
        for(i=0;i<n;i++)
           tmp[i]=x[i]-z[i];
        solve();
        
        for(i=0;i<n;i++)
           tmp[i]=y[i]-z[i];
        solve();
        
        printf("%I64d\n",sum/2);
        
    }
    return 0;
}
