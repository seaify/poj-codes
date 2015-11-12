#include<iostream>

struct node
{
    int x,y,next;
};
node e[40000];

int first[20000],flag[20000];
int ans[20000],num[20000];
int n,tot,top;

void add(int x,int y)
{
     e[++tot].x=x;
     e[tot].y=y;
     e[tot].next=first[x];
     first[x]=tot;
}

void dfs(int x)
{
     int tag=1,y,tmp;
     
     flag[x]=0;
     num[x]=1;
     tmp=first[x];
     while(tmp!=-1)
     {
          y=e[tmp].y;
          if(flag[y])
          {
              dfs(y);
              if(num[y]>n/2)
                 tag=0;
              num[x]+=num[y];
          }
          tmp=e[tmp].next;
     }
     
     if(tag&&n-num[x]<=n/2)
          ans[x]=1,top=1;
     
}

int main()
{
    int i,x,y;
    while(EOF!=scanf("%d",&n))
    {
          for(i=1;i<=n;i++)
              num[i]=0,ans[i]=0,first[i]=-1,flag[i]=1;
          tot=0;
          top=0;
          
          for(i=1;i<n;i++)
          {
              scanf("%d %d",&x,&y);
              add(x,y);
              add(y,x);
          }
          
          dfs(1);
          
       /*   for(i=1;i<=n;i++)
              printf("%d ",num[i]);
          printf("\n");*/
          
          if(top)
          {
              for(i=1;i<=n;i++)
                  if(ans[i])
                      printf("%d\n",i);
          }
          else
               printf("NONE\n"); 
    }
    return 0;
}
