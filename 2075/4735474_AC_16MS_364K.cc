#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=300000;
int p[maxn],num[maxn],n;
char name1[30],name2[30],node[maxn][30];
struct edge
{
	int i,j;
	double value;
};
edge c[maxn];
int cmp(const void *a, const void *b)
{
     struct edge *aa=(edge *)a;
     struct edge *bb=(edge *)b;
	 if(aa->value>=bb->value)
		 return 1;
	 else
		 return -1;
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
     int i,k,m;
	 double sum,total,temp;
     scanf("%lf %d",&total,&n);
	 for(i=1;i<=n;i++)
	     scanf("%s",node[i]);
	 scanf("%d",&m);
	 for(i=1;i<=m;i++)
	 {
		  scanf("%s %s %lf",name1,name2,&temp);
		  for(k=1;k<=n;k++)
			  if(strcmp(node[k],name1)==0)
			  {
				c[i].i=k;
				break;
			  }
		  for(k=1;k<=n;k++)
			  if(strcmp(node[k],name2)==0)
			  {
				c[i].j=k;
				break;
			  }
		  c[i].value=temp;
	 }	
	 qsort(c+1,m,sizeof(c[1]),cmp); 
	 for(i=1;i<=n;i++)
			Makeset(i);
	 sum=0.0;k=1;
	 for(i=1;i<=m;i++)
	 {
		if(Find(c[i].i)!=Find(c[i].j))
		{
				sum=sum+c[i].value;
				Union(c[i].i,c[i].j);
				k++;
		}
		if(k==n)
				break;
	}
	if(total>=sum)
	    printf("Need %.1lf miles of cable\n",sum);
	else
	    printf("Not enough cable\n");
    return 0;
 }     

