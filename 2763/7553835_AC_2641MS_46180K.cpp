#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=100100;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int m,n,tot,sum,N;
int a[2*maxn],visit[2*maxn],size[maxn],next[maxn],heavy[maxn];
int fat[maxn],d[maxn],T[maxn],first[maxn];
int pre[maxn][3],edge[maxn][3],q[2*maxn][20],id[2*maxn][20];

struct node
{
     int x,y,v,next;
};
node e[2*maxn];

struct Node
{
     int a,b,ls,rs,sum;
};
Node tree[2*maxn];

void insert(int x,int y,int v)
{
    ++tot;
    e[tot].x=x;
    e[tot].y=y;
    e[tot].v=v;
    e[tot].next=first[x];
    first[x]=tot;
}

int RMQ(int x,int y)
{
    int k;
    x=T[x],y=T[y]; 
    if(x>y)
       swap(x,y);
    k=int(log((y-x+1)*1.0)/log(2.0));
    if(q[x][k]<q[y-(1<<k)+1][k])
	   return visit[id[x][k]];
	return visit[id[y-(1<<k)+1][k]];
}

void init()
{
    int i,j;
    for(i=1;i<=N;i++)
        q[i][0]=a[i],id[i][0]=i;
    for(j=1;(1<<j)<=N;j++)
       for(i=1;i+(1<<j)-1<=N;i++)
	   {
           q[i][j]=min(q[i][j-1],q[i+(1<<(j-1))][j-1]);
		   if(q[i][j]==q[i][j-1])
			   id[i][j]=id[i][j-1];
		   else
			   id[i][j]=id[i+(1<<(j-1))][j-1];
	   }         
}

int dfs(int x,int p,int depth,int v)
{
    int y,hh,son=0,tmp=first[x];
	heavy[x]=0;
    size[x]=1; 
    d[x]=depth;
    visit[++tot]=x;
    T[x]=tot;
    pre[x][0]=p,pre[x][1]=v;
    while(tmp!=-1)
    {
        y=e[tmp].y;
        if(y==p)
		{
		   tmp=e[tmp].next;
           continue;
		}
		hh=dfs(y,x,depth+1,e[tmp].v);
		if(hh>son)
            son=hh,heavy[x]=y; 
		size[x]+=hh;
        visit[++tot]=x;
        tmp=e[tmp].next;
    }
    return size[x];
}

void DFS(int x,int p,int tag)
{
    int tmp=first[x],y;
    ++tot;
    pre[x][2]=tot; 
    if(tag)
          fat[x]=fat[p];
    else
          fat[x]=x;
	if(size[x]<=1) ///叶子返回.
         return ;
    DFS(heavy[x],x,1);
    while(tmp!=-1)
    {
          y=e[tmp].y;
          if(y==p||y==heavy[x])
          {
               tmp=e[tmp].next;
               continue;
          }
          DFS(y,x,0);
          tmp=e[tmp].next;
    }
}

int make_tree(int a,int b)
{
    int cur=tot,mid;
    tree[cur].a=a;
    tree[cur].b=b;
    tree[cur].sum=0;
    if(a==b)
    {
        tree[cur].ls=tree[cur].rs=-1;
        return cur;
    }
    mid=(a+b)/2;
    ++tot;
    tree[cur].ls=make_tree(a,mid);
    ++tot;
    tree[cur].rs=make_tree(mid+1,b);
    return cur;
} 

void update(int x,int c,int v)
{
    int mid,ls,rs;
    if(tree[x].a==tree[x].b)
    {
          tree[x].sum=v;
          return ;
    }
    mid=(tree[x].a+tree[x].b)/2;
    ls=tree[x].ls;
    rs=tree[x].rs;
    if(c<=mid)
         update(ls,c,v);
    else
         update(rs,c,v);
    tree[x].sum=tree[ls].sum+tree[rs].sum;
}

void solve(int c,int x,int y) //  solve会不断在sum上累加需注意赋予初值..
{
    int a,b,ls,rs,mid;
    a=tree[c].a,b=tree[c].b;
    ls=tree[c].ls,rs=tree[c].rs;
    if(x<=a&&b<=y)        //注意相交问题.
    {
         sum+=tree[c].sum;
         return ;
    }
    mid=(a+b)/2;
    if(y<=mid)
         solve(ls,x,y);
    else if(x>mid)
         solve(rs,x,y);
    else
    {
         solve(ls,x,y); 
         solve(rs,x,y);
    }
    
}

int check(int x,int root)  
{
    int c,p;
    sum=0;
    while(d[x]>d[root])
    {
		p=pre[x][0];
        if(heavy[p]!=x)
        {
             sum+=pre[x][1];
             x=p;
             continue;
        }
        c=fat[x];
        if(d[c]>d[root])
        {
             solve(1,pre[c][2]+1,pre[p][2]+1);
             x=c;
        }
        else 
        {
             solve(1,pre[root][2]+1,pre[p][2]+1);
             x=root;
        }
    }
    return sum;
}

int main()
{
    int i,x,y,v,op,o,s,t,result;

    while(EOF!=scanf("%d %d %d",&n,&m,&s))
    {
         for(i=1;i<=n;i++)
             first[i]=-1;
         tot=0;
         for(i=1;i<n;i++)
         {
             scanf("%d %d %d",&x,&y,&v);
             edge[i][0]=x,edge[i][1]=y,edge[i][2]=v;
             insert(x,y,v);
             insert(y,x,v);
         } 
         tot=0;
         dfs(1,1,0,0);
         for(i=1;i<=tot;i++)
              a[i]=d[visit[i]];
     
         N=tot;
		 init();
		 tot=0;
		 DFS(1,1,0);
	                  
         tot=1;
         make_tree(1,n);
         for(i=2;i<=n;i++)
             update(1,pre[i][2],pre[i][1]);

         while(m--)
         { 
             scanf("%d",&op);
             if(op==0)
             {
                 scanf("%d",&t);
                 o=RMQ(s,t);
                 result=check(s,o)+check(t,o); 
                 printf("%d\n",result); 
                 s=t; 
             }
             else
             {
                 scanf("%d %d",&i,&v);  
                 x=edge[i][0],y=edge[i][1];	 				 
                 if(d[x]<d[y])
                       swap(x,y);
				 if(heavy[y]!=x) //轻边
                       pre[x][1]=v;
                 else
                       update(1,pre[y][2]+1,v);                              
             }                
         }
    }
    return 0;
}
