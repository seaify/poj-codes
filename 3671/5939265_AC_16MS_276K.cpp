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
              if(x==2)
                  p[i]++;
        }   
        ans=p[n]<n-p[n]?p[n]:n-p[n];
		if(ans)
        for(i=1;i<n;i++)
        {
            f=p[i];
            g=n-i-p[n]+p[i];
            if(f+g<ans)
               ans=f+g;                                            
        }     
        printf("%d\n",ans);                      
    }
    return 0;
}
