#include<stdio.h>
#include<stdlib.h>
const int maxn=2002;
int p[maxn],num[maxn],map[maxn][maxn];
int n,m,k;
struct edge
{
	int i,j;
};
edge c[1000005];
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
     int i,j,k,n,t,x,y;
	 k=1;
     scanf("%d",&t);
	 while(t--)
	 {
		 scanf("%d%d",&n,&m);
		 for(i=1;i<=n;i++)
		 {
			 map[i][0]=0;
			 Makeset(i);
		 }
		 for(i=1;i<=m;i++)
		 {
			 scanf("%d%d",&x,&y);
			 c[i].i=x;
			 c[i].j=y;
			 map[x][++map[x][0]]=y;
			 map[y][++map[y][0]]=x;//注意
		 }
		 for(i=1;i<=n;i++)
			 for(j=2;j<=map[i][0];j++)//
				 Union(map[i][1],map[i][j]);
		 for(i=1;i<=m;i++)
			 if(Find(c[i].i)==Find(c[i].j))
				 break;
		printf("Scenario #%d:\n",k++);
		if(i==m+1)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	 }     
     return 0;
 }     

  

   

    

     

      

        

 

 


