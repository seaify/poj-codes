#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,q,m[101][101],p[101],n,l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	n--;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
		    for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
			    if(k==i||q<m[i][j])
				{
					m[i][j]=q;
				}
			}
		}
    printf("%d\n",m[1][n]);
	return 0;
}
