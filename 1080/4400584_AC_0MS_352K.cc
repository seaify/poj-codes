#include<stdio.h>
#include<string.h>
char a[101],b[101];int f[101][101],m,n,i,j;
int map(int a,int b)
{
	if(a==b)
		return 5;
	if(a+b==66)
		return -3;
	if(a+b==68)
		return -4;
	if(a+b==72)
		return -2;
	if(a+b==85)
		return -1;
	if(a+b==132)
		return -1;
	if(a+b==136)
		return -2;
	if(a+b==149)
		return -1;
    if(a+b==138)
		return -3;
	if(a+b==151)
		return -2;
	if(a+b==155)
		return -2;	
	return 0;
}
void dp()
{
	memset(f,0,sizeof(f[1][1]));
	for(i=1;i<=n;i++)
		f[0][i]=f[0][i-1]+map(1,b[i]);
	for(i=1;i<=m;i++)
		f[i][0]=f[i-1][0]+map(a[i],1);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][j-1]+map(a[i],b[j]);
			if(f[i-1][j]+map(a[i],1)>f[i][j])
				f[i][j]=f[i-1][j]+map(a[i],1);
			if(f[i][j-1]+map(1,b[j])>f[i][j])
				f[i][j]=f[i][j-1]+map(1,b[j]);
		}
	printf("%d\n",f[m][n]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&m,a+1);
		scanf("%d%s",&n,b+1);
		dp();
	}
	return 0;
}
