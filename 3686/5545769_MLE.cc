#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int INF=1000000000;
stack < int > q;
int N,M,T,n,minc;
int p[60][60],b[4000][4000],c[4000][4000],f[4000][4000],d[4000],path[4000];
bool flag[4000];

int find_way()
{
	int i,x,y;
    for(i=0;i<n;++i)  
		d[i]=INF,path[i]=-1;
	d[0]=0;
	q.push(0);
	memset(flag,true,sizeof(flag));
	flag[0]=false;
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		flag[x]=true;  ///出队列.....
		if(x==0)
		{
			for(y=1;y<=N;++y)
				if(((c[x][y]>0&&f[x][y]<c[x][y])||(f[x][y]>0&&c[x][y]>0))&&d[x]+b[x][y]<d[y])
				{
					d[y]=d[x]+b[x][y];
					if(flag[y])
					{
						flag[y]=false;  ////表示已经进入队列....
						path[y]=x;  ////最短路的前驱...
						q.push(y);
					}
				}
		}
		else if(x<=N)
		{
			for(y=N+1;y<n-1;++y)
				if(((c[x][y]>0&&f[x][y]<c[x][y])||(f[x][y]>0&&c[x][y]>0))&&d[x]+b[x][y]<d[y])
				{
					d[y]=d[x]+b[x][y];
					if(flag[y])
					{
						flag[y]=false;
						path[y]=x;
						q.push(y);
					}
				}
		}
		else
		{
			if(d[x]+b[x][n-1]<d[n-1])
			{
				d[n-1]=d[x]+b[x][n-1];
				path[n-1]=x;
			}
		}
	}
	if(d[n-1]==INF)
	      return 0;
	return 1;
}

void track_back()
{
	int minv=INF,i,load=0;
    for(i=n-1;i!=-1;i=path[i])
		if(c[path[i]][i]>0&&c[path[i]][i]<f[path[i]][i])  ///正向边...
		{
			load+=b[path[i]][i];
			if(c[path[i]][i]-f[path[i]][i]<minv)
				minv=c[path[i]][i]-f[path[i]][i];
		}
		else if(c[path[i]][i]>0&&f[path[i]][i]>0)
		{
			load-=b[path[i]][i];
			if(f[path[i]][i]<minv)
				minv=f[path[i]][i];
		}
   for(i=n-1;i!=-1;i=path[i])
	   	if(c[path[i]][i]>0&&c[path[i]][i]<f[path[i]][i])
		{
	       f[path[i]][i]+=minv;
		   f[i][path[i]]-=minv;
		}
		else if(c[path[i]][i]>0&&f[path[i]][i]>0)
		{
			f[i][path[i]]+=minv;
			f[path[i]][i]-=minv;
		}
        minc+=minv*load;
}

void solve()
{
    minc=0;
	while(find_way())
		track_back();
	printf("%.3lf\n",double(minc)/double(N));
}


int main()
{
	int i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
				scanf("%d",&p[i][j]);
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for(i=1;i<=N;++i)         
			for(j=1;j<=M;++j)
				for(k=1;k<=N;++k)     ////指的是倒数第k个任务....
				{
                     b[i][j*N+k]=k*p[i][j];   //费用
					 c[i][j*N+k]=1;
				}
		for(i=1;i<=N;++i)
		{
	        b[0][i]=0;
			c[0][i]=1;
		}
		n=(M+1)*N+2;     ///总共的点数...
		for(i=N+1;i<n-1;++i)
		{
			b[i][n-1]=0;
			c[i][n-1]=INF;
		}      ///构图完成，s=0,t=n-1,总共点数为n
		solve();
	}
	return 0;
}