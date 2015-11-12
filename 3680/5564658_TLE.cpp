#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int INF=100000000;
int x[500],y[500],w[500],first[500],d[500],path[50000],ID[11000];
int N,M,n,tot,cost;
bool flag[110000];
stack < int > q;

struct node
{
	int x,y,b,c,f,next;
};
node e[50000];

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
	q.push(0);
	while(!q.empty())
	{
		x=q.top();
		q.pop();
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
					q.push(y);
				}
			}
			else if(e[temp].f>0&&e[temp].c==0&&d[x]+dis<d[y]) ////逆流
			{
				d[y]=d[x]+dis;
				path[y]=temp;
				if(!flag[y])
				{
					flag[y]=true;
					q.push(y);
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
    int i,T,K,top;
  	scanf("%d",&T);
	while(T--)
	{
	    scanf("%d %d",&N,&K);
		for(i=1;i<=100000;++i)
			flag[i]=false;
		for(i=1;i<=N;++i)
		{
			scanf("%d %d %d",&x[i],&y[i],&w[i]);
			flag[x[i]]=true;
			flag[y[i]]=true;
        } 
		top=0;
		for(i=1;i<=100000;++i)
			if(flag[i])
			{
			    ID[i]=++top;
			}               ////构图
		n=top+1;
	    for(i=0;i<=n;i++)
			first[i]=-1;
		for(i=0;i<=top;++i)
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


