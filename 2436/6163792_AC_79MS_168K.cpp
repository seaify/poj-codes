#include<iostream>

int state[40000],p[30];
int N,D,K,top,sum,ans;

int main()
{
    int i,j,c,x;
    
    for(i=0;i<=20;i++)
       p[i]=(1<<i);

    while(EOF!=scanf("%d %d %d",&N,&D,&K))
    {
        for(i=1;i<=N;i++)
        {
             scanf("%d",&c);
             sum=0;
             for(j=1;j<=c;j++)
             {
                scanf("%d",&x);
                sum+=p[x-1];
             }
             state[i]=sum;
        }              
        
        ans=0;
        
        for(i=p[K]-1;i<p[D];i++)   
        {
             c=0;                      
             for(j=0;j<D;j++) 
                if(i&p[j])
                   c++;
                   
             if(c==K)
             {
                 sum=0;
                 for(j=1;j<=N;j++)
                 {
                    x=i&state[j];
                    if(x==state[j])
                      sum++;
                 }
                 if(sum>ans)
                    ans=sum;
             }
        }
        
        printf("%d\n",ans);
               
    } 
    return 0;
}
