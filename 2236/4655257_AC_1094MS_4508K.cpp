#include<stdio.h>
#include<stdlib.h>
const int maxn=1100;
int p[maxn],num[maxn],map[maxn][maxn];
bool flag[maxn];
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
int Union(int a,int b)
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
int dis(int i,int j)
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
	 d=d*d;
	 for(i=1;i<=n;i++)
	 {
		 Makeset(i);
		 map[i][0]=0;
		 flag[i]=false;
	 }
	 for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		  if(dis(i,j)<=d)
		  {
			map[i][++map[i][0]]=j;
			map[j][++map[j][0]]=i;
		  }
    while(EOF!=scanf("\n%c",&ch))
	{
	  if(ch=='O')
	  {
		scanf("%d",&x);
		flag[x]=true;
		for(i=1;i<=map[x][0];i++)
			if(flag[map[x][i]])
				Union(x,map[x][i]);
	  }
	  else
	  {
		scanf("%d%d",&x,&y);
		if(Find(x)==Find(y))
			printf("SUCCESS\n");
		else
			printf("FAIL\n");
	  }
	}
     return 0;
 }     

