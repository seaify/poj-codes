#include<stdio.h>
#include<algorithm>
using namespace std;

int x1,x2,y1,y2,n,N;
int len[100],c[100],hh[10];

struct node
{
    int a[5];
    int v;
    int sum;
};
node e[200000];

int cmp(node x,node y)
{
     return x.v<y.v;
}

void dfs(int depth,int v,int state) ///使用 
{
     int i;
     if(depth==n+1)
     {
          ++N;
          e[N].sum=0;
          e[N].v=v;
          for(i=n;i>=1;i--)
          {
              e[N].a[i]=state%11;
              e[N].sum+=e[N].a[i];
              state/=11;
          }
          return ;
     }
     for(i=1;i<=c[depth];i++)
     {
          dfs(depth+1,v+i*len[depth],state+i*hh[n-depth]);
          dfs(depth+1,v-i*len[depth],state+i*hh[n-depth]);
     }
}

int solve(int v)
{
    int left=1,right=N,mid,flag=0;
    while(left<=right)
    {
          mid=(left+right)/2;
          if(e[mid].v==v)
          {
              flag=1;
              right=mid-1;
          }
          else if(e[mid].v>v)
              right=mid-1;
          else
              left=mid+1;
    }
    if(flag)
         return left;
    return -1;
}
 
int main()
{
    int i,x,y,tmp,result;
    hh[0]=1;
    for(i=1;i<=5;i++)
        hh[i]=hh[i-1]*11;
    while(EOF!=scanf("%d %d %d %d",&x1,&y1,&x2,&y2))
    {
          scanf("%d",&n);
          for(i=1;i<=n;i++)
             scanf("%d",&len[i]);
          for(i=1;i<=n;i++)
             scanf("%d",&c[i]); 
          N=0;
          dfs(1,0,0);
          sort(e+1,e+N+1,cmp);
          x=solve(x2-x1);
          y=solve(y2-y1);  ///返回存在时的最左位置 
          if(x==-1||y==-1)
          {
               printf("-1\n");
               continue;
          }
          result=1000;
          while(e[x].v==x2-x1)
          {
                while(e[y].v==y2-y1)
                {
                     tmp=0;
                     for(i=1;i<=n;i++)
                        if(e[x].a[i]+e[y].a[i]>c[i])
                                break;
                        else
                              tmp+=e[x].a[i]+e[y].a[i];
                     if(i==n+1&&tmp<result)
                            result=tmp;
                     y++;
                }
                x++;
          } 
          if(result==1000)
                printf("-1\n");
          else
                printf("%d\n",result);
    }
    return 0;
}
