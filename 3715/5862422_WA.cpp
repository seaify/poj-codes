#include<stdio.h>
#include<string.h>
int n,m,tot,size,bad;
int c[210][210];
int p[210],first[210],a[210],link[210],flag[210],ans[210],d[210];

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
    if(flag[x]||!d[x])
        return 0;
    flag[x]=1;
    tmp=first[x];
    while(tmp!=-1)
    {
      y=e[tmp].y;
	  if(!flag[y])
	  {
		flag[y]=1;
        if(d[y]&&(link[y]==-1||dfs(link[y])))
		{
           link[y]=x;
           link[x]=y;
		
           return 1;
		}
      }
      tmp=e[tmp].next;
    }
    return 0;
}

void solve()
{
     int i,j,k,res=0;
     for(i=0;i<n;i++)
         link[i]=-1;

     for(i=1;i<=size;i++)
     {
         j=a[i];
         for(k=0;k<n;k++)
             flag[k]=0;
         if(dfs(j))
             res++;
     }
     j=0;
	 for(i=0;i<n&&j<res;i++)
	 {
		 if(link[i]!=-1)
		 {
			 d[i]=0;
			 for(k=0;k<n;k++)
				 flag[k]=0;
			 if(!dfs(link[i]))
			 {
				 ans[++j]=i;
				 link[link[i]]=-1;
			 }
			 else
				 d[i]=1;
		 }
	 }
     printf("%d ",res);
     for(j=1;j<res;j++)
         printf("%d ",ans[j]);
     if(res)
         printf("%d\n",ans[res]);
}
 
int main()
{
    int T,i,x,y;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d %d",&n,&m);
       size=0;
       for(i=0;i<n;i++)
       {
          scanf("%d",&p[i]);
          if(p[i]==0)
             a[++size]=i;
          first[i]=-1;
          d[i]=1;
       }
       tot=0;
	   memset(c,0,sizeof(c));
       while(m--)
       {
         scanf("%d %d",&x,&y);
         if(p[x]!=p[y]&&!c[x][y])
         {
			c[x][y]=c[y][x]=1;
            add(x,y);
            add(y,x);
         }
       }
       solve();
    }
    return 0;
}

