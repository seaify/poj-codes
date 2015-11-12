#include<iostream>

int n,tot,result,fuck;
int first[21000];

struct node
{
    int x,y,next;
};
node a[41000];

void add(int x,int y)
{
    ++tot;
    a[tot].x=x;
    a[tot].y=y;
    a[tot].next=first[x];
    first[x]=tot;     
}

int dfs(int x,int father)
{
     int y,hh=0,tmp,ans,size=1;
     
     for(tmp=first[x];tmp!=-1;tmp=a[tmp].next)
     {
         y=a[tmp].y;
         if(y==father)
            continue;
         ans=dfs(y,x);
         size+=ans;
         if(ans>hh)
            hh=ans;
     }
     if(n-size>hh)
          hh=n-size;
     
     if(hh<result||(hh==result&&x<fuck))
          result=hh,fuck=x;
    
     return size;
}

int main()
{
    int i,x,y,T;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
           first[i]=-1;
       tot=0;
       for(i=1;i<n;i++)
       {
           scanf("%d %d",&x,&y);
           add(x,y);
           add(y,x);
       } 
       fuck=40000;
       result=40000;
       dfs(1,-1); 
       printf("%d %d\n",fuck,result);
    }
    return 0;
}

