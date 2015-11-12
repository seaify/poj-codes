#include<cstdio>
#include<cmath>
const double eps=1e-6;
const double INF=100000000000;
int x[1100],y[1100],h[1100];
int N;
double left,right,mid,d[1100],map[1100][1100];
bool flag[1100];

int prim()
{
	int i,j,k;
	double minv,v,cost;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			v=sqrt(double((x[i]-x[j])*(x[i]-x[j]))+double((y[i]-y[j])*(y[i]-y[j])));
			map[i][j]=abs(h[i]-h[j])-mid*v;
		}
	for(i=1;i<=N;i++)
		d[i]=INF,flag[i]=true;
	d[1]=0;
	cost=0;
	for(i=1;i<=N;i++)
	{
		minv=INF;
		for(j=1;j<=N;j++)
			if(flag[j]&&d[j]<minv)
				minv=d[j],k=j;
		flag[k]=false;
		cost+=minv;
		for(j=1;j<=N;j++)
			if(flag[j]&&d[k]+map[k][j]<d[j])
				d[j]=d[k]+map[k][j];
	}
	if(cost>eps)
		return 1;
	return 0;
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&N))
	{
		if(N==0)
			break;
		for(i=1;i<=N;i++)
			scanf("%d %d %d",&x[i],&y[i],&h[i]);
		left=0;
		right=10000000;
		while(fabs(left-right)>eps)
		{
			mid=(left+right)/2.0;
			if(prim())
				left=mid;
			else
				right=mid;
		}
		printf("%.3lf\n",left);
	}
	return 0;
}