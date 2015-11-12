#include<stdio.h>

const int maxn=200100;

int m,n,tot,sum;
int a[maxn],b[maxn],c[maxn],d[maxn];
int flag[maxn],father[maxn];

struct node
{
    int x,y,next;
};
node e[maxn],tree[maxn];

void add(node *e,int *q,int x,int y)
{
    ++tot;
    e[tot].x=x;
    e[tot].y=y;
    e[tot].next=q[x];
    q[x]=tot;
}

int find(int x)
{
    int r=x,p;
    
    while(father[r]!=-1)
        r=father[r];
    
    while(x!=r)
    {
        p=father[x];
        father[x]=r;
        x=p;
    }
    
    return r;
}

void Union(int x,int y)
{
     int t1,t2;
     t1=find(x);
     t2=find(y);
     if(t1==t2)
         return ;
     father[t2]=t1;
}

int dfs(int p,int x)
{
     int y,tmp;
     c[x]=d[x];
     tmp=a[x];
     while(tmp!=-1)
     {
          y=tree[tmp].y;
          if(y!=p)
             c[x]+=dfs(x,y);
          tmp=tree[tmp].next;
     }
     if(c[x]==0)
	 {
        if(x!=1)
          sum+=m;
	 }
     else if(c[x]==1)
          sum+=1;
     return c[x];
}

void LCA(int p,int x)
{
    int tmp,root,y;
    flag[x]=++tot;
    tmp=a[x];
    while(tmp!=-1)
    {
         if(tree[tmp].y!=p)
         {
             LCA(x,tree[tmp].y);
             Union(x,tree[tmp].y);
         }
         tmp=tree[tmp].next;
    }
    tmp=b[x];
    while(tmp!=-1)
    {
         y=e[tmp].y;
         if(flag[y]>0&&flag[y]<flag[x])
         {
              root=find(y);
			//  printf("%d %d root:%d\n",x,y,root);
              d[x]++;
              d[y]++;
              d[root]-=2;
         }
         tmp=e[tmp].next;
    }
}

int main()
{
    int i,x,y;
    while(EOF!=scanf("%d %d",&n,&m))
    {
          tot=0;
          for(i=1;i<=n;i++)
              a[i]=b[i]=-1,c[i]=0,d[i]=0,flag[i]=0,father[i]=-1;
          for(i=1;i<n;i++)
          {
              scanf("%d %d",&x,&y);
              add(tree,a,x,y);
              add(tree,a,y,x); 
          }
          tot=0;
          for(i=1;i<=m;i++)
          {
              scanf("%d %d",&x,&y);
              add(e,b,x,y);
              add(e,b,y,x);
          }
          sum=0;
          LCA(-1,1);
		  tot=0;
		  for(i=1;i<=n;i++)
			  printf("%d ",d[i]);
		  printf("\n");
          dfs(-1,1);
          printf("%d\n",sum);
    }
    return 0; 
}
