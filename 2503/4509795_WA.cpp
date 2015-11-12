#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BSTNode
{
    char tree_name1[12],tree_name2[12];
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

void tree_insert(BSTree &t,char name1[],char name2[] )
{
    
    BSTree y=NULL;
    BSTree x=t;
    while(x)
    {	
        
        y=x;
        
        x=strcmp(x->tree_name1,name1)>0?x->lchild:x->rchild;
    }
    x=(BSTree)malloc(sizeof(BSTNode));
    x->lchild=NULL;
    x->rchild=NULL;
    strcpy(x->tree_name1,name1); 
	strcpy(x->tree_name2,name2);
    if(t==NULL)
        t=x;
    else
    {
        
        if(strcmp(y->tree_name1,name1)>0)
            y->lchild=x;
        else
            y->rchild=x;
    } 
}
void tree_search(BSTree &t,char x[])
{
   while(x!=NULL&&strcmp(x,t->tree_name1)!=0)
   {
	   if(strcmp(x,t->tree_name1)<0)
		   t=t->lchild;
	   else
		   t=t->rchild;
   }
   if(t->tree_name2!=NULL)
	   printf("%s\n",t->tree_name2);
   else
	   printf("eh\n");
  
}
int main()
{
    char a[12],b[12];
    BSTree t=NULL;
   
    while(EOF!=scanf("%s %s",a,b));
    {

        tree_insert(t,b,a);
        
    }
	while(EOF!=scanf("%s",a))
	{
		tree_search(t,a);
	}
    return 0;
}