#include<stdio.h>

const int maxn=100010;

int n,tot,result;
int flag[maxn],first[maxn],d[maxn],tree[32*maxn][2],c[maxn][40],path[40];

struct node
{
      int x,y,v,next;
};

 node e[2*maxn];

void add(int x,int y,int v)
{

     ++tot;
     e[tot].x=x;
     e[tot].y=y;
     e[tot].v=v;
     e[tot].next=first[x];
     first[x]=tot;
}

void debug()
{

     for(int i=0;i<n;i++)
               printf("%d ",d[i]);

     printf("\n\n");
}

void dfs(int x,int dis)
{

     int tmp;
     d[x]=dis;
     flag[x]=0;



     for(tmp=first[x];tmp!=-1;tmp=e[tmp].next)
          if(flag[e[tmp].y])
             dfs(e[tmp].y,dis^e[tmp].v);
}

void insert(int p,int x)
{

   //   printf("%d %d %d %d\n",x,p,path[x],tree[p][path[x]]);
      if(tree[p][path[x]]==0)
      {
          ++tot;
          tree[p][path[x]]=tot;
          tree[tot][0]=tree[tot][1]=0;
      }

     // printf("%d\n",tot);

      if(x==30)
          return ;

     // printf("%d %d\n",tree[p][path[x]],x);
      insert(tree[p][path[x]],x+1);
}

void match(int p,int x,int dx,int v)
{
      int cur=1-c[dx][x];

      if(x==31)
      {
          if(v>result)
               result=v;
          return ;
      }

      if(tree[p][cur])
           match(tree[p][cur],x+1,dx,v+(1<<(30-x)));
      else
           match(tree[p][1-cur],x+1,dx,v);

}

int main()
{
      int i,j,x,y,v;

      while(EOF!=scanf("%d",&n))
      {
            for(i=0;i<n;i++)
                first[i]=-1,flag[i]=1;
            tot=0;

            for(i=1;i<n;i++)
            {
                scanf("%d %d %d",&x,&y,&v);
                add(x,y,v);
                add(y,x,v);
            }

            dfs(0,0);

            tot=0;
            tree[0][0]=tree[0][1]=0;

            for(i=0;i<n;i++)
            {

                for(j=30;j>=0;j--)
                    if(d[i]&(1<<j))
                         path[30-j]=c[i][30-j]=1;
                    else
                         path[30-j]=c[i][30-j]=0;


                insert(0,0);
            }

          //  for(i=0;i<=tot;i++)
         //      printf("%d %d\n",tree[i][0],tree[i][1]);

            result=0;
            for(i=0;i<n;i++)
                match(0,0,i,0);


            printf("%d\n",result);
      }

      return 0;
}
