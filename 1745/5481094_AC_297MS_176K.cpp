#include<cstdio>
#include<cstring>
const int INF=100000000;
int N,K,ans,s[110],f[110],a[11000];

int main()
{
	int i,j;
	while(EOF!=scanf("%d %d",&N,&K))
	{
		for(i=1;i<=N;++i)
			scanf("%d",&a[i]);
	    for(i=1;i<K;++i)
			f[i]=s[i]=-1;
		f[0]=0;s[0]=0;
        for(i=1;i<=N;++i)
		{
			for(j=0;j<K;++j)
				if(f[j]!=-1)
				{
				   if(s[(j+a[i]+10000*K)%K]<=f[j]+1)
				       s[(j+a[i]+10000*K)%K]=f[j]+1;

				   if(s[(j-a[i]+10000*K)%K]<=f[j]+1)
					   s[(j-a[i]+10000*K)%K]=f[j]+1;
				
				   
				}
		    for(j=0;j<K;++j)
				f[j]=s[j];
		}
	//	for(i=0;i<K;++i)
	//	   printf("%d\n",s[i]);
		if(s[0]==N)
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}