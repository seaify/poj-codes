#include<stdio.h>
#include<stdlib.h>
const int maxn=100;
int p[maxn],num[maxn];
struct edge
{
	int i,j,value;
};
edge c[100000];
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
     int i,j,k,n,sum,s,a,b,m;
     while(EOF!=scanf("%d",&n)&&n)
      {
	    scanf("%d",&m);
	    if(m==0)
	    {
		  printf("0\n");
		  continue;
		}
	    for(i=1;i<=m;++i)
		{
		  scanf("%d%d%d",&a,&b,&k);
		  c[i].i=a;
		  c[i].j=b;
		  c[i].value=k;
	    } 
		qsort(c+1,m,sizeof(c[1]),cmp); 
		for(i=1;i<=n;i++)
			Makeset(i);
		sum=0;s=1;
		for(i=1;i<=m;i++)
		{
			if(Find(c[i].i)!=Find(c[i].j))
			{
				sum=sum+c[i].value;
				Union(c[i].i,c[i].j);
				s++;
			}
			if(s==n)
				break;
		}
		printf("%d\n",sum);
      }    
     return 0;
 }     

  
