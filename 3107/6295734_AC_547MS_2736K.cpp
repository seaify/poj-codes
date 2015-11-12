#include<iostream>

int n,tot,result,fuck;
int first[51000],h[51000];

struct node
{
    int x,y,next;
};
node a[110000];

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
     
     if(hh<result)
          result=hh;
     
     h[x]=hh;
    
     return size;
}

int main()
{
    int i,x,y,T;
    
    while(EOF!=scanf("%d",&n))
    {
       for(i=1;i<=n;i++)
           first[i]=-1;
       tot=0;
       for(i=1;i<n;i++)
       {
           scanf("%d %d",&x,&y);
           add(x,y);
           add(y,x);
       } 
       result=200000;
       dfs(1,-1); 
       
       T=0;
       for(i=1;i<=n;i++)
           if(h[i]==result)
           {
               if(T==0)
                   printf("%d",i);
               else
                    printf(" %d",i);
               T++;
                 
           }
        printf("\n");
           
    }
    return 0;
}

