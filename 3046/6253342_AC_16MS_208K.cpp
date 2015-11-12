#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int mod=1000000; 

int n,m,S,B;
int a[1100],f[110000],g[110000];

int sum;

int main()
{
	int i,j,x,d,all;
	
	while(EOF!=scanf("%d %d %d %d",&n,&m,&S,&B))
	{
                         
		for(i=1;i<=n;i++)
			a[i]=0;

		for(i=1;i<=m;i++)
		{
		    scanf("%d",&x);
			a[x]++;
        }
        
        for(i=1;i<=m;i++)
            f[i]=0;
        f[0]=1;
			
	    all=0;
	    
	    for(i=1;i<=n;i++)
	    {
            all+=a[i];
            d=a[i];
  
            g[all]=0;
            for(j=all;j>=all-d;j--)
            {
                g[all]+=f[j];
                if(g[all]>=mod)
                   g[all]-=mod;
            }
                
            for(j=all-1;j>=0;j--)
            {
                g[j]=g[j+1]-f[j+1];
                if(g[j]<0)
                   g[j]+=mod;
                if(j-d>=0)
                   g[j]+=f[j-d]; 
                if(g[j]>mod)
                   g[j]-=mod;
            }
            
            for(j=0;j<=all;j++)
                f[j]=g[j];
                         
        }
        
        sum=0;
        for(i=S;i<=B;i++)
            sum=(sum+f[i])%mod;
            
        printf("%d\n",sum);
            
            		
	}
	return 0;
}

