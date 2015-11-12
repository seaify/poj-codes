#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=500001;

int n,m;
int x[100000],y[100000],ans[100000],c[maxn+10];

struct node
{
    int x,y,id;
};
node e[100000],q[100000];

int cmp(node a,node b)
{
    return a.y<b.y;
}

int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int y)
{
     while(x<=maxn)
     {
          c[x]+=y;
          x+=lowbit(x);
     }
}

int sum(int x)
{
    int t=0;
    while(x>0)
    {
         t+=c[x];
         x-=lowbit(x);
    }
    return t;
}

int main()
{
    int i,j,M,N,T,S;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d %d",&n,&m);
         for(i=0;i<n;i++)
         {
             scanf("%d %d",&x[i],&y[i]);
             x[i]++,y[i]++;
             e[i].x=x[i],e[i].y=y[i];
         }
         sort(x,x+n);
         sort(y,y+n);
         sort(e,e+n,cmp);
       //  printf("yes\n");
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&q[i].x,&q[i].y);
             q[i].x++,q[i].y++;
             q[i].id=i;
         }
         sort(q,q+m,cmp);
         for(i=0;i<=maxn;i++)
              c[i]=0;
         j=0;
         for(i=0;i<m;i++)
         {
             while(j<n&&e[j].y<q[i].y)
             {
                   add(e[j].x,1);
                   j++;
             }
             
             S=sum(q[i].x); ///
             
             M=lower_bound(x,x+n,q[i].x)-x;
             N=lower_bound(y,y+n,q[i].y)-y;
             
             ans[q[i].id]=abs(2*M+2*N-n-4*S);
             
         }
         
         for(i=0;i<m;i++)
             printf("%d\n",ans[i]);
         
         if(T)
             printf("\n");
    }
   // system("pause");
    return 0;
}
