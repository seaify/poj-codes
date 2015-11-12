#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<algorithm>
using namespace std;
 
const int maxn=40000;
int p[maxn],num[maxn],d[maxn];
int x[maxn],y[maxn],f[maxn],v[maxn];
int n,m,tot,ans,tmp;

map < int,int> q;

void Makeset(int x)
{
     p[x]=-1;
     d[x]=0;
     num[x]=1;
} 
 
int Find(int x)//非递归压缩路径
{
     int r=x,q,value;
     ans=0;
     while(p[r]!=-1)//找到根结点
     {       
         ans+=d[r];
         r=p[r];
     }
     value=ans;
     while(x!=r)
      {
          q=p[x];
          p[x]=r;
          d[x]=value;
          value-=d[x];
          x=q;
      }      
     return r;      
}     
 
int Union(int a,int b,int value)
{

    int t1,t2;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
		  return 0;
    p[t2]=t1;
    num[t1]+=num[t2];
    d[t2]=value+tmp-ans;
    return 0;
}

int main()
{   
    
     int i,c,d,t;
     
     while(EOF!=scanf("%d",&m))
     {
                               
         q.clear();
         tot=0;
         for(i=1;i<=m;i++)
         {
             scanf("%d %d %d",&x[i],&y[i],&f[i]);
             
             if(x[i]>y[i])       
             {
                 t=x[i];
                 x[i]=y[i];
                 y[i]=t;      
             }
             
             v[2*i-1]=x[i];
             v[2*i]=y[i];
         
         }   
         
         sort(v+1,v+2*m+1);
        
         for(i=1;i<=2*m;i++)
           if(!q.count(v[i]))
                 q[v[i]]=++tot;
                 
         for(i=1;i<=m;i++)
             x[i]=q[x[i]],y[i]=q[y[i]];
    
         
         for(i=0;i<=tot;i++)
             Makeset(i);
             
         for(i=1;i<=m;i++)
         {
             c=Find(x[i]-1);
             tmp=ans;       ////////第一次的值替换为tmp 
             d=Find(y[i]);
             if(c==d)
             {
                  if(ans-tmp==f[i])
                      printf("Accept\n");
                  else
                      printf("Bug Detected %d\n",ans-tmp);
                      
             }
             else
             {
                 Union(x[i]-1,y[i],f[i]); ////注意.... 
                 printf("Accept\n");
             }
         }       
     } 
     return 0;
 }     

  

   
