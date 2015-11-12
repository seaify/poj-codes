#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=100010;
int n,c[maxn],flag[maxn],maxv;
struct node
{
  int x,y,tag,cnt;//c表示其出现次数。。。 
};
node e[maxn];
int cmp1(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return aa->x-bb->x;//先按x值排序。。。 
}
int cmp2(const void *a,const void *b)
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
    int i,close,s;
	while(EOF!=scanf("%d",&n))
	{
	  if(n==0)
		   break;
      for(i=1;i<=n;++i)
      {
         scanf("%d%d",&e[i].x,&e[i].y);
         ++e[i].x,++e[i].y;
         e[i].tag=i;	
      }
      qsort(e+1,n,sizeof(e[1]),cmp1);
     // for(i=1;i<=n;++i)//判重。。。。
//      {
//         j=i;
//         while(e[j].x==e[i].x)
//           ++j;
//         e[i].cnt=j-i;
//         i=j-1;
//      } 
      close=0;maxv=0;s=0;//前移和。。。 
      for(i=1;i<=n;++i)
      {
          e[i].x-=s,e[i].y-=s;
          if(e[i].x<=close)
          {
             if(e[i].y>close)
                 close=e[i].y;
          }
          else
          {  
             s+=e[i].x-close-1;
             e[i].y=close+1+e[i].y-e[i].x;
             e[i].x=close+1;
             if(e[i].y>close)
               close=e[i].y;
          }
          if(e[i].x>maxv)
			  maxv=e[i].x;
      }
     // for(i=1;i<=n;++i)
       //  printf("%d %d\n",e[i].x,e[i].y);
      qsort(e+1,n,sizeof(e[1]),cmp2);
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

