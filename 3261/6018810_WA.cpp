#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
const int MAXN=50010;
char str[MAXN],x[MAXN];
int c[MAXN],h[MAXN],mem[3][MAXN],n,last;
int min[MAXN][18],p[20],i,j,t;
int *SA,*nSA,*nRank,*Rank;
int m,sum,len,mid;

void suffixArray()
{
   int i,k;
   memset(c,0,sizeof(c));
   for(i=0;i<n;i++)
       c[str[i]]++;
   for(i=1;i<200;i++)
       c[i]+=c[i-1];
   SA=mem[0];nSA=mem[1];Rank=mem[2];
   for(i=0;i<n;i++)
      SA[--c[str[i]]]=i;
   for(Rank[SA[0]]=0,i=1;i<n;i++)
   {
       Rank[SA[i]]=Rank[SA[i-1]];
   if(str[SA[i]]!=str[SA[i-1]])
       Rank[SA[i]]++;
   }
   for(k=1;k<n&&Rank[SA[n-1]]<n-1;k*=2)
   {
     for(i=0;i<n;i++)
       c[Rank[SA[i]]]=i;
     for(i=n-1;i>=0;i--)
        if(SA[i]>=k)
           nSA[c[Rank[SA[i]-k]]--]=SA[i]-k;
    for(i=n-k;i<n;i++)
           nSA[c[Rank[i]]]=i;
     nRank=SA,SA=nSA;
     for(nRank[SA[0]]=0,i=1;i<n;i++)
	 {
      nRank[SA[i]]=nRank[SA[i-1]];
      if(Rank[SA[i]]!=Rank[SA[i-1]]||Rank[SA[i]+k]!=Rank[SA[i-1]+k])
        nRank[SA[i]]++;
	 }
     nSA=Rank,Rank=nRank;
   }
}
void init()
{
   int m;
   for(i=0;i<=16;i++)
      p[i]=(1<<i);
  for(i=1;i<=n;i++)
      min[i][0]=h[i-1];
     m=int(log((double)n)/log(2.0));
  for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
   {
    min[j][i]=min[j][i-1]<min[j+p[i-1]][i-1]?min[j][i-1]:min[j+p[i-1]][i-1];
   }
}
int RMQ(int i,int j)////////// rank,SA等数组中实际存储下标从0开始，但查询时以1开始。。 rank[x]=0,故需加上1个偏移量 
{
   int m,a;
   if(i==j)
       return n-i;
   i=Rank[i-1]+1;
   j=Rank[j-1]+1;
   if(i>j)
   {
    a=i;
    i=j;
    j=a;
   }
   i++;
   m=int(log((double)(j-i+1))/log(2.0));
   a=min[i][m]<min[j-p[m]+1][m]?min[i][m]:min[j-p[m]+1][m];
   return a;
}
void lcp()
{
int i,j,k;
for(i=0,k=0;i<n;i++)
{
if(Rank[i]==0)
   h[Rank[i]]=0;
else
{  
   j=SA[Rank[i]-1];
   while(str[i+k]==str[j+k])
    k++;
   h[Rank[i]]=k;
   if(k>0)
    k--;
}
}
}

int count(int flag)
{
    int i=mid,j=0,out=0;
    while(str[i+j]&&x[j]&&str[i+j]==x[j])
         j++;
    
    if(j==len)
         return !flag;
         
   return str[i+j]<x[j];
   
}

void check(int flag)
{
   int left,right,ans;
   left=0;
   right=n-1;
   while(left<=right)
   {
        mid=(left+right)/2;
        if(count(flag))
            right=mid-1,ans=mid;
        else
            left=mid+1;
   } 
   
   printf("%d\n",ans); 
   if(flag)
       sum=ans;
   else
       sum-=ans;
}

void debug()
{
   int i,j;
   printf("SA数组为:\n");
   for(i=0;i<n;i++)
       printf("%d %s\n",SA[i]+1,str+SA[i]);
   printf("\n"); 
    
   printf("h数组为:\n"); 
   for(i=0;i<n;i++)
       printf("%d ",h[i]);
       
   printf("\n");
   
       
   return ;
       
   for(i=1;i<n;i++)
   {
     for(j=1;j<n;j++)
        printf("%d ",RMQ(i,j));
     printf("\n");
   }
}

int main()
{
 while(gets(str))
 {
  n=strlen(str);
  str[n++]=1;
  suffixArray();
  lcp();
  init();
  debug();
 }
  return 0;
}

