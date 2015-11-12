#include<stdio.h>

#define size r-l+1

__int64 n,m,l,r;
__int64 a[100000],sum[100000],q[100000],f[100000];


int main()
{
    __int64 i,j,x,y,z,b,c,T;
  
    scanf("%I64d",&T);
    while(T--)
    {
          scanf("%I64d %I64d",&n,&m);
          sum[0]=0;
          for(i=1;i<=n;i++)
          {
              scanf("%I64d",&a[i]);
              sum[i]=sum[i-1]+a[i];
          }
          f[0]=0;
          l=1,r=1,q[1]=0;
          for(i=m;i<2*m;i++)
              f[i]=sum[i]-i*a[1];
              
          for(i=2*m,j=m;i<=n;i++,j++)
          {
              
              while(size>=2)
              {
                  b=q[r-1];
                  c=q[r];
                  x=f[b]+b*a[b+1]-sum[b];
                  y=f[c]+c*a[c+1]-sum[c];
                  z=f[j]+j*a[j+1]-sum[j];
                  if((y-x)*(a[j+1]-a[c+1])>=(z-y)*(a[c+1]-a[b+1]))
                       r--;
                  else
                       break;
              }
              q[++r]=j;
              while(size>=2)
              {
                 b=q[l];
                 c=q[l+1];
                 x=f[b]+b*a[b+1]-sum[b];
                 y=f[c]+c*a[c+1]-sum[c];
                 if(y-x<=i*(a[c+1]-a[b+1]))
                      l++;
                 else
                      break;

			  }
              b=q[l];
              f[i]=f[b]+(sum[i]-sum[b]-(i-b)*a[b+1]);
          }
          printf("%I64d\n",f[n]);
    }
    return 0;
}