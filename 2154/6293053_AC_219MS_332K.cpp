#include<stdio.h>
#include<math.h>

int n,top,size,mod;
int prime[100000],flag[100000];
int p[100000],num[100000];
long long result;

void init()
{
    int i,j,limit;

    n=1000000000;

    limit=(int)(sqrt(n*1.00));
    for(i=3;i<=limit;i+=2)
         flag[i]=1;
    
    prime[1]=2;
    top=1;

    for(i=3;i<=limit;i+=2)
         if(flag[i])
         {
              prime[++top]=i;
              j=i*i;
              while(j<=limit)
              {
                   flag[j]=0;
                   j+=2*i;
              }
         }
}

void divide(int n)
{
    int i;
    size=0;
    for(i=1;i<=top&&prime[i]<=n;i++)
           if(n%prime[i]==0)
           {
                ++size;
		p[size]=prime[i];
                num[size]=0;
		while(n%prime[i]==0)
                     n/=prime[i],num[size]++;
           }
    if(n!=1)
    {
        ++size;
        p[size]=n;
        num[size]=1;
    }
}

long long check(long long a,long long n,long long mod)
{
    long long result=1;
    while(n)
    {
         if(n&1)
            result=(result*a)%mod;
         a=(a*a)%mod;
         n>>=1;
    }
    return result;
}

void dfs(int sum,int up,int down,int depth)
{
    int i,ans=1;

    if(depth==size+1)
    {
         long long L,tmp;
         tmp=n/sum;
         L=(tmp*up)/down;
         result=(result+L*check(n,sum-1,mod))%mod;
         return ;
    }

    for(i=0;i<=num[depth];i++)
    {
         if(i<num[depth])
               dfs(sum*ans,up*(p[depth]-1),down*p[depth],depth+1);
         else
               dfs(sum*ans,up,down,depth+1);   
   	 ans*=p[depth];
    }
    
}

void solve(int n)
{
    result=0;
    divide(n);
    dfs(1,1,1,1);
    printf("%lld\n",result);
}

int  main()
{
    int T;
    init();
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d %d",&n,&mod);
         solve(n);
    }
    return 0;
}