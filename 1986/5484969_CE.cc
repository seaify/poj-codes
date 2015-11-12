#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110000;
int p[maxn],num[maxn],in[maxn],c[maxn],ans[maxn],father[maxn];
int n,m,k,root;
bool flag[maxn],last;

struct node
{
	int y,T;
};
node v;
vector < node > e[maxn],q[maxn];

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

void LCA(int x,int dis)
{
	int i,y,v,mid,T;
	Makeset(x);
	father[Find(x)]=x;
	in[x]=dis;    
	flag[x]=false;
	for(i=0;i<e[x].size();++i)
	 if(flag[e[x][i].y])
	 {
		y=e[x][i].y;
		v=e[x][i].T;
		LCA(y,dis+v);
		Union(x,y);
		father[Find(x)]=x;
	 }
	c[x]=1;
	for(i=0;i<q[x].size();++i)
	     if(c[q[x][i].y])
		 {
			 mid=father[Find(q[x][i].y)];
			 T=q[x][i].T;
			 y=q[x][i].y;
			 ans[T]=in[x]+in[y]-2*in[mid];
		 }
}

int main()
 {   
     int i,x,y,value;
	 char ch;
	// freopen("dquery.8.in","r",stdin);
	 //freopen("1.out","w",stdout);
	 while(EOF!=scanf("%d %d",&n,&m))
	 {
		 for(i=1;i<=n;++i)
		 {
			 e[i].clear();
			 q[i].clear();    ////查询....
			 flag[i]=true;
		 }          ///先对多棵树求出根结点和距离。。。
		 while(m--)
		 {
			 scanf("%d %d %d %c",&x,&y,&value,&ch);
			 v.y=y;v.T=value;
			 e[x].push_back(v);
			 v.y=x;
			 e[y].push_back(v);
		 }
		 scanf("%d",&m);
		 for(i=1;i<=m;++i)
		 {
			 scanf("%d %d",&x,&y);
			 v.y=y;v.T=i;
			 q[x].push_back(v);
			 v.y=x;
			 q[y].push_back(v);
		 }
		 memset(c,0,sizeof(c));
		 for(i=1;i<=n;++i)
			 if(flag[i])   ///   可能存在多棵树。。。分别做1次。。。
			 { 
                LCA(i,0);
			 }
		for(i=1;i<=m;++i)
			printf("%d\n",ans[i]);
	 }     
     return 0;
 }     

