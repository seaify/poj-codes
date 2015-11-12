#include<stdio.h>
#include<stdlib.h>
const int maxn=100010;
int p[maxn],num[maxn],map[maxn];
bool flag[maxn];
int sum;
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
int main()
 {   
     int i,j,x,y,n,m,t;
	 char ch[3];
	 scanf("%d",&t);
     while(t--)
	 {
	   scanf("%d%d",&n,&m);	 
       for(i=1;i<=n;i++)
		 {
			 flag[i]=false;
			 Makeset(i);
		 }
	   while(m--)
	   {
		scanf("%s",ch);
		if(ch[0]=='D')
		{
		 scanf("%d%d",&x,&y);
		 if(flag[x])
		   Union(map[x],y);
		 else
		 {
			 flag[x]=true;
			 map[x]=y;
		 }
		 if(flag[y])
           Union(map[y],x);
		 else
		 {
			 flag[y]=true;
			 map[y]=x;
		 }
	   }
	   else
	   {
		 scanf("%d%d",&x,&y);
		 i=Find(x);
		 j=Find(y);
		 if(i==j)
			 printf("In the same gang.\n");
		 else
		 {
			 if(flag[x]==false||flag[y]==false)
				 printf("Not sure yet.\n");
			 else
			 {
				 if(i==Find(map[y]))
					 printf("In different gangs.\n");
				 else
					 printf("Not sure yet.\n");
			 }
		 }
	   }
      }    
	 }
     return 0;
 }     


