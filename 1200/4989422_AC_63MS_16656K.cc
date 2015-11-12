#include<stdio.h>
#include<string.h>
const int maxn=16000005;
char a[maxn];
int i,j,k,len,n,NC,sum,tot,value[300];
bool flag[maxn];
void solve()
{
   memset(flag,false,sizeof(flag));
   len=strlen(a);j=0;
   for(i=0;i<len;++i)
   {
     if(value[a[i]]==0)
            value[a[i]]=++j;
     if(j==NC)
        break;
   }
   for(i=0;i<=len-n;++i)
   {
      sum=0;k=1;
      for(j=n+i-1;j>=i;--j)
      {
        sum+=value[a[j]]*k;
        k*=NC;
      }     
      if(flag[sum]==false)
      {
         flag[sum]=true;
         ++tot;
      }                  
   }
   printf("%d\n",tot);  
}
int main()
{
   while(EOF!=scanf("%d%d",&n,&NC))
   {
     scanf("%s",a);
     solve();
   }
}

