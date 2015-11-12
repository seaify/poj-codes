#include<stdio.h>
#include<string.h>
int n,m,tot,ans;
int first[11000],link[11000],flag[11000];

struct node
{
     int x,y,next;
};
node e[50000];

void add(int x,int y)
{
     ++tot;
     e[tot].x=x;
     e[tot].y=y;
     e[tot].next=first[x];
     first[x]=tot;
}
 
int dfs(int x)
{
    int tmp,y;
    tmp=first[x];
    while(tmp!=-1)
    {
      y=e[tmp].y;
	  if(flag[y]<ans)
	  {
		flag[y]=ans;
        if(link[y]==-1||dfs(link[y]))
		{
           link[y]=x;
           return 1;
		}
      }
      tmp=e[tmp].next;
    }
    return 0;
}

void solve()
{
     int i,res=0;
     for(i=0;i<n;i++)
         link[i]=-1,flag[i]=-1;

     for(i=0;i<m;i++)
     {       
         ans=i;
         if(dfs(i))
             res++;
     }
	 if(res==m)
		 printf("successful hashing\n");
	 else
		 printf("rehash necessary\n");
}
 
int main()
{
    int T,i,x,y;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d %d",&m,&n);
	   tot=0;
	   for(i=0;i<m;i++)
		   first[i]=-1;
	   for(i=0;i<m;i++)
	   {
		   scanf("%d %d",&x,&y);
		   add(i,x);
		   add(i,y);
	   }
       solve();
    }
    return 0;
}
