#include<iostream>

int first[6000],in[6000],sum[6000];
int n,m,tot;

struct node
{
    int x,y,next;
};

node e[60000];

void add(int x,int y)
{
     e[++tot].x=x;
     e[tot].y=y;
     e[tot].next=first[x];
     first[x]=tot;
}

int main()
{
    int i,x,y,tmp;
    
    while(EOF!=scanf("%d %d",&n,&m))
    {
                         
         tot=0;
         
         for(i=0;i<=n;i++)
            first[i]=-1,in[i]=1;
            
         while(m--)
         {
            scanf("%d %d",&x,&y);
            add(y,x);
            in[y]=0;
         }
         
         for(i=1;i<=n;i++)
            if(in[i])
               add(i,0);
               
         sum[0]=1;
         
         for(i=1;i<=n;i++)
         {
             tmp=first[i];
             sum[i]=0;
             while(tmp!=-1)
             {
                 y=e[tmp].y;
                 sum[i]+=sum[y];
                 tmp=e[tmp].next;
             }
         }
         
         printf("%d\n",sum[n]);
         
         
         
    }
    return 0;
}
