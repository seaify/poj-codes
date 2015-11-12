#include<cstdio>
#include<cstring>
const int INF=100000000;
int p[60][60],first[4000],d[4000],path[4000],q[900000];
int N,M,n,tot,cost;
bool flag[4000];

struct node
{
	int x,y,b,c,f,next;
};
node e[400000];

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
//	printf("%d\n",d[n]);
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
  //   printf("%d\n",minv);
	 cost+=d[n]*minv;
     //printf("%d\n",cost);

}

void solve()
{
	cost=0;
	while(SPFA())
		track_back();
	printf("%.6lf\n",double(cost)/double(N));
}

int main()
{
    int i,j,T,k;
  	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);   
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
				scanf("%d",&p[i][j]);

        n=(M+1)*N+1;
		for(i=0;i<=n;++i)   ///边表的入口...,n为源点...
             first[i]=-1;
        tot=-1;

		for(i=1;i<=N;++i)         
		   for(j=1;j<=M;++j)
		  	 for(k=1;k<=N;++k)   ////指的是倒数第k个任务....//费用
			 {                            
                
				  add(i,j*N+k,1,k*p[i][j]);
				  add(j*N+k,i,0,-k*p[i][j]);  ///逆边的费用为其负值...
			 }

	    for(i=1;i<=N;++i)
		{
			add(0,i,1,0);
			add(i,0,0,0);
		}

		for(i=N+1;i<n;++i)
		{
			add(i,n,1,0);
			add(n,i,0,0);
		}

		solve();
	
  }
  return 0;
}

