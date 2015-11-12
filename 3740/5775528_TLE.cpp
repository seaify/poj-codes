#include<stdio.h>
int p[400],a[20][400];
int m,n,i,j,t,total,flag;

int main()
{
    while(EOF!=scanf("%d %d",&m,&n))
    {
        for(i=0;i<m;i++)
          for(j=0;j<n;j++)
             scanf("%d",&a[i][j]);
                          
        for(i=0;i<n;i++)
        {
           p[i]=0;
           for(j=0;j<m;j++)
              p[i]+=a[j][i]*(1<<j);
        }
        total=(1<<n);
        flag=0;
        for(i=1;i<total;i++)
        {   
        
            for(j=0;j<n;j++)
            {
                t=i&p[j];
                if(t&&t==(t&-t))
                   continue;
                else
                    break;
            }
            if(j==n)
            {
               flag=1;
               break;
            }
        }
        if(flag)
             printf("Yes, I found it\n");
        else
             printf("It is impossible\n");
              
    }
    return 0;
}
