#include<stdio.h>
#include<algorithm>
using namespace std;

int p[2000],num[2000];
int n,m;

struct node
{
	int x,y,value;
};

node c[40000];

int cmp(node a,node b)
{
    return a.value>b.value;
}

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
     int i,j,k,n,sum,s;
     while(EOF!=scanf("%d %d",&n,&m))
      {
          for(i=1;i<=m;i++)
             scanf("%d %d %d",&c[i].x,&c[i].y,&c[i].value);
		  sort(c+1,c+m+1,cmp);
		  
		  for(i=1;i<=n;i++)
			  Makeset(i);
		  sum=0;
          s=1;
		  for(i=1;i<=m;i++)
		  { 
			if(Find(c[i].x)!=Find(c[i].y))
			{
				sum=sum+c[i].value;
				Union(c[i].x,c[i].y);
				s++;
			}
			if(s==n)
			{
                printf("%d\n",sum);
				break;
            }
		 }
		 
		 if(s!=n)
		      printf("-1\n");
		
      }    
     return 0;
 }     

  

   
