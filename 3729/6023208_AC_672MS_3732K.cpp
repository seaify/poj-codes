#include"iostream"
#include"algorithm"
#include"cstdio"
#define INF 99999999
using namespace std;
int n,m,k,a[200010],len,array[4][1600010],*rank,*sa,*tsa,*trank,cnt[200010],height[200010];
int lp[200010],rp[200010];
void Da(void)
{
  int i,j;
  memset(cnt,0,sizeof(int)*11000);
  rank=array[1];
  sa=array[0];
  trank=array[3];
  tsa=array[2];
  for(i=0;i<len;i++)   
    cnt[a[i]]++;
  for(i=1;i<=10001;i++)
    cnt[i]+=cnt[i-1];
  for(i=len-1;i>=0;i--)
    sa[--cnt[a[i]]]=i;              
  rank[sa[0]]=0;  
  for(i=1;i<len;i++)
    {
    rank[sa[i]]=rank[sa[i-1]];                
    if (a[sa[i]]!=a[sa[i-1]])
      rank[sa[i]]++;
    }
  for(j=1;j<len&&rank[sa[len-1]]!=len-1;j<<=1)
    {
    for(i=0;i<len;i++)
      cnt[rank[sa[i]]]=i+1;                                        
    for(i=len-1;i>=0;i--)
      if (sa[i]>=j)
        tsa[--cnt[rank[sa[i]-j]]]=sa[i]-j;
    for(i=len-j;i<len;i++)
      tsa[--cnt[rank[i]]]=i;
    trank[tsa[0]]=0;  
    for(i=1;i<len;i++)
      {
      trank[tsa[i]]=trank[tsa[i-1]];
      if (rank[tsa[i]]!=rank[tsa[i-1]]||rank[tsa[i]+j]!=rank[tsa[i-1]+j])
        trank[tsa[i]]++;                
      }        
    swap(tsa,sa);
    swap(trank,rank);  
    }
}
void GetH(void)
{
  int i,j;
  if (rank[0]==0)
    height[rank[0]]=0;
  else
    {
    for(j=0;;j++)
      if (a[j]!=a[sa[rank[0]-1]+j])
        break;
    height[rank[0]]=j;      
    }
  for(i=1;i<len;i++)
    {
    if (rank[i]==0)
      height[rank[i]]=0;
    else
      {
      for(j=max(0,height[rank[i-1]]-1);;j++)
        if (a[i+j]!=a[sa[rank[i]-1]+j])
          break;
      height[rank[i]]=j;      
      }                  
    }     
}
void Getr(void)
{
  int i,j,mt,t,r=0;
  for(i=3;i<len;i++)
    if (sa[i]<n)
      if (sa[i-1]>=n)
        lp[i]=height[i];
      else
        lp[i]=min(height[i],lp[i-1]);
  for(i=len-2;i>=2;i--)
    if (sa[i]<n)
      if (sa[i+1]>=n)
        rp[i]=height[i+1];
      else
        rp[i]=min(height[i+1],rp[i+1]);
  lp[0]=rp[len-1]=0;
  for(i=2;i<len;i++)
    if (sa[i]<n)   
      if (max(lp[i],rp[i])==k)
        r++;      
  printf("%d\n",r);
}
int main()
{
  while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
    for(int i=0;i<n;i++)
      {
      scanf("%d",&a[i]);
      a[i]++;      
      }
    a[n]=0;
    for(int i=0;i<m;i++)
      {
      scanf("%d",&a[i+n+1]);
      a[i+n+1]++;
      }        
    a[n+m+1]=0;
    len=n+m+2;
    Da();
    GetH();
    Getr();
    }  
  return 0;  
}

