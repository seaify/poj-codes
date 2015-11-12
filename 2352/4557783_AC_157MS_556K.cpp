//http://acm.pku.edu.cn/JudgeOnline/problem?id=2352
#include<stdio.h>
int i,j,n,t,c[32100],s,flag[32100],x,y,a[32100];
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
int count(int i,int j)
{
	return sum(j)-sum(i-1);
}
void add(int i,int x)//将a[i]加上x 
{
	while(i<=32001)
	{
		c[i]=c[i]+x;
		i=i+lowbit(i);//实际上是一个把末尾1补为0的过程 
	}	
}
int main()
{	

	scanf("%d",&n);
	flag[0]=0;
	for(i=1;i<=32001;i++)
	{
		flag[i]=0;
		c[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		x++;
		flag[sum(x-1)+a[x]]++;	
		add(x,1);
		a[x]++;
	//	printf("%d\n",sum(x));	
	}
	for(i=0;i<n;i++)
	   printf("%d\n",flag[i]);
	return 0;
}
