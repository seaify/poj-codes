#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const int maxn=11000;
const double eps=1e-12;
int p[maxn],num[maxn];
int N,M,sum,m;
double total,x[maxn],y[maxn];
struct node
{
	int x,y;
	double v;
};
node edge[1100000];
int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     if(aa->v+eps<bb->v)
		 return 0;
	 return 1;
}
void Makeset(int x)
 {
     p[x]=-1;
     num[x]=1;
 } 
int Find(int x)//非递归压缩路径
 {
     int r=x;
     while(p[r]!=-1)//找到根结点
         r=p[r];
     while(x!=r)
      {
          int q=p[x];
          p[x]=r;
          x=q;
      }
    return r;      
 }     
int Union(int a,int b)
{

    int t1,t2;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
		  return 0;
	--sum;
    if(num[t2]<=num[t1])
    {
        p[t2]=t1;
        num[t1]+=num[t2];
    }
    else
    {
        p[t1]=t2;
        num[t2]+=num[t1];
    }
    return 0;
}
int main()
 {   
     int i,j;
     while(EOF!=scanf("%d %d",&N,&M))
	 {
		 for(i=1;i<=N;++i)
		 {
			 scanf("%lf %lf",&x[i],&y[i]);
			 Makeset(i);
		 }
		 sum=N;
		 while(M--)
		 {
			 scanf("%d %d",&i,&j);
			 Union(i,j);
		 }
		 if(sum==1)
		 {
			 printf("0.00\n");
			 continue;
		 }
		 m=0;
		 for(i=1;i<N;++i)
			 for(j=i+1;j<=N;++j)
			 {
				 edge[++m].x=i;
				 edge[m].y=j;
				 edge[m].v=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			 }
		 qsort(edge+1,m,sizeof(edge[1]),cmp);
         total=0.0;
		 for(i=1;i<=m&&sum>1;++i)
		 {
             if(Find(edge[i].x)!=Find(edge[i].y))
			 {
				 Union(edge[i].x,edge[i].y);
				 total+=edge[i].v;
			 }
		 }
		 printf("%.2lf\n",total);
	 }
     return 0;
 }     

