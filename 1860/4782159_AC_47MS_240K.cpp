#include<stdio.h>
const int maxn=110;
const double eps=1e-8;
int i,u,v,n,m,s;
double rate,less,dis[maxn];
struct Edge
{
 int dest;
 double less,rate;
 Edge *link;
};
Edge *edge=new Edge[maxn];
Edge *l;
int main()
{
 double sum,temp;bool flag;
 scanf("%d%d%d%lf",&n,&m,&s,&sum);
 for(i=1;i<=n;i++)
 {
	 edge[i].link=NULL;
	 dis[i]=0.0;
 }
 dis[s]=sum;
 while(m--)
 {
    scanf("%d%d",&u,&v);	
	scanf("%lf%lf",&rate,&less);
	l=new Edge;
	l->dest=v;
	l->rate=rate;
	l->less=less;
	l->link=edge[u].link;
	edge[u].link=l;
	scanf("%lf%lf",&rate,&less);
	l=new Edge;
	l->dest=u;
	l->rate=rate;
	l->less=less;
	l->link=edge[v].link;
	edge[v].link=l;
 }
 while(1)
 {
   flag=true;
   for(i=1;i<=n;i++)
   {
	 if(dis[i]>eps)
	 {
		l=edge[i].link;
		while(l)
		{
		  temp=(dis[i]-l->less)*l->rate;
		  if(temp>dis[l->dest]+eps)
		  {
			  dis[l->dest]=temp;
			  flag=false;
		  } 
		  l=l->link;
		}
	 }
   }
   if(flag)
	   break;
 }
 if(dis[s]>sum+eps)
	 printf("YES\n");
 else
	 printf("NO\n");
 return 0;
}