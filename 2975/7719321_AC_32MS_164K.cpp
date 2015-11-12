#include<stdio.h>

int p[40];
int n;

int main()
{
 int i,j,x;
     while(EOF!=scanf("%d",&n)&&n)
{
       for(i=30;i>=0;i--)
           p[i]=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(j=30;j>=0;j--)
                 if(x&(1<<j))
                      ++p[j];
        }
        
        for(i=30;i>=0;i--)
           if(p[i]&1)
           {
                printf("%d\n",p[i]);
                break;
           }

        if(i==-1)
                printf("0\n");
        
}
     return 0;
}
