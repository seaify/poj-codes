#include<cstdio>
#include<cmath>
#include<cstdlib>
const double eps=1e-6;
const double INF=1000000000;
int x[1100],y[1100],h[1100],c[1100];
int N;
double T,left,right,mid,d[1100],map[1100][1100];
bool flag[1100];

int prim()
{
	int i,j,k;
	double minv,v,cost,len;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			v=sqrt(double((x[i]-x[j])*(x[i]-x[j]))+double((y[i]-y[j])*(y[i]-y[j])));
			map[i][j]=abs(h[i]-h[j])-mid*v;
		}
	for(i=1;i<=N;i++)
		d[i]=INF,flag[i]=true,c[i]=-1; ///c[i]表示在最小生成树中的前驱... 
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
			if(flag[j]&&map[k][j]<d[j])
				d[j]=map[k][j],c[j]=k;
	}
	//printf("%.3lf\n",cost);
	if(cost>=eps)
	     return 0;
	v=0;
	for(i=2;i<=N;i++)
	     v+=abs(h[c[i]]-h[i]);
//	printf("%.3lf\n",v);
	T=(v*mid)/(v-cost);   ////v不可能等于cost。。。	 
	if(fabs(T-mid)>eps)
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
		mid=10000000;
		while(1)
		{
			if(prim())
			{
				
			    mid=T;
			  //  printf("%.3lf\n",mid);
			}
			else
			    break;
		}
		printf("%.3lf\n",mid);
	}
	return 0;
}
