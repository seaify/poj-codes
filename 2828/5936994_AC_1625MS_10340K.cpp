#include<stdio.h>
const int maxn=210000;
int n,tot;
int x[maxn],y[maxn],ans[maxn];

struct node
{
   int ls,rs,beg,end,c;
};
node tree[2*maxn];

int inline init(int a,int b)
{
   int cur=tot,mid;
   tree[cur].beg=a;
   tree[cur].end=b;
   tree[cur].c=b-a+1;
   if(a==b)
   {
	  tree[cur].ls=-1;
	  tree[cur].rs=-1;
	  return cur;
   }
   mid=(a+b)/2;
   ++tot;
   tree[cur].ls=init(a,mid);
   ++tot;
   tree[cur].rs=init(mid+1,b);
   return cur;
}

void inline seek(int a,int b,int v)
{
 
   int ls;

   tree[v].c--;

   if(tree[v].beg==tree[v].end)
   {
	   ans[tree[v].beg]=b;
	   return ;
   }

   ls=tree[v].ls;

   if(tree[ls].c>=a)
	   seek(a,b,tree[v].ls);
   else
	   seek(a-tree[ls].c,b,tree[v].rs);

}


int main()
{

  int i;
  while(EOF!=scanf("%d",&n))
  {
	  for(i=1;i<=n;i++)
		  scanf("%d %d",&x[i],&y[i]);

	  tot=1;
	  init(1,n);

	  for(i=n;i>=1;i--)
		  seek(x[i]+1,y[i],1);

	  for(i=1;i<n;i++)
		  printf("%d ",ans[i]);
	  printf("%d\n",ans[n]);

  }


  return 0;
}

