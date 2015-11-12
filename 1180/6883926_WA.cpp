#include<stdio.h>

typedef long long Long;
#define size r-l+1

Long l,r,N,S;
Long T[20000],F[20000],sumT[20000],sumF[20000],a[20000],q[40000];

int main()
{
	Long i,j,x,y,m,n;
	while(EOF!=scanf("%lld",&N))
	{
		scanf("%lld",&S);
		for(i=1;i<=N;i++)
			scanf("%lld %lld",&T[i],&F[i]);

		sumT[N+1]=0,sumF[N+1]=0;

        for(i=N;i>=1;i--)
			sumT[i]=sumT[i+1]+T[i],sumF[i]=sumF[i+1]+F[i];

		a[N]=(S+sumT[N])*sumF[N];
		l=1,r=1,q[1]=N;

		for(i=N-1;i>=1;i--)
		{
			while(size>=2)
			{
				if((a[q[l]]-a[q[l+1]])>sumF[i]*(sumT[q[l]]-sumT[q[l+1]]))
					l++;
				else
					break;
			}
			j=q[l];
			a[i]=a[j]+sumF[i]*(S+sumT[i]-sumT[j]);

			while(size>=2)
			{
				x=a[q[r-1]]-a[q[r]];
				y=sumT[q[r-1]]-sumT[q[r]];
				m=a[q[r]]-a[i];
				n=sumT[q[r]]-sumT[i];
                if(x*n<=y*m)
					r--;
				else
					break;
			}
			q[++r]=i;

		}
		printf("%lld\n",a[1]);

	}
	return 0;
}