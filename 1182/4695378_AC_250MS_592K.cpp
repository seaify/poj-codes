#include<stdio.h>
#include<stdlib.h>
const int maxn=51000;
int p[maxn],num[maxn];
void Makeset(int x)
 {
     p[x]=-1;
     num[x]=0;
 } 
int Find(int x)//非递归压缩路径
 {
     int r,s,t;
	 s=0;r=x;
     while(p[r]!=-1)//找到根结点
	 {
		 s+=num[r];
		 r=p[r];
	 }
     while(x!=r)
      {
          int q=p[x];
          p[x]=r;
		  t=num[x];
		  num[x]=s%3;
		  s-=t;
          x=q;
      }
    return r;      
 }     
int sum(int x)
{
 int r=x,s=0;
 while(p[r]!=-1)//找到根结点,并未将根结点上的num[r]加上来
 {
	 s+=num[r];
	 r=p[r];
 }
 return s%3;
}
int Union(int a,int b,int h)
{
    int t1,t2;
	if(a==b)
	   return 0;
    t1=Find(a);
    t2=Find(b);
    p[t2]=t1;
	num[t2]=(sum(a)-sum(b)+3+h)%3;
    return 0;
}
int main()
{   
  int n,i,k,x,y,count,d;
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++)
	   Makeset(i);
  count=0;
  while(k--)
  {
	scanf("%d%d%d",&d,&x,&y);
	if(x>n||y>n)
	{
	  count++;
	  continue;
	}
	if(d==2&&x==y)
	{
	  count++;
	  continue;
	}
	if(Find(x)!=Find(y))
		Union(x,y,d-1);
	else
	{
	  if(d==2&&(sum(x)-sum(y)+3)%3==2)
	   	  continue;
	  if(d==1&&sum(x)==sum(y))
		  continue;
      count++;
	}
  }
  printf("%d\n",count);
  return 0;
}     


