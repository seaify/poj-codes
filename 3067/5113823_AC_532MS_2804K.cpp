#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
__int64 c[1100];int maxv;
struct node
{
	int x,y;
};
node a[1000002];
int cmp(const void *a,const void *b)
{
	 struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     if(aa->x!=bb->x)
		 return aa->x-bb->x;
	 else
		 return aa->y-bb->y;
}
int lowbit(int i)//计算2^k，k为i的二进制末尾0的个数 
{
	return i&(-i); 
}
__int64 sum(int i)
{
  __int64 s=0;
  while(i>0)
  {
	s+=c[i];
	i-=lowbit(i);	
  }
  return s;
} 
__int64 count(int i,int j)
{
	return sum(j)-sum(i-1);
}
void add(int i,int x,int maxv)//将a[i]加上x 
{
	while(i<=maxv)
	{
		c[i]=c[i]+x;
		i=i+lowbit(i);//实际上是一个把末尾1补为0的过程 
	}	
}
int main()
{	
    int k,m,n,T,cases,i;
	__int64 out;
	scanf("%d",&T);
	cases=1;
	while(T--)
	{
	 scanf("%d %d %d",&m,&n,&k);
	 for(i=1;i<=k;i++)
	 {
	   scanf("%d %d",&a[i].x,&a[i].y);
	   if(a[i].y>maxv)
	      maxv=a[i].y;
    }
	 qsort(a+1,k,sizeof(a[1]),cmp);
     memset(c,0,sizeof(c));
	 add(a[1].y,1,maxv);out=0;
     for(i=2;i<=k;i++)
	 {
		out+=count(a[i].y+1,maxv);
		add(a[i].y,1,maxv);
	 }
    printf("Test case %d: %I64d\n",cases++,out);
	}
	return 0;
}


