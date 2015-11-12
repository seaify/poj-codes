#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BSTNode
{
    char tree_name1[12],tree_name2[12];
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
 BSTree t=NULL;

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
//void inorder_walk(BSTree &t)
//{
  
   // if(t==NULL)
    //    return;
  // inorder_walk(t->lchild);
 //printf("%s %s\n",t->tree_name1,t->tree_name2);
//    inorder_walk(t->rchild);
    
//}         
void tree_search(char key[])
{

	BSTree x=t;

    while(x!=NULL&&strcmp(x->tree_name1 ,key)!=0)
    {
        if(strcmp(key,x->tree_name1 )<0)
            x=x->lchild;
        else if(strcmp(key,x->tree_name1 )>0)
            x=x->rchild;
     
    }
   if(x!=NULL)
	   printf("%s\n",x->tree_name2);
   else
	   printf("eh\n");
  
}
int main()
{
    char a[12],b[12],str[100];
   
   
   while( gets(str) ) 
    {  
	   if ( str[0] == '\0')break; 
	   sscanf(str, "%s %s", a,b);  
        tree_insert(t,b,a);    
    }
   //inorder_walk(t);
	while(EOF!=scanf("%s",a))
	{
		tree_search(a);
	}
    return 0;
}