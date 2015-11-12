#include<stdio.h>
#include<string.h>
int p[110],first[1100];
int m,n,size,tot,P;
int C,S,T;
__int64 h[110][110];

struct node
{
	int x,y,c,next;
};

node e[90000];

struct Q
{
	int state;
	int res;
	__int64 cost;   ///
};
Q heap[9000000],tmp;  //>100*1000

void add(int x,int y,int c)
{
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].c=c;
	e[tot].next=first[x];
	first[x]=tot;
}

void insert(Q s) 
{
	int i;
	Q tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2].cost>heap[i].cost)
	{
		tmp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=tmp;
		i=i/2;
	}
}

struct Q del()
{
	int i,l,r,min;
	Q tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		min=i;
		if(l<=size&&heap[l].cost<heap[i].cost) //取出较小元素置为根。。。
			min=l;
		if(r<=size&&heap[r].cost<heap[min].cost)
			min=r;
		if(min!=i)
		{
			vx=heap[i];
			heap[i]=heap[min];
			heap[min]=vx;
			i=min;
		}
		else
			break;
	}
    return tmp;
}

void bfs()
{
	 
	 int i,j,x,y,nb,len,res;
	 __int64 cost;
	 Q vx;
	 if(S==T)
	 {
		 printf("0\n");
		 return ;
	 }
	 size=0;
	 tmp.cost=0;
	 tmp.res=0;
	 tmp.state=S;
	 for(i=1;i<=n;i++)
		 for(j=0;j<=C;j++)
			 h[i][j]=-1;
	 h[S][0]=0;
	 insert(tmp);
	 while(size)
	 {
		 tmp=del();
		 if(tmp.state==T)
		 {
			 printf("%I64d\n",tmp.cost);
			 return ;
		 }
		 x=tmp.state;
		 res=tmp.res;
		 cost=tmp.cost;
		 if(tmp.cost>h[x][res])                               
		      continue;
		 for(i=1;i+res<=C;i++)
		 {
             vx.state=x;
			 vx.cost=cost+i*p[x];
			 vx.res=res+i;
			 if(h[vx.state][vx.res]==-1||vx.cost<h[vx.state][vx.res])
			 {
				 h[vx.state][vx.res]=vx.cost;
				 insert(vx);
			 }
		 }
		 nb=first[x];
		 while(nb!=-1)
		 {
			 y=e[nb].y;
			 len=e[nb].c;
			 if(res>=len)
			 {
				 vx.state=y;
				 vx.res=res-len;
				 vx.cost=cost;
				 if(h[vx.state][vx.res]==-1||vx.cost<h[vx.state][vx.res])
				 {
					 h[vx.state][vx.res]=vx.cost;
					 insert(vx);
				 }
			 }
			 nb=e[nb].next;
		 }
	 }	
	 printf("impossible\n");
}

int main()
{
	int i,x,y,c;
    while(EOF!=scanf("%d %d",&n,&m))
	{
         for(i=1;i<=n;i++)
		 {
			 scanf("%d",&p[i]);
			 first[i]=-1;
		 }
		 tot=0;
		 while(m--)
		 {
			 scanf("%d %d %d",&x,&y,&c);  ////重边 
			 add(x+1,y+1,c);
			 add(y+1,x+1,c);
		 }
		 scanf("%d",&P);
		 while(P--)
		 {
             scanf("%d %d %d",&C,&S,&T);
			 S++;
			 T++;
			 bfs();
		 }
	}
	return 0;
}

