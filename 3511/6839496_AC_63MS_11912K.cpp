#include<stdio.h>
#include<math.h>

const int maxn=2000000;

int L,U;
int flag[maxn],a[maxn],b[maxn];

void init()
{
	long long i,j,N;
	N=1000000;
	for(i=3;i<=N;i+=2)
		flag[i]=1;  
	for(i=3;i<=1000000;i+=2)
		if(flag[i])
	    {
           j=i*i;
		   while(j<=N)
		   {
			  flag[j]=0;
			  j+=2*i;
		   }
		}
	a[0]=b[0]=0;
	a[1]=b[1]=0;
	a[2]=1;b[2]=1;
    for(i=3;i<=N;i++)
		if((i%2)==1&&flag[i])
		{
            a[i]=a[i-1]+1;
			if((i%4)==1)
				b[i]=b[i-1]+1;
			else
				b[i]=b[i-1];
		}
	    else
		{
			a[i]=a[i-1];
			b[i]=b[i-1];
		}
}

int main()
{
    int i,ls,rs;
	init();
	while(EOF!=scanf("%d %d",&L,&U))
	{
		if(L==-1&&U==-1)
			break;
		if(L<=0)
			ls=0;
		else
			ls=L-1;
		if(U<=0)
			rs=0;
		else
			rs=U;
        printf("%d %d %d %d\n",L,U,a[rs]-a[ls],b[rs]-b[ls]);
	}
	return 0;
}