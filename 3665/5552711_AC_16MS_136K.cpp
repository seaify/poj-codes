#include<cstdio>
#include<cstring>
int N,T,maxv,ans,res;
int x[1100];

int main()
{
	int i,j,k;
	while(EOF!=scanf("%d %d",&N,&T))
	{
	    for(i=1;i<=N;++i)
			scanf("%d",&x[i]);
		if(N==1)
		{
			for(i=1;i<=T;++i)
				printf("1\n");
			continue;
		}
		for(k=1;k<=T;k++)
		{
			maxv=x[1],j=1;
			for(i=2;i<=N;++i)
				if(x[i]>maxv)
					maxv=x[i],j=i;

		
			printf("%d\n",j);
			if(k==T)
				break;
			ans=x[j]/(N-1);
			for(i=1;i<=N;++i)
				if(j!=i)
					x[i]+=ans;
			res=x[j]%(N-1);
			x[j]=0;
			for(i=1;res;++i)
			{
				if(j!=i)
				{
					x[i]+=1;
					res--;
				}
				if(i>N)
					i=1;
			}
		}

	}
	return 0;
}