#include<stdio.h>
#include<math.h>

const int N=1024;

int n,top,c[40][40],a[40],prime[N],flag[2*N];

void init()
{
     int i,j;
     for(i=0;i<=30;i++)
         c[i][0]=c[i][i]=1;
     
     for(i=1;i<=30;i++)
        for(j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
     
     for(i=3;i<=N;i+=2)
            flag[i]=1;
     
     top=1;
     prime[1]=2;
     
     for(i=3;i<=N;i+=2)
     {
         if(flag[i])
         {
               j=i*i;
               while(j<=N)
               {
                    flag[j]=0;
                    j+=2*i;
               }
         }
     }
     
     for(i=3;i<=N;i+=2)
         if(flag[i])
              prime[++top]=i;
               
}

void solve(int n)
{
     int i,cx,p,m,sum,result;
     
     
     m=int(sqrt(1.0*n));
     sum=0;p=0;
     for(i=1;i<=top&&prime[i]<=n;i++)
     {
         cx=0;
         while(n%prime[i]==0)
         {
             n/=prime[i];
             cx++;
             sum++;
         }
         if(cx)
             a[++p]=cx;
     }
     
     result=1,cx=sum;
     for(i=1;i<=p;i++)
     {
         result*=c[sum][a[i]];
         sum-=a[i];
     }
     printf("%d %d\n",cx,result);
}

int main()
{
    init();
    while(EOF!=scanf("%d",&n))
    {
          solve(n);
    }
    return 0;
}
