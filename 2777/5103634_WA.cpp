#include<stdio.h>
#include<string.h>
const int maxn=100010;
int flag[40],tot;
struct node
{
 int low,high,left,right,count;
}a[4*maxn];
int init(int low,int high)//初始化
{
  int mid,cur;
  cur=tot;
  a[cur].low=low;
  a[cur].high=high;
  a[cur].count=1;
  mid=(low+high)/2;
  if(low==high)
  {
     a[cur].left=-1;
     a[cur].right=-1;
     return cur;
  }
  ++tot;
  a[cur].left=init(low,mid);
  ++tot;
  a[cur].right=init(mid+1,high);
  return cur;
}
void insert(int c,int x,int y,int k)//更新一个区间
{
 int l,r,mid;
 if(k==-1)
    return ;
 l=a[k].low;r=a[k].high;
 if(!(x<=r&&l<=y))
     return ;
 if(x<=l&&r<=y)
 {
	a[k].count=c;
	return ;
 }
  if(a[k].count!=-1)
  {
     a[a[k].left].count=a[a[k].right].count=a[k].count;
     a[k].count=-1;
  }
  mid=(l+r)/2;
  insert(c,x,y,a[k].left);
  insert(c,x,y,a[k].right);
  if(a[a[k].left].count!=-1&&a[a[k].right].count!=-1&&a[a[k].left].count==a[a[k].right].count)
	  a[k].count=a[a[k].left].count;
}
void sum(int x,int y,int k)
{
 int l,r;
 l=a[k].low;r=a[k].high;
 if(k==-1)
    return ;
 if(!(x<=r&&l<=y))
     return ;
 if(x<=l&&r<=y&&a[k].count!=-1)//a[i].mark==true 表示其区间内颜色相同
 {
	flag[a[k].count]=1;
    return ;
 }
 sum(x,y,a[k].left);
 sum(x,y,a[k].right);
}
int main()
{
 int i,c,x,y,s,n,t,p;char ch[2];
 while(EOF!=scanf("%d%d%d",&n,&t,&p))
 {
  memset(a,-1,sizeof(a));
  tot=1;
  init(1,n);
  while(p--)
  {
	scanf("%s",ch);
	if(ch[0]=='C')
	{
	  scanf("%d%d%d",&x,&y,&c);
	  if(x>y)
	  {
		i=x;
		x=y;
		y=i;    
	  }
	  insert(c,x,y,1);
	}
	else
	{
	  scanf("%d%d",&x,&y);
	  if(x>y)
	  {
		i=x;
		x=y;
		y=i;    
	  }
	  s=0;
	 for(i=1;i<=t;i++)
	    flag[i]=0;
	 sum(x,y,1);
	 for(i=1;i<=t;i++)
		  s+=flag[i];
	  printf("%d\n",s);
	}
  }
 }
 return 0;
}

