#include<stdio.h>
#include<stdlib.h>
const int maxn=51000;
int p[maxn],num[maxn];
struct edge
{
	int i,j,value;
};
edge c[51000];
int cmp(const void *a, const void *b)
{
     struct edge *aa=(edge *)a;
     struct edge *bb=(edge *)b;
     return aa->value-bb->value;
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
     int i,j,k,n,m,sum,s,T,value,last,t;
	 scanf("%d",&T);
	 while(T--)
	 {
        scanf("%d%d%d",&n,&t,&m);
		k=0;
		while(m--)
		{
		    scanf("%d%d%d",&i,&j,&value);
			c[++k].i=i;
			c[k].j=j+n;
			c[k].value=10000-value;
		}
		n+=t;	
		qsort(c+1,k,sizeof(c[1]),cmp); 
		for(i=0;i<n;i++)
			Makeset(i);
		sum=0;s=1;last=n;
		for(i=1;i<=k;i++)
		{
			if(Find(c[i].i)!=Find(c[i].j))
			{
				--last;
				sum=sum+c[i].value;
				Union(c[i].i,c[i].j);
				s++;
			}
			if(s==n)
				break;
		}
		sum+=last*10000;
		printf("%d\n",sum);
     }
     return 0;
 }     

  
