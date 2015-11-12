#include<iostream>

int n,result,x,a[5100],sum[5100];

int solve(int R)
{
    int i,tmp;
    
    for(i=0;i<=n;i++)
        sum[i]=0;
    
    sum[1]=a[1];
    for(i=2;i<=n;i++)
    {
        tmp=a[i]+sum[i-1];
        if(i-R>0)
          tmp-=sum[i-R];
        if(i>n-R+1)
        {
           if(tmp&1)
               return 2*n;
           sum[i]=sum[i-1];
        }
        else
            sum[i]=sum[i-1]+(tmp&1);
    }
        
    return sum[n];
    
}

int main()
{
    int i,tmp;
    char ch[4];
    while(EOF!=scanf("%d",&n))
    {
        for(i=1;i<=n;i++) 
        {
            scanf("%s",ch);
            if(ch[0]=='B')
                 a[i]=1;
            else
                 a[i]=0;
        }
        result=2*n;
        for(i=1;i<=n;i++)
        {
            tmp=solve(i);
            if(tmp<result)
            {
                  result=tmp;
                  x=i;
            }
        }
        printf("%d %d\n",x,result); 
    }
    return 0;
}

