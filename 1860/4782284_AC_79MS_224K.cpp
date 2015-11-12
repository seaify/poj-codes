#include<stdio.h>
#include<string.h>
const int maxn=1000;
const double eps=1e-8;
int i,u,v,n,m,s,top;
double rate,less,dis[110];
struct node
{
 int x,y;
 double less,rate;
};
node a[maxn];
int main()
{
 double sum,temp;bool flag;
 scanf("%d%d%d%lf",&n,&m,&s,&sum);
 memset(dis,0,(n+1)*sizeof(double));
 dis[s]=sum;top=0;
 while(m--)
 {
    scanf("%d%d",&u,&v);	
	scanf("%lf%lf",&rate,&less);
	a[++top].x=u;
	a[top].y=v;
	a[top].less=less;
	a[top].rate=rate;
	scanf("%lf%lf",&rate,&less);
    a[++top].x=v;
	a[top].y=u;
	a[top].less=less;
	a[top].rate=rate;
 }
 while(1)
 {
   flag=true;
   for(i=1;i<=top;i++)
   {
	 temp=(dis[a[i].x]-a[i].less)*a[i].rate;
	 if(temp>dis[a[i].y]+eps)
	 {
		 dis[a[i].y]=temp;
		 flag=false;
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