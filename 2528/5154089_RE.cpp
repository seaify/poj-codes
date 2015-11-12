#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=11000;
int x[maxn],y[maxn],p[2*maxn],cnt[2*maxn],flag[maxn];
int n,top,tot;
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
   if(a==b)
   {
	  tree[cur].ls=-1;
	  tree[cur].rs=-1;
	  return cur;
   }
   mid=(a+b)/2;
   ++tot;
   tree[cur].ls=init(a,mid);
   ++tot;
   tree[cur].rs=init(mid+1,b);
   return cur;
}
void insert(int c,int x,int y,int k)//更新一个区间
{
 int l,r;
 if(k==-1)
    return ;
 l=tree[k].beg;r=tree[k].end;
 if(!(x<=r&&l<=y))
     return ;
 if(x<=l&&r<=y)
 {
	tree[k].c=c;
	return ;
 }
  if(tree[k].c!=-1)
  {
     tree[tree[k].ls].c=tree[tree[k].rs].c=tree[k].c;
     tree[k].c=-1;
  }
  insert(c,x,y,tree[k].ls);
  insert(c,x,y,tree[k].rs);
  if(tree[tree[k].ls].c!=-1&&tree[tree[k].rs].c!=-1&&tree[tree[k].ls].c==tree[tree[k].rs].c)
	  tree[k].c=tree[tree[k].ls].c;
}
void sum(int x,int y,int k)
{
 int l,r,mid;
 l=tree[k].beg;r=tree[k].end;
 if(k==-1)
    return ;
// if(!(x<=r&&l<=y))可以确保区间一定相交。。。 
 //    return ;
 if(l<=x&&y<=r&&tree[k].c!=-1)//a[i].mark==true 表示其区间内颜色相同
 {
	flag[tree[k].c]=1;
    return ;
 }
 mid=(l+r)/2; 
 if(y<=mid)
    sum(x,y,tree[k].ls);
 else if(x>mid)
    sum(x,y,tree[k].rs);
 else 
 {
    sum(x,mid,tree[k].ls);
    sum(mid+1,y,tree[k].rs);
 }
}
int Bsearch(int v)
{
   int l,r,mid;
   l=1,r=top;
   while(l<=r)
   {
	  mid=(l+r)/2;
	  if(v==p[mid])
		  return mid;
	  else if(v<p[mid])
		  r=mid-1;
	  else
		  l=mid+1;
   }
   return 0;
}
int main()
{
  int i,j,k,T,temp,s;
  scanf("%d",&T);
  while(T--)
  {
	scanf("%d",&n);
	top=0;
	for(i=1;i<=n;++i)
	{
	   scanf("%d%d",&x[i],&y[i]);
	  // --x[i];
	   cnt[++top]=x[i];
	   cnt[++top]=y[i];
	}
	++top;//top为尾端。。。。
	sort(cnt+1,cnt+top); 
	temp=1;p[1]=cnt[1];
	for(i=2;i<top;++i)
	{
	   if(cnt[i]!=cnt[i-1])
	   {
		   if(cnt[i]!=cnt[i-1]+1)
		      p[++temp]=cnt[i-1]+1;
           p[++temp]=cnt[i];
       }
	}
	
	top=temp;tot=1;
	memset(tree,-1,sizeof(tree));
	init(1,top);//建树。。。。
	for(i=1;i<=n;++i)
	{
	   j=Bsearch(x[i]);
	   k=Bsearch(y[i]);
	   insert(i,j,k,1);
	}
	memset(flag,0,sizeof(flag));
	sum(1,top,1);
	s=0;
	for(i=1;i<=n;++i)
		  s+=flag[i];
	printf("%d\n",s);
  }
  return 0;
}

