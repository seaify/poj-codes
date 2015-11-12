#include<stdio.h>
#include<stdlib.h>
const int maxn=30002;
int p[maxn],num[maxn],sum[maxn];
void Makeset(int x)
 {
     p[x]=-1;
     num[x]=0;//num[x]表示从根结点到该结点的和
	 sum[x]=1;
 } 
int Find(int x)//非递归压缩路径
 {
     int r=x,s;
	 s=0;
     while(p[r]!=-1)//r为根结点
	 {
		 r=p[r];
		 s=s+num[r];
	 }
	 s=s-num[r];
     while(x!=r)
      {
          int q=p[x];//q为x的父节点
          p[x]=r;
		  num[x]=s+num[x];//更新num[x],使num[x]的性质得以满足，出错的地方
		  s=s-num[q];
		  if(s==0)
			  break;
          x=q;
      }
    return r;         
 }     
int Union(int a,int b)
{
    int t1,t2;
    t1=Find(a);
    t2=Find(b);
    p[t2]=t1;
	sum[t1]+=sum[t2];//sum[x]表示该堆的个数
    num[t1]=num[t1]+sum[t2];
	num[t2]=num[t2]-num[t1];
    return 0;
}
int count(int x)
{
	int r,s;
	r=Find(x);
	s=0;
	while(x!=-1)
	{
		s=s+num[x];
		x=p[x];
	}
	return s;
}
int main()
 {   
     int i,t,x,y;
     char ch[3];
	 for(i=1;i<=30000;i++)
		 Makeset(i);
     scanf("%d",&t);
	 while(t--)
	 {
		 scanf("%s",ch);
		 if(ch[0]=='M')
		 {
			 scanf("%d%d",&x,&y);
			 Union(x,y);
		 }
		 else
		 {
			 scanf("%d",&x);
			 printf("%d\n",count(x));
		 }
	 }     
     return 0;
 }     

