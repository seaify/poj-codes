#include<iostream>

int first[2000],flag[2000];
int n,m,tot,sum;

struct node
{
    int x,y,next;
};

node e[20000];

void add(int x,int y)
{
     e[++tot].x=x;
     e[tot].y=y;
     e[tot].next=first[x];
     first[x]=tot;
}

void dfs(int x)
{
     int tmp,y;
     tmp=first[x];
     while(tmp!=-1)
     {
         y=e[tmp].y;
         if(flag[y]==0)
         {
            sum--;
            flag[y]=1;
            dfs(e[tmp].y);
         }         
         tmp=e[tmp].next;
     }
}

int main()
{
    int i,j,x,y,tmp;
    
    while(EOF!=scanf("%d %d",&n,&m))
    {
                         
        for(i=1;i<=n;i++)
           first[i]=-1;
           
        tot=0;
        
        while(m--)
        {
           scanf("%d %d",&x,&y);
           add(y,x);
        }    
        
        sum=n*(n-1)/2;           
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
               flag[j]=0; 
            dfs(i);
        }
  
        printf("%d\n",sum);

                 
    }
    return 0;
}
