#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=500000;
int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int p[maxn],numx[maxn],numy[maxn],sum[maxn],ans[maxn];
int N,M,K,tot,sx,sy;
struct node
{
	int x,y,dx,dy,no;//dx,dy为偏移量。。,no为次序。。
};
node q[maxn],map[maxn];
int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return aa->dx-bb->dx;
}
void Makeset(int x)
{
     p[x]=-1;
     numx[x]=0;//其双亲与其的偏移值。。
	 numy[x]=0;
     sum[x]=1;//堆的大小
} 

int Find(int x)//非递归压缩路径
{
     int r=x,sx,sy;
     sx=0,sy=0;
     while(p[r]!=-1)//r为根结点
	 {
       sx=sx+numx[r];
	   sy=sy+numy[r];
	   r=p[r];
	 }
     while(x!=r)
     {
        int q=p[x];//q为x的父节点
        p[x]=r;
        numx[x]=sx;//更新num[x],使num[x]的性质得以满足，
		numy[x]=sy;
        sx=sx-numx[x];
		sy=sy-numy[x];
        if(sx==0)
           break;
        x=q;
     }
    return r;         
}  
   
void count(int r)
{
   sx=0,sy=0;
   while(p[r]!=-1)//r为根结点
   {
       sx=sx+numx[r];
	   sy=sy+numy[r];
	   r=p[r];
   }
}
int Union(int a,int b,int dx,int dy)
{
    int t1,t2;
    t1=Find(a);
    t2=Find(b);
	if(t1==t2)
		return 0;
    p[t2]=t1;
    sum[t1]+=sum[t2];//sum[x]表示该堆的个数
    numx[t2]=dx,numy[t2]=dy;
    return 0;
}
int main()
{
	int i,v,cnt,pos[10],x,y;
	char ch[2];
    pos['N']=0,pos['W']=1,pos['S']=2,pos['E']=3;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		for(i=1;i<=M;++i)
		{
           scanf("%d %d",&map[i].x,&map[i].y);
		   scanf("%d %s",&v,ch);
		   cnt=pos[ch[0]];
		   map[i].dx=v*d[cnt][0];
		   map[i].dy=v*d[cnt][1];
		}
		scanf("%d",&K);
		for(i=1;i<=K;++i)
		{
			scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].dx);//q[i].dx表示其序号。。
			q[i].no=i;
		}
		qsort(q+1,K,sizeof(q[1]),cmp);
		memset(ans,-1,sizeof(ans));
		for(i=1;i<=N;++i)
			Makeset(i);
		tot=1;
		for(i=1;i<=M&&tot<=K;++i)
		{
			Union(map[i].x,map[i].y,map[i].dx,map[i].dy);
			if(i==q[tot].dx)
			{
				if(Find(q[tot].x)==Find(q[tot].y))
				{
                    count(q[tot].y);
					x=sx,y=sy;
					count(q[tot].x);
					x-=sx,y-=sy;
					ans[q[tot].no]=abs(x)+abs(y);
				}
				++tot;
			}
		}
		for(i=1;i<=K;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}