#include<stdio.h>
#include<malloc.h>
int flag[40],n,t,p;
char ch;
typedef struct node
{
 int i,j;
 int cover;
 struct node *lchild,*rchild;
}Tree;
Tree *CreateTree (int a,int b)
{
  Tree *r;
  if(b<a)
	  return (NULL);
  r=(Tree *)malloc(sizeof(Tree));
  r->i=a;r->j=b;r->cover=1;
  if(b-a>1)
  {
	r->lchild=CreateTree(a,(a+b)/2);
	r->rchild=CreateTree((a+b)/2,b);
  }
  else
  {
	r->lchild=r->rchild=NULL;
  }
  return r;
}
void Insert(Tree *r,int c,int a,int b)
{
 int mid;
 if(r==NULL)
	 return ;
 if(a<=r->i&&r->j<=b)
	 r->cover=c;
 else
 {
   if(r->cover>=1)
   {
	 if(r->lchild!=NULL)
		 r->lchild->cover=r->cover;
	 if(r->rchild!=NULL)
		 r->rchild->cover=r->cover;
	 r->cover=0;
   }
   mid=(r->i+r->j)/2;
   if(b<=mid)
	   Insert(r->lchild,c,a,b);
   else if(mid<=a)
	   Insert(r->rchild,c,a,b);
   else
   {
	   Insert(r->lchild,c,a,mid);
	   Insert(r->rchild,c,mid,b);
   }
 }
}
/**void Delete(Tree *r,int a,int b)//只有曾经插入过的区间才能删除
{
 int mid;
 if(a<=r->i&&r->j<=b)
	 r->cover--;
 else
 {
   mid=(r->i+r->j)/2;
   if(b<=mid)
	   Delete(r->lchild,a,b);
   else if(mid<=a)
	   Delete(r->rchild,a,b);
   else
   {
	   Delete(r->lchild,a,mid);
	   Delete(r->rchild,mid,b);
   }
 }
}**/
/**int Count(Tree *r)
{
  if(r->cover>0)
	  return (r->j-r->i);
  else if(r->j-r->i==1)
	  return 0;
  else
	  return Count(r->lchild)+Count(r->rchild);
}**/
void sum(Tree *r,int a,int b)
{
  int mid;
  if(r->cover>=1)
	  flag[r->cover]=1;
  else if(b-a>1)
  {
	  mid=(a+b)/2;
	  sum(r->lchild,a,mid);
	  sum(r->rchild,mid,b);
  }
}
int main()
{
 int i,c,x,y,s;Tree *root;
 scanf("%d%d%d",&n,&t,&p);
 root=CreateTree(1,n+1);
 while(p--)
 {
	scanf("\n%c",&ch);
	if(ch=='C')
	{
	  scanf("%d%d%d",&x,&y,&c);
	  if(x>y)
	  {
		i=x;
		x=y;
		y=i;    
	  }
	  Insert(root,c,x,y+1);
	}
	else
	{
	  scanf("%d%d",&x,&y);
	  if(x>y)
	  {
		i=x;
		x=y;
		y=i;    
	  }
	  s=0;
	 for(i=1;i<=t;i++)
	    flag[i]=0;
	 sum(root,x,y+1);
	 for(i=1;i<=t;i++)
		  s+=flag[i];
	  printf("%d\n",s);
	}
 }
 return 0;
}