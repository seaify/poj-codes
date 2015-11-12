#include<stdio.h>
const int size=51000;
int p[size],num[size];
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

int Union(int x,int y)
{
    if(num[y]<=num[x])
    {
        p[y]=x;
        num[x]+=num[y];
    }
    else
    {
        p[x]=y;
        num[y]+=num[x];
    }
    return 0;
}
int main()
 {   
     int i,j,sum,n,t;
	 __int64 m;
	 t=1;
     while(scanf("%d%I64d",&n,&m))
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
			  if(Find(i)!=Find(j))
			  {
				  Union(i,j);
				  sum--;
			  }
		  }
		  printf("Case %d: %d\n",t++,sum);
      }    
     return 0;

 }     

  

   

    

     

      

        

 

 


