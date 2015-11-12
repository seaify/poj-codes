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

void insert(tree *p,char *s)///bj=1,注意标记数 
{
    
     int c=(*s)-'a';

     if(p->node[c])
        p=p->node[c];
	 else
	 {
		p->node[c]=new tree;
		p=p->node[c];
	 }

     if(s[1])
        insert(p,s+1);
     else
		 p->id=cur;

}

int find(tree *p,char *s)
{
	int i,c,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		c=s[i]-'a';
	    if(c<0)
		    return -1;
		if(p->node[c]==NULL)
			return -1;
		p=p->node[c];
	}
	return p->id;
}

void dfs(int x)
{
     if(pre[x]!=-1)
        dfs(pre[x]);
     printf("%s\n",e[x].f); 
}

int main()
{

    int i,j,c,id,last;
    
    n=0;
    while(EOF!=scanf("%s",e[n].f))
    {
	//	 if(e[n].f[0]=='1')
	//		 break;
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
	ans=0;

    for(i=0;i<n;i++)
    {
		cur=i;
		tmp=1;
        if(i==0)
			insert(root,e[i].a);
		else
        for(j=0;j<e[i].size;j++)
        {
			strcpy(x,e[i].a);
            strcpy(&x[j],&x[j+1]);
            id=find(root,x);
			if(id!=-1&&best[id]+1>tmp)
			{
				tmp=best[id]+1;
				last=id;
				pre[cur]=id;
			}
        }
		best[cur]=tmp;
		if(tmp>ans)
		{
			ans=tmp;
			tail=cur;
		}
        insert(root,e[i].a);
    }
    
    dfs(tail);
   //scanf("%d",&i);
///	system("pause");
    
    return 0;
    
} 
