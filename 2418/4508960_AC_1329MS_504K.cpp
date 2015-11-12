#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BSTNode
{
    char tree_name[100];
    int time;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
int count;
void tree_insert(BSTree &t,char name[])
{
    
    BSTree y=NULL;
    BSTree x=t;
    while(x)
    {	
        if(strcmp(x->tree_name,name)==0)
        {
            x->time++;
            return;
        }
        
        y=x;
        
        x=strcmp(x->tree_name,name)>0?x->lchild:x->rchild;
    }
    
    x=(BSTree)malloc(sizeof(BSTNode));
    x->lchild=NULL;
    x->rchild=NULL;
    x->time=1;
    strcpy(x->tree_name,name);
    if(t==NULL)
        t=x;
    else
    {
        
        if(strcmp(y->tree_name,name)>0)
            y->lchild=x;
        else
            y->rchild=x;
    } 
}
void inorder_walk(BSTree &t)
{
  
    if(t==NULL)
        return;
   inorder_walk(t->lchild);
    printf("%s %.4f\n",t->tree_name,t->time*100.0/count);
    inorder_walk(t->rchild);
    
}
int main()
{
    char name[100];
    BSTree t=NULL;
    count=0;
    while(gets(name))
    {

        tree_insert(t,name);
        count++;
    }
    inorder_walk(t);
    return 1;
}