#include<iostream>

int n,m,R,tot;
int first[1000010],result[1000010];

struct node
{
    int x,y,value,next;
};
node a[2000];

void add(int x,int y,int value)
{
     a[++tot].x=x;
     a[tot].y=y;
     a[tot].value=value;
     a[tot].next=first[x];
     first[x]=tot;
}


int main()
{
    int i,x,y,value,tmp,ans;
    while(EOF!=scanf("%d %d %d",&n,&m,&R))
    {
         for(i=0;i<=n;i++)
             first[i]=-1;
         tot=0;
         for(i=1;i<=m;i++)
         {
            scanf("%d %d %d",&x,&y,&value);
            add(y,x,value);
         }
         result[0]=0;   
         for(i=1;i<=n;i++)    ////枚举终止时间
         {
              result[i]=result[i-1];
              tmp=first[i];
              while(tmp!=-1)
              {
                  y=a[tmp].y;
                  value=a[tmp].value;
                  if(y-R<=0)
                       ans=0;
                  else
                       ans=result[y-R];
                  if(ans+value>result[i])
                       result[i]=ans+value;
                  tmp=a[tmp].next;
              }                
         } 
         
         printf("%d\n",result[n]);
         
    }
    return 0;
}

