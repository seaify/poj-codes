#include<stdio.h>
#include<string.h>
const int maxn=100010;
int flag[40],tot;
struct node
{
 int beg,end,ls,rs,count;
}a[4*maxn];
int init(int beg,int end)//初始化
{
  int mid,cur;
  cur=tot;
  a[cur].beg=beg;
  a[cur].end=end;
  a[cur].count=1;
  mid=(beg+end)/2;
  if(beg==end)
  {
     a[cur].ls=-1;
     a[cur].rs=-1;
     return cur;
  }
  ++tot;
  a[cur].ls=init(beg,mid);
  ++tot;
  a[cur].rs=init(mid+1,end);
  return cur;
}
void insert(int c,int x,int y,int k)//更新一个区间
{
 int l,r,mid;
 if(k==-1)
    return ;
 l=a[k].beg;r=a[k].end;
 if(!(x<=r&&l<=y))
     return ;
 if(x<=l&&r<=y)
 {
	a[k].count=c;
	return ;
 }
  if(a[k].count!=-1)
  {
     a[a[k].ls].count=a[a[k].rs].count=a[k].count;
     a[k].count=-1;
  }
  insert(c,x,y,a[k].ls);
  insert(c,x,y,a[k].rs);
  if(a[a[k].ls].count!=-1&&a[a[k].rs].count!=-1&&a[a[k].ls].count==a[a[k].rs].count)
	  a[k].count=a[a[k].ls].count;
}
void sum(int x,int y,int k)
{
 int l,r,mid;
 l=a[k].beg;r=a[k].end;
 if(k==-1)
    return ;
// if(!(x<=r&&l<=y))可以确保区间一定相交。。。 
 //    return ;
 if(l<=x&&y<=r&&a[k].count!=-1)//a[i].mark==true 表示其区间内颜色相同
 {
	flag[a[k].count]=1;
    return ;
 }
 mid=(l+r)/2; 
 if(y<=mid)
    sum(x,y,a[k].ls);
 else if(x>mid)
    sum(x,y,a[k].rs);
 else 
 {
    sum(x,mid,a[k].ls);
    sum(mid+1,y,a[k].rs);
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
  while(p--)
  {
	scanf("%s",ch);
	if(ch[0]=='C')
	{
	  scanf("%d%d%d",&x,&y,&c);
	  if(x<=y)
         insert(c,x,y,1);
      else
	    insert(c,y,x,1);
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


