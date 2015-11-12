#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int mod=1000000; 

int n,m,S,B;
int a[1100],f[110000][2];

int sum;

int main()
{
	int i,j,x,d,all,tmp;
	
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
            f[i][0]=0;
        f[0][0]=1;
			
	    all=0;
	    
	    for(i=1;i<=n;i++)
	    {
            all+=a[i];
            d=a[i];
            tmp=i&1;
  
            f[all][tmp]=0;
            for(j=all;j>=all-d;j--)
            {
                f[all][tmp]+=f[j][1-tmp];
                if(f[all][tmp]>=mod)
                   f[all][tmp]-=mod;
            }
                
            for(j=all-1;j>=0;j--)
            {
                f[j][tmp]=f[j+1][tmp]-f[j+1][1-tmp];
                if(f[j][tmp]<0)
                   f[j][tmp]+=mod;
                if(j-d>=0)
                   f[j][tmp]+=f[j-d][1-tmp]; 
                if(f[j][tmp]>mod)
                   f[j][tmp]-=mod;
            }
                         
        }
        
        tmp=(n&1);
        sum=0;
        for(i=S;i<=B;i++)
            sum=(sum+f[i][tmp])%mod;
            
        printf("%d\n",sum);
            
            		
	}
	return 0;
}

