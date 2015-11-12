#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn=300000;
int p[maxn],num[maxn],n;
char name1[30],name2[30];
struct Node
{
  char name[30];
  int index;
};
Node node[maxn]; 
struct edge
{
	int i,j;
	double value;
};
edge c[maxn];
int cmp1(const void *a,const void *b)
{
   struct Node *aa=(Node *)a;
   struct Node *bb=(Node *)b;
   return strcmp(aa->name,bb->name);
}
int cmp2(const void *a, const void *b)
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
int Bsearch(char a[])
{
  int left,mid,right,k;
  left=1;right=n;
  while(left<=right)
  {
	mid=(left+right)/2;
	k=strcmp(node[mid].name,a);
	if(k==0.0)
		return mid;
	else if(k<0.0)
		left=mid+1;
	else
		right=mid-1;
  }
  return 0;
}
int main()
 {   
     int i,k,m;
	 double sum,total,temp;
     scanf("%lf %d",&total,&n);
	 for(i=1;i<=n;i++)
	 {
	   node[i].index=i;
	   scanf("%s",node[i].name);
	 }
	 qsort(node+1,n,sizeof(node[1]),cmp1);
	 scanf("%d",&m);
	 for(i=1;i<=m;i++)
	 {
		  memset(name1,0,sizeof(name1));
		  memset(name2,0,sizeof(name2));
		  scanf("%s %s %lf",name1,name2,&temp);
	      c[i].i=Bsearch(name1);
		  c[i].j=Bsearch(name2);
		  c[i].value=temp;
	 }	
	 qsort(c+1,m,sizeof(c[1]),cmp2); 
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

