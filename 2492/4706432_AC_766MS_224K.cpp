#include<stdio.h>
#include<stdlib.h>
const int maxn=2002;
int p[maxn],num[maxn],map[maxn];
int n,m,k;bool flag[maxn],last;
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
     int i,k,n,t,x,y;
	 k=1;
     scanf("%d",&t);
	 while(t--)
	 {
		 scanf("%d%d",&n,&m);
		 for(i=1;i<=n;i++)
		 {
			 flag[i]=0;
			 Makeset(i);
		 }
         last=true;
		 for(i=1;i<=m;i++)
		 {
			 scanf("%d%d",&x,&y);
			 if(last)
             {
			 if(Find(x)==Find(y))
                    last=false;
			 else 
			 {
			   if(flag[x])
				   Union(map[x],y);
			   if(flag[y])
				   Union(x,map[y]);
			   flag[x]=true;flag[y]=true;
			   map[x]=y;map[y]=x;
			 }
			 }
		 }	
		printf("Scenario #%d:\n",k++);
	    if(last==true)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
		if(t)
			printf("\n");
	 }     
     return 0;
 }     

