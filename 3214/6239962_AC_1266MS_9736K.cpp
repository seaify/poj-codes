#include<iostream>

int n,h,tot,big,top;
int q[1100000],a[1100000],c[1100000];

void dfs(int x)
{
    if(x>n)
       return ;
       
    dfs(x<<1);
    
    if((x<<1)+1<=n)
       big++; 
    
    dfs((x<<1)+1);
    
    c[++tot]=a[x]-big;
    
}

int main()
{
    int i,v,left,mid,right;
    while(EOF!=scanf("%d",&h))
    {
          n=0;
          while(EOF!=scanf("%d",&v))
               a[++n]=v;    
          tot=0;
          big=0;
                   
          dfs(1);
          
          top=1;
          q[1]=c[1];
          for(i=2;i<=n;i++)
             if(c[i]>=q[top])
                q[++top]=c[i];
             else
             {
                 left=1;
                 right=top;
                 while(left<=right)
                 {
                       mid=(left+right)>>1;
                       if(q[mid]<=c[i])
                            left=mid+1;
                       else
                            right=mid-1;
                 }
                 q[left]=c[i];
             }
          
           printf("%d\n",n-top); 
          
    }
}
