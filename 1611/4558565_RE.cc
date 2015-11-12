#include<stdio.h>
int m,n;
int parent[50100];
void Make_set()   //初始化
{
	int i;
for(i=0;i<n;i++)
   parent[i]=-1;
}
int Find(int x)   //返回第Ｘ节点所属集合的根结点
{
int i,tmp;
for( i=x;parent[i]>=0;i=parent[i]);
return i;
}
void Union(int R1,int R2)   //将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
{
int tmp=parent[R1]+parent[R2];
if(parent[R1]>parent[R2]) //优化方案――加权法则
{
   parent[R1]=R2;
   parent[R2]=tmp;
}
else
{
   parent[R2]=R1;
   parent[R1]=tmp;
}
}
int main()
{
	int i,j,c,root,h,k;
	while(EOF!=scanf("%d%d",&n,&m)&&(n||m))
	{
		if(m==0)
		{
			printf("1\n");
			continue;
		}
		Make_set();
		for(i=1;i<=m;i++)
		{
			scanf("%d",&c);
			if(c==0)
				continue;
            scanf("%d",&root);
			parent[root]=-c;
			for(j=1;j<c;j++)
			{
		  	  scanf("%d",&h);
			  if(parent[h]!=-1)
			  {
				  k=Find(h);
				  parent[k]++;
				  Union(k,root);
				  root=Find(h);
			  }	
			  else
				  parent[h]=root;
			}
		}
		printf("%d\n",-parent[Find(0)]);
	}
	return 0;
}

