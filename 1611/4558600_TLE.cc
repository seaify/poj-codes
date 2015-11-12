#include<stdio.h>
int m,n,i,j,k,c,root,a;
int parent[30100];
void Make_set()   //初始化
{
for(i=0;i<n;i++)
   parent[i]=-1;
}
int Find(int x)   //返回第Ｘ节点所属集合的根结点
{
for(int i=x;parent[i]>=0;i=parent[i]);
while(i!=x)    //优化方案――压缩路径
{
   int tmp=parent[x];
   parent[x]=i;
     x=tmp;
}
return i;
}
void Union(int R1,int R2)   //将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
{
if(R1==R2)
   return ;
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
	while(EOF!=scanf("%d%d",&n,&m)&&(n||m))
	{
		Make_set();
		for(i=1;i<=m;i++)
		{
			scanf("%d",&c);
            scanf("%d",&root);
			for(j=1;j<c;j++)
			{
		  	  scanf("%d",&a);
			  a=Find(a);
			  root=Find(root);
			  Union(a,root);			  		
			}
		}
		printf("%d\n",-parent[Find(0)]);
	}
	return 0;
}

