#include<cstdio>
#include<cstring>
int T,L,op,C,S,ans[100],w[30];
int flag[4000000];
int size;

struct Q
{
	int state;
	int cost;
};
Q heap[5000000],tmp,vx;

struct node
{
	char a[21];
	int f,s,t;
	int cost;
};

node P[40];

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

int bfs()
{
	 int i;
	 if(S==T)
          return 0;
	 size=0;
	 tmp.cost=0;
	 tmp.state=S;
	 insert(tmp);
	 memset(flag,-1,2+sizeof(int)*(1<<L));
	 flag[S]=0;
	 while(size)
	 {
		 tmp=del();
		 if(tmp.state==T)
			 return tmp.cost;
		 for(i=1;i<=op;++i)
		 {
			 vx.state=((tmp.state^P[i].f)|P[i].s)&P[i].t;
			 vx.cost=tmp.cost+P[i].cost;
			 if(flag[vx.state]==-1||vx.cost<flag[vx.state])
			 {
				 flag[vx.state]=vx.cost;
				 insert(vx);
			 }
		 }
	 }
	 return -1;
}

int main()
{
	int i,j,Case;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d %d %d",&L,&op,&C);
		for(i=1;i<=op;++i)
		{
			scanf("%s %d",P[i].a,&P[i].cost);
			P[i].f=0;
			P[i].s=0;
			P[i].t=0x7ffffff;
			for(j=0;j<L;j++)
			{
				if(P[i].a[j]=='F')
					P[i].f+=(1<<(L-j-1));
				else if(P[i].a[j]=='S')
					P[i].s+=(1<<(L-j-1));
				else if(P[i].a[j]=='C')
					P[i].t-=(1<<(L-j-1));
			}
		}
		for(j=1;j<=C;j++)
		{
			scanf("%s %s",P[35].a,P[36].a);  //先求出状态..
			S=0; 
			for(i=0;i<L;i++)
				S+=(P[35].a[i]-'0')*(1<<(L-i-1));
			T=0; 
			for(i=0;i<L;i++)
				T+=(P[36].a[i]-'0')*(1<<(L-i-1));
		    ans[j]=bfs();
		}
		for(j=1;j<C;++j)
			if(ans[j]!=-1)
				printf("%d ",ans[j]);
			else
				printf("NP ");
		if(ans[C]!=-1)
			printf("%d\n",ans[C]);
		else
			printf("NP\n");
	}
	return 0;
}