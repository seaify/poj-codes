#include<stdio.h>
#include<string.h>
const int maxn=100010;
int flag[40];
struct node
{
 int low,high,left,right,count;
}a[4*maxn];
void init(int low,int high,int i)//初始化
{
  int mid;
  a[i].low=low;
  a[i].high=high;
  a[i].count=1;
  if(low==high)
       return ;
  a[i].left=2*i;
  a[i].right=2*i+1;
  mid=(low+high)/2;
  init(low,mid,2*i);
  init(mid+1,high,2*i+1);
}
void insert(int c,int x,int y,int k)//更新一个区间
{
 int l,r,mid;
 l=a[k].low;r=a[k].high;
 if(x<=r&&l<=y)//区间相交
 {
  if(a[k].count>0)//必需保证该区间内的值相同，即a[k].mark为true,如果为false时，其许多子区间未更新
  {
	if(x<=l&&r<=y)
	{
		a[k].count=c;
		return ;
	}
	else
	{
	   if(a[k].left!=0)
	      a[2*k].count=a[2*k+1].count=a[k].count;
	}
  }
  if(a[k].left==0)
	   return ;
  a[k].count=-1;
  mid=(l+r)/2;
  if(y<=mid)
      insert(c,x,y,2*k);
  else if(x>mid)
	   insert(c,x,y,2*k+1);
  else
  {
	   insert(c,x,y,2*k);
       insert(c,x,y,2*k+1);
  }
  if(a[2*k].count>0&&a[2*k+1].count>0&&a[2*k].count==a[2*k+1].count)
	  a[k].count=a[2*k].count;
 }
}
void sum(int x,int y,int k)
{
 int l,r;
 l=a[k].low;r=a[k].high;
 if(x<=r&&l<=y)
 {
   if(a[k].count>0&&x<=l&&r<=y)//a[i].mark==true 表示其区间内颜色相同
   {
	flag[a[k].count]=1;
    return ;
   }
   if(a[k].left==0)
	   return ;
   sum(x,y,2*k);
   sum(x,y,2*k+1);
 }
}
int main()
{
 int i,c,x,y,s,n,t,p;char ch[2];
 scanf("%d%d%d",&n,&t,&p);
 memset(a,0,sizeof(a));
 init(1,n,1);
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
 return 0;
}


