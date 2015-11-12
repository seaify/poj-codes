#include<iostream>

const int INF=20000;

int first[11000],sum[11000],f[11000][3];
int n,tot,ans;

struct node
{
    int x,y,next;
};
node e[21000];

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

void add(int x,int y)
{
    e[++tot].x=x;
    e[tot].y=y;
    e[tot].next=first[x];
    first[x]=tot;
}

void dfs(int x,int father)
{
    int tmp,y,less=INF,flag=1;
    tmp=first[x];
    
    f[x][0]=1;
    f[x][1]=INF;
    f[x][2]=0;
    
    while(tmp!=-1)
    {
         y=e[tmp].y;
         if(y!=father)
         {
             dfs(y,x);
             flag=0;
             f[x][0]+=min(min(f[y][0],f[y][1]),f[y][2]);
             f[x][2]+=min(f[y][0],f[y][1]);
             if(f[y][0]-min(f[y][0],f[y][1])<less)
                  less=f[y][0]-min(f[y][0],f[y][1]);
         }
            
         tmp=e[tmp].next;
    }
    
    if(flag==0)
         f[x][1]=f[x][2]+less;
   
}

int main()
{
    int i,x,y;
    while(EOF!=scanf("%d",&n))
    {
		 for(i=1;i<=n;i++)
			 first[i]=-1;
		 tot=0;
         for(i=0;i<n-1;i++)
         {
              scanf("%d %d",&x,&y);
              add(x,y);
              add(y,x);
         }
         dfs(1,-1);
         if(f[1][0]<f[1][1])
              printf("%d\n",f[1][0]);
         else
              printf("%d\n",f[1][1]); 
         
    }
    return 0;
}
