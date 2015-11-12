#include<stdio.h>
#include<stdlib.h>
const int maxn=1100;
int p[maxn],num[maxn],map[maxn][maxn];
bool flag[maxn];//标记数组，刚开始全部置为false
typedef struct 
{
  int x,y;
}node;
node c[maxn];
void Makeset(int x)
 {
     p[x]=-1;
     num[x]=1;
 } 
int Find(int x)//非递归压缩路径
 {
     int r=x;
     while(p[r]!=-1)//找到根结点
         r=p[r];
     while(x!=r)
      {
          int q=p[x];
          p[x]=r;
          x=q;
      }
    return r;      
 }     
int Union(int a,int b)//合并2个堆
{
    int t1,t2;
	if(a==b)
		return 0;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
		  return 0;
    if(num[t2]<=num[t1])
    {
        p[t2]=t1;
        num[t1]+=num[t2];
    }
    else
    {
        p[t1]=t2;
        num[t2]+=num[t1];
    }
    return 0;
}
int dis(int i,int j)//计算2个点距离的平方
{
	return (c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y);
}
int main()
 {   
     int i,j,x,y,n,d;
	 char ch;
	 scanf("%d%d",&n,&d);
	 for(i=1;i<=n;i++)
		 scanf("%d%d",&c[i].x,&c[i].y);
	 d=d*d;//为比较是否2点距离<=d，为避免开方引起的精度问题
	 for(i=1;i<=n;i++)
	 {
		 Makeset(i);//初始化堆
		 map[i][0]=0;//map[i][0]表示和i距离<=d的点的个数,分别用map[i][1]....map[1][map[i][o]]表示
		 flag[i]=false;//
	 }
	 for(i=1;i<n;i++)//这个地方已经注定了这个算法的低效，
		for(j=i+1;j<=n;j++)
		  if(dis(i,j)<=d)
		  {
			map[i][++map[i][0]]=j;//计算出每个点的情况
			map[j][++map[j][0]]=i;
		  }
    while(EOF!=scanf("\n%c",&ch))//显然还有大量可以优化的地方，例如许多重复的合并
	{
	  if(ch=='O')
	  {
		scanf("%d",&x);
		flag[x]=true;
		for(i=1;i<=map[x][0];i++)//每修理好1台电脑，检查和它距离<=d的电脑，如果该电脑已出现过,合并
			if(flag[map[x][i]])//在查找方面应该能有改进
				Union(x,map[x][i]);
	  }
	  else
	  {
		scanf("%d%d",&x,&y);
		if(flag[x]&&flag[y]&&Find(x)==Find(y))//前面的操作已经完成了堆的合并，直接判断
			printf("SUCCESS\n");
		else
			printf("FAIL\n");
	  }
	}
     return 0;
 }     

