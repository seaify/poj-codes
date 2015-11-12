#include<stdio.h>
#include<stdlib.h>
int c[1100];
struct node
{
	int x,y;
};
node a[1000002];
int cmp(const void *a,const void *b)
{
	 struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     if(aa->y!=bb->y)
		 return aa->y-bb->y;
	 else
		 return aa->x-bb->x;
}
int lowbit(int i)//计算2^k，k为i的二进制末尾0的个数 
{
	return i&(-i); 
}
int sum(int i)//计算从a[1]到a[i]的数据的和 
{
  int s=0;
  while(i>0)
  {
	s+=c[i];
	i-=lowbit(i);	//实际上等价于将i的二进制的最后一个1减去
  }
  return s;
} 
void add(int i,int x)//将a[i]加上x 
{
	while(i<=1000)
	{
		c[i]=c[i]+x;
		i=i+lowbit(i);//实际上是一个把末尾1补为0的过程 
	}	
}
int main()
{	
    int s,k,t,m,n,i,cases;
	scanf("%d",&t);
	cases=1;
	while(t--)
	{
	scanf("%d%d%d",&m,&n,&k);
	s=0;
	for(i=1;i<=k;i++)
	   scanf("%d%d",&a[i].x,&a[i].y);
	qsort(a+1,k,sizeof(a[1]),cmp);
	add(a[1].x,1);
    for(i=2;i<=k;i++)
	{
		s=s+i-1-sum(a[i].x);
		add(a[i].x,1);
	}
    printf("Test case %d: %d\n",cases++,s);
	}
	return 0;
}
