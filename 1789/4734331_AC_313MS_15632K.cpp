#include<stdio.h>
const int maxn=2002;
int a[maxn][maxn],min[maxn];
char map[maxn][10];
int main()
{
	int n,i,j,k,c,sum,temp;
	while(EOF!=scanf("%d",&n)&&n)
	{	
	for(i=1;i<=n;i++)
		scanf("%s",&map[i][1]);
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
		  temp=0;
		  for(k=1;k<=7;k++)
			  if(map[i][k]!=map[j][k])
				  temp++;
		  a[i][j]=a[j][i]=temp;
		}
    for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=0;sum=0;
	for(i=1;i<n;i++)
	{
		c=10;
		for(j=2;j<=n;j++)
			if(min[j]>0&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    sum=sum+c;
		min[k]=0;
		for(j=2;j<=n;j++)
           if(a[k][j]>0&&a[k][j]<min[j])
			   min[j]=a[k][j];
	}
	printf("The highest possible quality is 1/%d.\n",sum);
	}
    return 0;
}

