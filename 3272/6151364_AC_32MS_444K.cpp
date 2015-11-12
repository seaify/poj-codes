#include<iostream>

int first[6000],first1[6000],in[6000],sum[6000],f[6000];
int n,m,tot,ans;

struct node
{
    int x,y,next;
};

node e[60000],r[60000];

void add(int x,int y)
{
     e[++tot].x=x;
     e[tot].y=y;
     e[tot].next=first[x];
     first[x]=tot;
     
     r[tot].x=y;
     r[tot].y=x;
     r[tot].next=first1[y];
     first1[y]=tot;
}

int main()
{
    int i,x,y,tmp;
    
    while(EOF!=scanf("%d %d",&n,&m))
    {
                         
         tot=0;
         
         for(i=0;i<=n;i++)
            first1[i]=first[i]=-1,in[i]=1;
            
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
         
         f[n]=1;
         for(i=n-1;i>=0;i--)
         {
            tmp=first1[i];
            f[i]=0;
            while(tmp!=-1)
            {
                 y=r[tmp].y;
                 f[i]+=f[y];
                 tmp=r[tmp].next;                
            }
         }
         
       /*  printf("\n");
         for(i=1;i<=n;i++)
             printf("%d %d\n",sum[i],f[i]);*/
         
         ans=0;
         
         for(i=1;i<=tot;i++)
         {
             x=r[i].x;
             y=r[i].y;
             if(x==0)
               continue;
             //printf("%d %d\n",x,y);
             if(sum[x]*f[y]>ans)
               ans=sum[x]*f[y];
         }
         
         
         
         printf("%d\n",ans);
                 
    }
    return 0;
}
