#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,cur,tail,ans,tmp;
int pre[11000];
bool flag[22];

struct tree
{
   tree *node[26];
   int tag,count;
   tree()
   {
       int i;
       count=0; ///表示到它的最大个数 
       tag=-1;
       for(i=0;i<26;i++)
           node[i]=NULL;
   }      
}*root;
       
struct Q 
{
   int size,tag;
   char a[22];
}; 
Q e[11000],f[11000];

int cmp(Q a , Q b)
{
    return a.size<b.size;
} 

void debug()
{
    int i;
	for(i=0;i<n;i++)
		printf("%s\n",e[i].a);
}

void insert(tree *p,char *s,int bj,int dep)///bj=1,注意标记数 
{
     if(!flag[dep])
         s++;
     int c=(*s)-'a';
     if(p->node[c])
        p=p->node[c];
     else
     {
        if(!bj)
           return ;
        p->node[c]=new tree;
        p=p->node[c];
     } 
     
     if(!flag[dep+1])
         s++,dep++;
     
     if(s[1])
        insert(p,s+1,bj,dep+1);
     else if(bj) 
     {
        p->count=tmp,p->tag=cur;
        if(p->count>ans)
           tail=p->tag,ans=p->count;
     }
     else
     {
        if(p->count+1>tmp)            //////ans最大值 
           tmp=p->count+1,pre[cur]=p->tag;
     }
}

void dfs(int x)
{
     if(pre[x]!=-1)
        dfs(pre[x]);
     printf("%s\n",f[x].a); 
}

int main()
{
    int i,j,c;
    char x[22];
    
    n=0;
    while(EOF!=scanf("%s",f[n].a))
    {
         strcpy(x,f[n].a);
	//	 if(x[0]=='1')
	//		 break;
         c=strlen(x);
         sort(x,x+c);
         e[n].size=c;
         e[n].tag=n;
         strcpy(e[n++].a,x);
    }
    sort(e,e+n,cmp);
//	debug();

    root=new tree;
    
    memset(flag,true,sizeof(flag));
    memset(pre,-1,sizeof(pre)); 
    tmp=1; ///注意... 
    ans=0; 
    cur=e[0].tag;
    insert(root,e[0].a,1,0);

    
    for(i=1;i<n;i++)
    {
        cur=e[i].tag;
        tmp=0;
        for(j=0;j<e[i].size;j++)
        {
            flag[j]=false;
            insert(root,e[i].a,0,0);
            flag[j]=true;
        }
        insert(root,e[i].a,1,0);
    }
    
    dfs(tail);
   // scanf("%d",&i);
    
    return 0;
    
} 
