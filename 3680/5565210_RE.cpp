#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int INF=100000000;
int x[500],y[500],w[500],first[500],d[500],path[500],q[900000],ID[500];
int N,M,n,tot,cost;
bool flag[110000];
set < int > num;

struct node
{
	int x,y,b,c,f,next;
};
node e[500000];

void add(int x,int y,int c,int b)
{
    ++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].c=c;
	e[tot].f=0;
	e[tot].b=b;
	e[tot].next=first[x];
	first[x]=tot;
}

int SPFA()
{
	int i,beg,end,y,temp,x,dis;
    for(i=0;i<=n;++i)
		d[i]=INF,path[i]=-1,flag[i]=false;  ///表示不在松弛队列中...
	d[0]=0;
	flag[0]=true;
	beg=1;
	end=1;
	q[1]=0;
	for(;beg<=end;++beg)
	{
		x=q[beg];
		flag[x]=false; //出队列
		temp=first[x];
		while(temp!=-1)
		{
			y=e[temp].y;
			dis=e[temp].b;
			if(e[temp].c>e[temp].f&&d[x]+dis<d[y]) ////正向流...
			{
				d[y]=d[x]+dis;
				path[y]=temp;   ///记录路径...
				if(!flag[y])
				{
					flag[y]=true;
					q[++end]=y;
				}
			}
			else if(e[temp].f>0&&e[temp].c==0&&d[x]+dis<d[y]) ////逆流
			{
				d[y]=d[x]+dis;
				path[y]=temp;
				if(!flag[y])
				{
					flag[y]=true;
					q[++end]=y;
				}
			}
			temp=e[temp].next;
		}
	}
	if(d[n]==INF)
         return 0;
	return 1;
}

void track_back()
{
     int i,T,minv=INF;
	 for(i=n;path[i]!=-1;)
	 {
		 T=path[i];
		 if(e[T].c>e[T].f)
		 {
			 if(e[T].c-e[T].f<minv)
			     minv=e[T].c-e[T].f;
		 }
		 else 
		 {
			 if(e[T].f<minv)
			     minv=e[T].f;
		 }
		 i=e[T].x;
	 }

	 for(i=n;path[i]!=-1;)
	 {
		 T=path[i];
		 if(e[T].c>e[T].f)
		 {
 			 e[T].f+=minv;
			 e[T^1].f=-e[T].f;
		 }
		 else 
		 {
             e[T].f-=minv;
			 e[T^1].f=-e[T].f;
		 }
		 i=e[T].x;
	 }
	 cost+=d[n]*minv;
}

void solve()
{
	cost=0;
	while(SPFA())
		track_back();
	printf("%d\n",-cost);
}

int main()
{
    int i,T,K,top,id;
  	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d %d",&N,&K);
	    num.clear();
		for(i=1;i<=N;++i)
		{
			scanf("%d %d %d",&x[i],&y[i],&w[i]);
			num.insert(x[i]);
			num.insert(y[i]);
		}
	    id=0;
	    for (set<int> ::iterator it = num.begin(); it != num.end(); ++it)
		{
		   ID[*it] = ++id;
		}
        n=id+1;
		tot=-1;
	    for(i=0;i<=n;i++)
			first[i]=-1;
		for(i=0;i<n;++i)
		{
			add(i,i+1,K,0);
			add(i+1,i,0,0);
		}
		for(i=1;i<=N;++i)
		{
			add(ID[x[i]],ID[y[i]],1,-w[i]);
			add(ID[y[i]],ID[x[i]],0,w[i]);
		}
        
		solve();
	
  }
  return 0;
}

