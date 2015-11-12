#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=2002;
vector < int > e[1100],q[1100];
int p[maxn],num[maxn],in[maxn],c[maxn],father[maxn];
int n,m,k,root;
bool flag[maxn],last;

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

void LCA(int x)
{
	int i,y;
	Makeset(x);
	father[Find(x)]=x;
	for(i=0;i<e[x].size();++i)
	{
		y=e[x][i];
		LCA(y);
		Union(x,y);
		father[Find(x)]=x;
	}
	c[x]=1;
	for(i=0;i<q[x].size();++i)
	     if(c[q[x][i]])
		 {
			 y=father[Find(q[x][i])];
			 ++in[y];
		 }
}

int main()
 {   
     int i,x,y;
	 char ch;
	 while(EOF!= scanf("%d",&n))
	 {
		 for(i=1;i<=n;++i)
		 {
			 e[i].clear();
			 q[i].clear();    ////查询....
			 flag[i]=true;
		 }
		 for(i=1;i<=n;++i)
		 {
			 scanf("%d:(%d)",&x,&m);
			 while(m--)
			 {
				 scanf("%d",&y);
				 e[x].push_back(y);
				 flag[y]=false;
			 }
		 }
		 scanf("%d",&m);
		// printf("%d\n",m);
		 while(m--)
		 {
			 while(EOF!=scanf("%c",&ch)&&ch!='(');
			 scanf("%d",&x);
			 scanf("%d",&y);	
			 while(EOF!=scanf("%c",&ch)&&ch!=')');
			 q[x].push_back(y);
			 q[y].push_back(x);
		 }
		 for(i=1;i<=n;++i)  ///找根结点...
			 if(flag[i])
			 {
				 root=i;
				 break;
			 }
		 memset(c,0,sizeof(c));
		 memset(in,0,sizeof(in));
		 LCA(root);
		 for(i=1;i<=n;++i)
			 if(in[i])
				 printf("%d:%d\n",i,in[i]);
	 }     
     return 0;
 }     

