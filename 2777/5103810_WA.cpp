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
 int l,r;
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
 if(a[k].count!=-1)
 {
   flag[a[k].count]=1;
   return ;
 }
 if(a[k].left<a[k].right)//a[i].mark==true 表示其区间内颜色相同
 {
  int mid=(a[k].left+a[k].right)>>1;
  if(y<=mid)
     sum(x,y,a[k].left);
  else if(x>mid)
     sum(x,y,a[k].right);
  else
  {   sum(x,mid,a[k].left);
             sum(mid+1,y,a[k].right);
  }
 }

}
int main()
{
 int i,c,x,y,s,n,t,p;char ch[2];
 while(EOF!=scanf("%d%d%d",&n,&t,&p))
 {
  memset(a,-1,sizeof(a));
  tot=1;
  init(1,n);
  for(i=1;i<=tot;++i)
	   printf("%d %d %d %d %d\n",a[i].left,a[i].right,a[i].low,a[i].high,a[i].count);
  while(p--)
  {
	scanf("%s",ch);
	if(ch[0]=='C')
	{
	  scanf("%d%d%d",&x,&y,&c);
	  if(x>y)
	    insert(c,y,x,1);
      else
	    insert(c,x,y,1);
	}
	else
	{
	  scanf("%d%d",&x,&y);
	  s=0;
	  for(i=1;i<=t;i++)
	    flag[i]=0;
      if(x<=y)
	     sum(x,y,1);
      else
         sum(y,x,1);
	  for(i=1;i<=t;i++)
		  s+=flag[i];
	   printf("%d\n",s);
	}
	
  }
 }
 return 0;
}

