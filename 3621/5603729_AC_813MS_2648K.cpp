#include<cstdio>
const double eps=1e-6;
const double INF=1000000000;
int n,m,tot;
int v[1100],first[1100],c[1100],q[90000000];
double left,mid,right,d[1100];
bool flag[1100];

struct node
{
	int x,y,cost,next;
};
node e[5100];

void add(int x,int y,int cost)
{
     e[++tot].x=x;
	 e[tot].y=y;
	 e[tot].cost=cost;
	 e[tot].next=first[x];
	 first[x]=tot;
}

int SPFA()
{
	int i,beg,end,x,y,tmp;
    for(i=1;i<=n;i++)
		d[i]=INF,c[i]=0,flag[i]=true;
	d[1]=0;
	c[1]=1;
	q[1]=1;
	end=1;
	flag[1]=false;  ///进入队列...
	for(beg=1;beg<=end;beg++)
	{
		x=q[beg];
		tmp=first[x];
		flag[x]=true;
		while(tmp!=-1)
		{
            y=e[tmp].y;
			if(d[x]+mid*e[tmp].cost-v[y]<d[y])
			{
				d[y]=d[x]+mid*e[tmp].cost-v[y];
				if(flag[y])
				{
					q[++end]=y;
					c[y]++;
					flag[y]=false;
					if(c[y]>=n)
						return 1;
				}
			}
			tmp=e[tmp].next;
		}
	}
	return 0;
}

int main()
{
	int i,x,y,cost;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		left=0;
		right=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			first[i]=-1;
			right+=v[i];
		}
		tot=-1;
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&cost);
			add(x,y,cost);
		}
		while(left+eps<=right)
		{
			mid=(left+right)/2;
			if(SPFA())
				left=mid;
			else
				right=mid;
		}
		printf("%.2lf\n",left);
	}
	return 0;
}
