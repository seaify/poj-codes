#include<iostream>

int n,ans;
int f[2100][2100],a[2100];

int main()
{
    int i,j,k,t;

    while(EOF!=scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
			scanf("%d",&a[i]);

		t=-1;

		for(k=n;k>=1;k--)
		{
			t++;
			for(i=1;i+k-1<=n;i++)
			{
				j=i+k-1;
				f[i][j]=0;
				if(j+1<=n&&f[i][j+1]+t*a[j+1]>f[i][j])
					f[i][j]=f[i][j+1]+t*a[j+1];
				if(i-1>=1&&f[i-1][j]+t*a[i-1]>f[i][j])
					f[i][j]=f[i-1][j]+t*a[i-1];
			}
		}

		ans=0;

		for(i=1;i<=n;i++)
			if(f[i][i]+n*a[i]>ans)
				ans=f[i][i]+n*a[i];

		printf("%d\n",ans);
    } 
	return 0;
}

