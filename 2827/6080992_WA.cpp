#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
 
const int maxn=40000;
int p[maxn],num[maxn],d[maxn];
int x[maxn],y[maxn],f[maxn],v[maxn],q[maxn];
int n,m,tot,ans,tmp,top;


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
 //    value=ans;
   /*  while(x!=r)
      {
          q=p[x];
          p[x]=r;
          d[x]=value;
          value-=d[x];
          x=q;
      }      */
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

int check(int v)
{
    int left=1,mid,right=top;
    while(left<=right)
    {
         mid=(left+right)/2;
         if(q[mid]==v)
            return mid;
         else if(v<q[mid])
              right=mid-1;
         else
             left=mid+1;
         
    }
    return 0;
} 

int main()
{   
    
     int i,j,c,d,t;
     
    // freopen("data.txt","r",stdin);
    // freopen("ans.txt","w",stdout); 
     while(EOF!=scanf("%d",&m))
     {
                 
         j=0;              
         for(i=1;i<=m;i++)
         {
             scanf("%d %d %d",&x[i],&y[i],&f[i]);
             
             if(x[i]>y[i])       
             {
                 t=x[i];
                 x[i]=y[i];
                 y[i]=t;      
             }
             
           v[++j]=x[i];
           v[++j]=y[i];
         
         }   
         
         sort(v+1,v+2*m+1);
         
         top=1;
         q[1]=v[1];
         
         for(i=2;i<=2*m;i++)
             if(v[i]!=v[i-1])
                q[++top]=v[i];
         
     //    for(i=1;i<=top;i++)
     //        printf("%d ",q[i]);
      //   printf("\n\n"); 
         
         for(i=1;i<=m;i++)
         {
             x[i]=check(x[i]);
             y[i]=check(y[i]);
      //       printf("%d %d\n",x[i],y[i]); 
         }

    
         
         for(i=0;i<=top;i++)
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

  

   
