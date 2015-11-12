#include<stdio.h>
#include<string.h>
int w[25][25][25];
int main()
{
    int a,b,c,i,j,k;
    for(i=0;i<=20;i++)
		for(j=0;j<=20;j++)
		{
			w[0][i][j]=1;
			w[i][0][j]=1;
			w[i][j][0]=1;
		}
    for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
         for(k=1;k<=20;k++)
			 if(i<j&&j<k)
				 w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
             else
				 w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
	while(EOF!=scanf("%d%d%d",&a,&b,&c))
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		if(a<=0||b<=0||c<=0)
			k=1;
		else if(a>20||b>20||c>20)
			k=w[20][20][20];
		else
			k=w[a][b][c];
	    	printf("w(%d，%d, %d) = %d\n",a,b,c,k);
	}
	return 0;
}


	