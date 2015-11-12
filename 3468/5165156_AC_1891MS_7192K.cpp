#include<stdio.h>
const int maxn=110000;
int  n,m,tot;
__int64 sum[maxn],last;
struct node
{
   int ls,rs,beg,end;
   __int64 mark,value;
};
node tree[2*maxn];
int init(int a,int b)
{
   int cur=tot,mid;
   tree[cur].beg=a;
   tree[cur].end=b;
   tree[cur].value=0;
   tree[cur].mark=0;
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
void insert(int cur,int x,int y,int c)
{
  int l,r;
  if(cur==-1)
      return ;
  l=tree[cur].beg;r=tree[cur].end;
  if(!(x<=r&&l<=y))
     return ;
  if(x<=l&&r<=y)
  {
	tree[cur].mark+=c;
	tree[cur].value+=c*(tree[cur].end-tree[cur].beg+1);
	return ;
  }
  l=tree[cur].ls,r=tree[cur].rs;//由线段树的构造知可保证其左右孩子均存在。。 
  tree[l].mark+=tree[cur].mark, tree[l].value+=tree[cur].mark*(tree[l].end-tree[l].beg+1);
  tree[r].mark+=tree[cur].mark, tree[r].value+=tree[cur].mark*(tree[r].end-tree[r].beg+1);
  tree[cur].mark=0;
  insert(l,x,y,c);
  insert(r,x,y,c);
  tree[cur].value=tree[l].value+tree[r].value;
}
void add(int cur,int x,int y)
{
  int l,r;
  if(cur==-1)
     return ;
  l=tree[cur].beg,r=tree[cur].end;
  if(!(x<=r&&l<=y))
     return ;
  if(x<=l&&r<=y)
  {
     last+=tree[cur].value;
     return ;
  }
  l=tree[cur].ls,r=tree[cur].rs;//由线段树的构造知可保证其左右孩子均存在。。 
  tree[l].mark+=tree[cur].mark, tree[l].value+=tree[cur].mark*(tree[l].end-tree[l].beg+1);
  tree[r].mark+=tree[cur].mark, tree[r].value+=tree[cur].mark*(tree[r].end-tree[r].beg+1);
  tree[cur].mark=0;
  add(l,x,y);
  add(r,x,y);//无需更新value值，因为并没有对其做出任何修改。。   
} 
int main()
{
   int i,value,x,y,c; char ch[2];
   while(EOF!=scanf("%d%d",&n,&m))
   {
      sum[0]=0;
      for(i=1;i<=n;++i)
      {
         scanf("%d",&value);
         sum[i]=sum[i-1]+value;
      }
      tot=1;
      init(1,n);
      while(m--)
      {
         scanf("%s",ch);
         if(ch[0]=='C')
         {
            scanf("%d%d%d",&x,&y,&c);
            insert(1,x,y,c);
         }
         else
         {
            scanf("%d%d",&x,&y);
            last=sum[y]-sum[x-1];
            add(1,x,y);
            printf("%I64d\n",last);
         }
      }
   }
}
