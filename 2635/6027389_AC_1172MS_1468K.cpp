#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=1000000;
bool flag[maxn+2];
int prime[1000000],top,n,L;
char a[200];


void init()
{
 int i,j,k;
 memset(flag,true,sizeof(flag));//生成素数,
 flag[1]=false;
 k=int(sqrt(1.0*maxn));
 for(i=2;i<=k;i++)
 {
   if(flag[i])
   {
    j=i*i;
    while(j<=maxn)
    {
     flag[j]=false;
     j=j+2*i;
    }
   }
 }
 k=1;
 prime[1]=2;
  for(i=3;i<=maxn;i=i+2)
    if(flag[i])
        prime[++k]=i;
 top=k;
}

void solve()
{
   int i,j,len,sum,tmp,ans;
   len=strlen(a);
   for(i=1;i<=top&&prime[i]<L;i++)
   {
	    sum=0;
        for(j=len-1;j>=0;j-=3)
		{
			tmp=0;
            if(j>=0)
			   tmp+=a[j]-'0';
			if(j-1>=0)
			   tmp+=10*(a[j-1]-'0');
			if(j-2>=0)
			   tmp+=100*(a[j-2]-'0');
		    
			if(j==len-1)
				ans=1;
			else
				ans=(ans*1000)%prime[i];  

			sum=(sum+ans*tmp)%prime[i];
			
		}
		if(sum==0)
		{
			printf("BAD %d\n",prime[i]);
			return ;
		}
   }
   printf("GOOD\n");
}



int main()
{

  init();
  while(EOF!=scanf("%s %d",a,&L))
  {
	  if(a[0]=='0'&&L==0)
		  break;
	  solve();

  }
  return 0;
}

