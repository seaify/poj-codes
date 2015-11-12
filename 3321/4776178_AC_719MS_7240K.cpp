#include<stdio.h>
const int maxn=100005;
int time,begin[maxn],end[maxn],c[maxn],flag[maxn];
struct Edge
{
 int dest;
 Edge *link;
};
Edge *edge=new Edge[maxn];
Edge *l;
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
void add(int i,int j,int x )//将a[index]加上x 
{
	while(i<=j)
	{
		c[i]=c[i]+x;
		i=i+lowbit(i);//实际上是一个把末尾1补为0的过程 
	}	
}
void DFS(int cur)
{
	Edge *l;
	++time;
	begin[cur]=time;
	l=edge[cur].link;
	while(l)
	{
	  DFS(l->dest); 
	 // c[cur]+=c[l->dest];
	  l=l->link;
	}
	end[cur]=time;
}
int main()
{	
    int i,n,m,x,y;char ch[2];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		edge[i].link=NULL;
		flag[i]=0;
		add(i,n,1);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		l=new Edge;
	    l->dest=y;
   	    l->link=edge[x].link;
	    edge[x].link=l;
	}
    time=0;DFS(1);
	scanf("%d",&m);
	while(m--)
	{
	  scanf("%s",ch);
	  if(ch[0]=='C')
	  {
		scanf("%d",&x);
		++flag[x];
		if(flag[x]%2==0)
			add(begin[x],n,1);
		else
            add(begin[x],n,-1);
	  }
	  else
	  {
		scanf("%d",&x);
		printf("%d\n",count(begin[x],end[x]));
	  }
	}
	return 0;
}
