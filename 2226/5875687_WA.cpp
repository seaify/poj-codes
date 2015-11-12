#include<stdio.h>
#include<string.h>
int n,m,tot,ans;
int first[11000],link[11000],flag[11000];
int a[100][100],b[100][100];
char map[100][100];

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
     printf("%d\n",res);
}
 
int main()
{
    int i,j,r,c;
    while(EOF!=scanf("%d %d",&r,&c))
	{
	   for(i=0;i<r;i++)
		   scanf("%s",map+i);
		  
	   m=0;
	   n=0;
	   for(i=0;i<r;i++)
	   {
		   map[i][c]='.';
		   for(j=0;j<c;j++)
		   {
               if(map[i][j]=='*')
				   a[i][j]=m;
			   if(map[i][j]=='*'&&map[i][j+1]!='*')
				   m++;
		   }
	   }

	   for(j=0;j<c;j++)
	   {
		   map[r][j]='.';
		   for(i=0;i<r;i++)
		   {
			   if(map[i][j]=='*')
				   b[i][j]=n;
			   if(map[i][j]=='*'&&map[i+1][j]!='*')
				   n++;
		   }
	   }

	   for(i=0;i<m;i++)
		   first[i]=-1;
       tot=-1;

	   for(i=0;i<r;i++)
		   for(j=0;j<c;j++)
			   add(a[i][j],b[i][j]);

       solve();
    }
    return 0;
}

