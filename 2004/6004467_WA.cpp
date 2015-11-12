#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,cur,tail,ans,tmp;
int pre[11000],best[11000];
char x[22];

struct tree
{
   tree *node[26];
   int id;
   tree()
   {
       int i;
       id=-1; ///表示到它的最大个数 
       
       for(i=0;i<26;i++)
           node[i]=NULL;
   }      
}*root;
       
struct Q 
{
   int size,tag;
   char a[22],f[22];
}; 
Q e[11000];

int cmp(Q a , Q b)
{
    return a.size<b.size;
} 

void debug()
{
    int i;
	printf("%d\n",n);
	for(i=0;i<n;i++)
		printf("%s\n",e[i].a);
}

void insert(tree *p,char *s,int bj)///bj=1,注意标记数 
{
    
     int c=(*s)-'a';
	 if(c<0)
		 return ;
     if(p->node[c])
        p=p->node[c];
     else
     {
        if(!bj)
           return ;
        p->node[c]=new tree;
        p=p->node[c];
     } 
     
     
     if(s[1])
        insert(p,s+1,bj);
     else if(bj) 
     {
        if(ans<best[cur])
		{
			ans=best[cur];
			tail=cur;			
		}
		p->id=cur;
     }
     else
     {
        if(best[p->id]+1>best[cur])
		{
			best[cur]=best[p->id]+1;
		    pre[cur]=p->id;
		}
     }
}

void dfs(int x)
{
     if(pre[x]!=-1)
        dfs(pre[x]);
     printf("%s\n",e[x].f); 
}

int main()
{

    int i,j,c;
    
    
    n=0;
    while(EOF!=scanf("%s",e[n].f))
    {
         
		 //if(e[n].f[0]=='1')
		  //    break;
		 strcpy(e[n].a,e[n].f);
         c=strlen(e[n].a);
         sort(e[n].a,e[n].a+c);
         e[n].size=c;
		 n++;
      
    }

    sort(e,e+n,cmp);
	//debug();

    root=new tree;
    
    memset(best,0,sizeof(best));
	memset(pre,-1,sizeof(pre));
	best[0]=1;
	ans=0;

    for(i=0;i<n;i++)
    {
		cur=i;
        if(i==0)
			insert(root,e[i].a,1);
		else
        for(j=0;j<e[i].size;j++)
        {
			strcpy(x,e[i].a);
            strcpy(&x[j],&x[j+1]);
            insert(root,x,0);
        }
        insert(root,e[i].a,1);
    }
    
    dfs(tail);
   //scanf("%d",&i);
///	system("pause");
    
    return 0;
    
} 
