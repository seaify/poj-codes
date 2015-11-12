#include<cstdio>
const __int64 INF=900000000000;
int beg[1100000],end[1100000],flag[1100000],n,m,T,tot; ///
struct node
{
	int x,y,next;
	__int64 cost;
};
node e[1100000],f[1100000];
int q[90000000];
__int64 d[1100000],sum;

void add(int x,int y,__int64 cost)
{
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].cost=cost;
	e[tot].next=beg[x];
	beg[x]=tot;

	f[tot].x=y;
	f[tot].y=x;
	f[tot].cost=cost;
	f[tot].next=end[y];
	end[y]=tot;

}

void SPFA(node *e,int *first)
{
	 int i,x,y,beg,end,tmp;
     for(i=0;i<n;++i)
		 d[i]=INF,flag[i]=0;
	 d[0]=0;
	 flag[0]=1;  ////进入队列的置为1
	 q[1]=0;
	 beg=1;
	 end=1;
	 for(;beg<=end;beg++)
	 {
         x=q[beg];
		 flag[x]=0;  //////出队列	 
		 tmp=first[x];
		 while(tmp!=-1)
		 {
			 y=e[tmp].y;
			 if(d[x]+e[tmp].cost<d[y])
			 {
				 d[y]=d[x]+e[tmp].cost;
				 if(!flag[y])
				 {
					 q[++end]=y;
					 flag[y]=1;
				 }
			 }
			 tmp=e[tmp].next;
		 }
	 }
	 for(i=1;i<n;++i)
		 sum+=d[i];
}

int main()
{
	int x,y,i;
	__int64 cost;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;++i)
			beg[i]=-1,end[i]=-1;
		tot=-1;
		while(m--)
		{
			scanf("%d %d %I64d",&x,&y,&cost);
			add(x-1,y-1,cost);
		}
		sum=0;
		SPFA(e,beg);
		SPFA(f,end);
		printf("%I64d\n",sum);
	}
	return 0;
}
