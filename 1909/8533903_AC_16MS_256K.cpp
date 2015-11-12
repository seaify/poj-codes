#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int maxn=10010;
int out[maxn],c[maxn],f[maxn],q[maxn];

int main()
{
    int i,n,k,s,t,x,y,z,p,tmp,sum;
    while(EOF!=scanf("%d",&n)&&n)
    {
          t=0,sum=0;
          for(i=1;i<=n;i++)
          {
              scanf("%d %d %d",&x,&y,&k);
              c[x]=y;
              out[x]=k;
              if(out[x]==0)
                 q[++t]=x;
              while(k--)
              {
                   scanf("%d",&z);
                   f[z]=x;
              }
          }          
          for(s=1;s<n;s++)
          {
              tmp=q[s];
              p=f[tmp];
              c[p]+=c[tmp]-1;
              out[p]--;
              if(out[p]==0)
                 q[++t]=p;
              sum+=abs(c[tmp]-1);          
          }
          printf("%d\n",sum);          
    }
    return 0;
}
