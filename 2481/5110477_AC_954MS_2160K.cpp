#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=100010;
int n,c[maxn],flag[maxn],maxv;
struct node
{
  int x,y,tag;
};
node e[maxn];
int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     if(aa->y!=bb->y)
         return bb->y-aa->y;
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
    int i;
	while(EOF!=scanf("%d",&n))
	{
	  if(n==0)
		   break;
	  maxv=0;
      for(i=1;i<=n;++i)
      {
         scanf("%d%d",&e[i].x,&e[i].y);
         ++e[i].x,++e[i].y;
         e[i].tag=i;
		 if(e[i].y>maxv)
			  maxv=e[i].y;
      }
      qsort(e+1,n,sizeof(e[1]),cmp);
      memset(c,0,(n+1)*sizeof(int));
      flag[e[1].tag]=0;
      add(e[1].x,1,maxv);
	  for(i=2;i<=n;i++)
	  {  
        if(e[i].x==e[i-1].x&&e[i].y==e[i-1].y)
            flag[e[i].tag]=flag[e[i-1].tag];
	    else
	        flag[e[i].tag]=sum(e[i].x);
		add(e[i].x,1,maxv);
 	  }
	  for(i=1;i<n;i++)
	     printf("%d ",flag[i]);
	  printf("%d\n",flag[n]);
    }
	return 0;
}
