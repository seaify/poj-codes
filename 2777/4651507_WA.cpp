#include<stdio.h>
#include<string.h>
const int maxn=100010;
int i,l,r,n,t,p,flag[40];
char ch;
struct node
{
int low,high,left,right,count;
bool mark;
}a[4*maxn];
void init(int low,int high,int i)//初始化
{
int mid;
a[i].left=2*i;
a[i].right=2*i+1;
a[i].low=low;
a[i].high=high;
a[i].count=1;
a[i].mark=true;
if(low==high)
   return ;
mid=(low+high)/2;
init(low,mid,2*i);
init(mid+1,high,2*i+1);
}
int insert(int c,int x,int y,int k)//更新一个区间
{
 if(a[k].left==0)
	 return 0;
 l=a[k].low;r=a[k].high;
if(x<=r&&l<=y)
{
if(a[k].mark&&x<=l&&r<=y)//必需保证该区间内的值相同，即a[k].mark为true,如果为false时，其许多子区间未更新
{
   a[k].count=c;
   a[k].mark=true;
   return 0;
}
if(a[k].mark)//因为需要修改，故值向下传
{
    a[k].mark=false;
    a[2*k].count=a[2*k+1].count=a[k].count;
    a[2*k].mark=a[2*k+1].mark=true;
}
insert(c,x,y,2*k);
insert(c,x,y,2*k+1);
if(a[2*k].mark&&a[2*k+1].mark&&a[2*k].count==a[2*k+1].count)//合并两段区间
{
   a[k].count=a[2*k].count;
   a[k].mark=true;
}
}
return 0;
}
int sum(int x,int y,int k)//觉得应该可以将所求区间和树一起分解加速运行，
{
if(a[k].left==0)
    return 0;
l=a[k].low;r=a[k].high;
if(x<=r&&l<=y)
{
   if(a[k].mark&&x<=l&&r<=y)//a[i].mark==true 表示其区间内颜色相同
   {
	flag[a[k].count]=1;
    return 0;
   }
  sum(x,y,2*k);
  sum(x,y,2*k+1);
}
return 0;
}
int main()
{
int i,c,x,y,s;
 scanf("%d%d%d",&n,&t,&p);
 memset(a,0,sizeof(a));
 init(1,n,1);
 while(p--)
 {
	scanf("\n%c",&ch);
	if(ch=='C')
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
