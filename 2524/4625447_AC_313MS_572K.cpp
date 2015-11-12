#include<stdio.h>
#include<stdlib.h>
const int maxn=51000;
int p[maxn],num[maxn];
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
	sum--;
    return 0;
}
int main()
 {   
     int i,j,n,m,t;
	 t=1;
     while(EOF!=scanf("%d%d",&n,&m))
	 {
		  if(n==0&&m==0)
			  break;
		  if(m==0)
		  {
			printf("Case %d: %d\n",t++,n);
            continue;
		  }
          for(i=1;i<=n;i++)
            Makeset(i);
		  sum=n;
		  while(m--)
		  {
			  scanf("%d%d",&i,&j);
			  Union(i,j);				  
		  }
		 printf("Case %d: %d\n",t++,sum);
      }    
     return 0;
 }     

  

   

