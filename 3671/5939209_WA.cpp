#include<stdio.h>
int n,ans,f,g;
int p[40000];

int main()
{
    int i,x;
    while(EOF!=scanf("%d",&n))
    {
        p[0]=0;
        for(i=1;i<=n;i++)
        {
              p[i]=p[i-1];
              scanf("%d",&x);
              if(x==1)
                  p[i]++;
        }   
        ans=n;
        for(i=1;i<n;i++)
        {
            f=p[i];
            if(p[i]>i/2)
               f=i-p[i];     
            g=p[n]-p[i];
            if(2*g>n-i)
               g=n-i-g;
            if(f+g<ans)
               ans=f+g;                                            
        }     
        printf("%d\n",ans);                      
    }
    return 0;
}
