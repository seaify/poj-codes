#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=100100;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int m,n,tot,td,N;
int a[maxn],c[maxn],w[maxn],d[2*maxn],T[maxn],beg[maxn],end[maxn],first[maxn],visit[2*maxn];
int edge[maxn][3],q[maxn][20],id[maxn][20];

struct node
{
     int x,y,v,next;
};
node e[2*maxn];

void insert(int x,int y,int v)
{
    ++tot;
    e[tot].x=x;
    e[tot].y=y;
    e[tot].v=v;
    e[tot].next=first[x];
    first[x]=tot;
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

int RMQ(int x,int y)
{
    int k;
    if(x>y)
       swap(x,y);
    k=int(log((y-x+1)*1.0)/log(2.0));
    if(q[x][k]<q[y-(1<<k)+1][k])
	   return id[x][k];
	return id[y-(1<<k)+1][k];
}

int dfs(int x,int p,int depth,int v)
{
    int y,hh,tmp=first[x];
    d[x]=depth;
	w[x]=v;
    visit[++tot]=x;
    T[x]=tot;
    beg[x]=++td;
    end[x]=beg[x];
    while(tmp!=-1)
    {
        y=e[tmp].y;
        if(y==p)
		{
		   tmp=e[tmp].next;
           continue;
		}
		hh=dfs(y,x,depth+1,v+e[tmp].v);
        end[x]=max(end[x],hh);
        visit[++tot]=x;
        tmp=e[tmp].next;
    }
    return end[x];
}

int index(int i)
{
     return i&(-i);
}

void add(int x,int v)
{
     while(x<=n)
     {
          c[x]+=v;
          x+=index(x);
     }
}
 
int sum(int x)
{
    int result=0;
    while(x>0)
    {
          result+=c[x];
          x-=index(x);
    }
    return result;
}

void debug1()
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\n",sum(beg[i]));
}

void debug()
{
    int i;

	printf("\n");
    for(i=1;i<=n;i++)
        printf("%d %d %d\n",T[i],beg[i],end[i]);
    
    printf("\n");
    
  /*  for(i=1;i<=tot;i++)
        printf("%d ",visit[i]);
    printf("\n\n");*/

	for(i=1;i<=n;i++)
		printf("%d %d\n",w[i],sum(beg[i]));

	for(i=1;i<=n;i++)
		printf("%d\n",sum(beg[i]));
    
}

int main()
{
    int i,x,y,v,op,s,t,result;
    
    while(EOF!=scanf("%d %d %d",&n,&m,&s))
    {
         for(i=1;i<=n;i++)
             first[i]=-1,c[i]=0;
         tot=0;
         for(i=1;i<n;i++)
         {
             scanf("%d %d %d",&x,&y,&v);
             edge[i][0]=x,edge[i][1]=y,edge[i][2]=v;
             insert(x,y,v);
             insert(y,x,v);
         } 
         
         td=0,tot=0;
       
         dfs(1,-1,0,0);
     
         for(i=1;i<=tot;i++)
              a[i]=d[visit[i]];
         N=2*n;
		 a[N]=N;

		 init();

      //   debug();
		 //构造c数组

	//	 for ,需要多构造1点，c[x]+=v,c[y]+=-v;
		 w[0]=0;
		 for(i=1;i<=n;i++)
		 {
		//	 printf("%d\n",w[i]-w[i-1]);
			 add(i,w[beg[i]]-w[beg[i-1]]);
		//	 t+=w[i];
		 }

	//	 debug();

	//	 debug1();

		 
         
         while(m--)
         { 
         
             scanf("%d",&op);
             if(op==0)
             {
                 scanf("%d",&t);
                 result=sum(beg[s])+sum(beg[t]);
                 result-=2*sum(beg[visit[RMQ(T[s],T[t])]]);
                 printf("%d\n",result); 
                 s=t; 
             }
             else
             {
                 scanf("%d %d",&i,&v);  ///保留dfs序中处于第x条边下面的.. 
                 x=edge[i][0],y=edge[i][1],v-=edge[i][2];
				 
                 if(d[x]<d[y])
                       swap(x,y);

				

                 add(beg[x],v);
                 add(end[x]+1,-v);

			//	 debug1();
                 
             }
                   
         }
    }
    
    return 0;
}
