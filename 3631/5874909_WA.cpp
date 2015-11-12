#include<stdio.h>
#include<stdlib.h>
const int maxn=11000;
int p[maxn],num[maxn];
int n,m,flag;

void Makeset(int x)
{
     p[x]=-1;
     num[x]=1;
} 
 
int Find(int x)//非递归压缩路径
{
     int r=x;
     while(p[r]!=-1)//找到根结点
         r=p[r];
     while(x!=r)
      {
          int q=p[x];
          p[x]=r;
          x=q;
      }
    return r;      
}   
  
int Union(int a,int b)
{

    int t1,t2,ans;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
    {
        num[t1]--;
        if(num[t1]<0)
           flag=0;
        return 0;
    }
    ans=num[t1]+num[t2]-1;
    if(num[t2]<=num[t1])
    {
        p[t2]=t1;
        num[t1]=ans;
    }
    else
    {
        p[t1]=t2;
        num[t2]=ans;
    }
    if(ans<0)
         flag=0;
    return 0;
}

int main()
 {   
     int T,i,x,y;
     scanf("%d",&T);
     while(EOF!=scanf("%d %d",&m,&n))
     {
          for(i=0;i<n;i++)
               Makeset(i);
          flag=1;
          for(i=1;i<=m&&flag;i++)
          {
               scanf("%d %d",&x,&y);
               Union(x,y);     
          }
          if(flag)
                printf("successful hashing\n");
          else
                printf("rehash necessary\n");
     }
     return 0;
 }     

  

   
