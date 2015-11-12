#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=110000;
int x[maxn],y[maxn],h[maxn];
long long p[2*maxn],cnt[2*maxn];
int n,top,tot,temp;
struct node
{
   int ls,rs,beg,end,c;
};
node tree[2*maxn];
int init(int a,int b)
{
   int cur=tot,mid;
   tree[cur].beg=a;
   tree[cur].end=b;
   tree[cur].c=0;
   if(b-a==1)
   {
	  tree[cur].ls=-1;
	  tree[cur].rs=-1;
	  return cur;
   }
   mid=(a+b)/2;
   ++tot;
   tree[cur].ls=init(a,mid);
   ++tot;
   tree[cur].rs=init(mid,b);
   return cur;
}
void insert(int cur,int x,int y,int v)//更新一个区间
{
  int l,r;
  if(cur==-1)
    return ;
  l=tree[cur].beg;r=tree[cur].end;
  if(!(x<=r&&l<=y))
     return ;
  if(tree[cur].c>=v)
     return ;
  if(tree[cur].c>=0&&x<=l&&r<=y)//避免当前节点值为-1
  {
	tree[cur].c=v;
	return ;
  }
  if(tree[cur].c!=-1)
  {
     tree[tree[cur].ls].c=tree[tree[cur].rs].c=tree[cur].c;
     tree[cur].c=-1;
  }
  insert(tree[cur].ls,x,y,v);
  insert(tree[cur].rs,x,y,v);
  if(tree[tree[cur].ls].c!=-1&&tree[tree[cur].ls].c==tree[tree[cur].rs].c)
	  tree[cur].c=tree[tree[cur].ls].c;
}
long long find(int cur,int x,int y)
{
  int l,r,mid;
  l=tree[cur].beg;r=tree[cur].end;
  mid=(l+r)/2;
  if(l<=x&&y<=r&&tree[cur].c!=-1)//
    return (tree[cur].c);
  if(y<=mid)
    return find(tree[cur].ls,x,y);
  else 
    return find(tree[cur].rs,x,y);
}
int main()
{
  int i,j,k;
  long long sum;
  while(EOF!=scanf("%d",&n))
  {
	top=0;
	for(i=1;i<=n;++i)
	{
	   scanf("%d %d %d",&x[i],&y[i],&h[i]);
	   cnt[++top]=x[i];
	   cnt[++top]=y[i];
	}
	++top;//top为尾端。。。。
	sort(cnt+1,cnt+top); 
	temp=0;p[0]=cnt[1];
	for(i=2;i<top;++i)
	{
	   if(cnt[i]!=cnt[i-1])
           p[++temp]=cnt[i];   
	}
	tot=0;
	memset(tree,-1,sizeof(tree));
	init(0,temp);//建树。。。。
	for(i=1;i<=n;++i)   
	{
	  j=upper_bound(p,p+temp+1,x[i])-p-1;
	  k=upper_bound(p,p+temp+1,y[i])-p-1;
      insert(0,j,k,h[i]);
	}
    sum=0;
    for(i=0;i<temp;++i)
       sum+=(p[i+1]-p[i])*find(0,i,i+1);
	printf("%I64d\n",sum);
  }
  return 0;
}

