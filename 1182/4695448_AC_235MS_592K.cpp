#include<stdio.h>
#include<stdlib.h>
const int maxn=51000;
int p[maxn],num[maxn],x,y;
void Makeset(int x)
 {
     p[x]=-1;
     num[x]=0;
 } 
int Find(int i,int j)//非递归压缩路径
 {
     int r,s,t;
	 s=0;r=i;
     while(p[r]!=-1)//找到根结点
	 {
		 s+=num[r];
		 r=p[r];
	 }
	 if(j==1)
		 x=s%3;
	 else
		 y=s%3;
     while(i!=r)
      {
          int q=p[i];
          p[i]=r;
		  t=num[i];
		  num[i]=s%3;
		  s-=t;
          i=q;
      }
    return r;      
 }     
int Union(int t1,int t2,int h)
{
    p[t2]=t1;
	num[t2]=(x-y+3+h)%3;
    return 0;
}
int main()
{   
  int n,i,k,count,d,t1,t2;
  scanf("%d%d",&n,&k);
  for(i=1;i<=n;i++)
	   Makeset(i);
  count=0;
  while(k--)
  {
	scanf("%d%d%d",&d,&x,&y);
	if(x>n||y>n)
	{
	  count++;
	  continue;
	}
	if(d==2&&x==y)
	{
	  count++;
	  continue;
	}
	t1=Find(x,1);t2=Find(y,2);
	if(t1!=t2)
		Union(t1,t2,d-1);
	else
	{
	  if(d==2&&(x-y+3)%3==2)
	   	  continue;
	  if(d==1&&x==y)
		  continue;
      count++;
	}
  }
  printf("%d\n",count);
  return 0;
}     


