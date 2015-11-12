#include<stdio.h>
#include<stdlib.h>
const int maxn=11000;
int p[maxn],num[maxn],pos[maxn],ans[maxn];
int n,m,Q;
struct node
{
  int x,y,value;
};
node edge[51000];
struct Node
{
  int value,index;
};
Node q[11000];
int cmp1(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return   aa->value-bb->value;
}
int cmp2(const void *a,const void *b)
{
     struct Node *aa=(Node *)a;
     struct Node *bb=(Node *)b;
     return   aa->value-bb->value;
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

    int t1,t2,last;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
		  return 0;
    last=(num[t1]+num[t2])*(num[t1]+num[t2]-1);
    if(num[t1]>=2)
         last-=num[t1]*(num[t1]-1);
    if(num[t2]>=2)
         last-=num[t2]*(num[t2]-1);
    last/=2;
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
    return last;
}
int main()
 {   
     int i,j,first;
	 scanf("%d%d%d",&n,&m,&Q);
	 for(i=1;i<=m;++i)
	   scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].value);
     qsort(edge+1,m,sizeof(edge[1]),cmp1);
     for(i=1;i<=Q;++i)
     {
       scanf("%d",&q[i].value);
       q[i].index=i;
     }
     qsort(q+1,Q,sizeof(q[1]),cmp2);
     for(i=1;i<=Q;++i)
         pos[q[i].index]=i;
     for(i=1;i<=n;++i)
         Makeset(i);
     first=1;ans[0]=0;
     for(i=1;i<=Q;++i)
     {
       ans[i]=ans[i-1];
       while(first<=m&&edge[first].value<=q[i].value)
       {
          //printf("%d %d\n",edge[first].value,q[i].value);
          ans[i]+=Union(edge[first].x,edge[first].y);
          ++first;
       }
     }
    // for(i=1;i<=m;++i)
//        printf("%d\n",edge[i].value);
//     for(i=1;i<=Q;++i)
//        printf("%d %d %d\n",q[i].value,pos[i],ans[i]);
    for(i=1;i<=Q;++i)
       printf("%d\n",ans[pos[i]]);
    // scanf("%d",&i);
     return 0;
 }     

