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

void dfs(int depth,int v,int state,int t) ///使用 
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
	 dfs(depth+1,v,state,t); ///
     for(i=1;i<=c[depth];i++)
     {
          dfs(depth+1,v+i*len[depth],state+i*hh[n-depth],t);
          if(t)
			  dfs(depth+1,v-i*len[depth],state+i*hh[n-depth],t);
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

void debug(int x)
{
     int i;
     for(i=1;i<=n;i++)
         printf("%d %d\n",len[i],e[x].a[i]);
     printf("\n"); 
}
 
int main()
{
    int i,j,k,x,y,tmp,result;
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
          if(x1==x2&&y1==y2)
          {
               printf("0\n");
               continue;
          }

          N=0;
		  if(x1==x2||y1==y2)
			  dfs(1,0,0,0);
		  else
              dfs(1,0,0,1);
          sort(e+1,e+N+1,cmp);
          x=solve(x2-x1);
          y=solve(y2-y1);  ///返回存在时的最左位置 
         // printf("%d %d\n",x,y);
          if(x==-1||y==-1)
          {
               printf("-1\n");
               continue;
          }
         // printf("%d %d\n",x,y);
          
          result=1000;
          for(i=x;e[i].v==x2-x1;i++)
          {
                for(j=y;e[j].v==y2-y1;j++)
                {
                   
                     for(k=1;k<=n;k++)
                        if(e[i].a[k]+e[j].a[k]>c[k])
                                break;
                     if(k==n+1&&e[i].sum+e[j].sum<result)
                            result=e[i].sum+e[j].sum;
                }
          } 
          if(result==1000)
                printf("-1\n");
          else
                printf("%d\n",result);
    }
    return 0;
}
