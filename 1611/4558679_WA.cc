#include<stdio.h>
int m,n,i,j,k,c,root,a,b;
int p[30100],rank[30100];
void Make_set()   //初始化
{
for(i=0;i<n;i++)
{
	p[i]=i;
	rank[i]=1;
}
}
int Find(int x)   //返回第Ｘ节点所属集合的根结点
{
	int i;
	for( i=x;p[i]!=i;i=p[i]);
while(i!=x)    //优化方案――压缩路径
{
   int tmp=p[x];
   p[x]=i;
     x=tmp;
}
  return i;
}
void Union(int x,int y)   //将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
{
	if(rank[x]>rank[y])
	{
		p[y]=x;
		rank[x]=rank[x]+rank[y];
	}
	else
	{
		p[x]=y;
  	    rank[y]=rank[x]+rank[y];
	}
}
int main()
{
	while(EOF!=scanf("%d%d",&n,&m)&&(n||m))
	{
		Make_set();
		for(i=1;i<=m;i++)
		{
			scanf("%d",&c);
            scanf("%d",&a);
			for(j=1;j<c;j++)
			{
		  	  scanf("%d",&b);
			  a=Find(a);
			  b=Find(b);
			  Union(a,b);			  		
			}
		}
		printf("%d\n",rank[Find(0)]);
	}
	return 0;
}

