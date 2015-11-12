#include<stdio.h>
#include<string.h>
long x[21][21][21];
long w(int a,int b,int c )
{
	
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return w(20,20,20);
	if(x[a][b][c]>0)
		return x[a][b][c];
	if(a<b&&b<c)
	{
		x[a][b][c]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c) ;
	    return x[a][b][c];
	}
	else
	{
		x[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) ;
		return x[a][b][c];
	}
}


int main()
{
    int a,b,c,k;
	memset(x,0,sizeof(x));
	while(EOF!=scanf("%d%d%d",&a,&b,&c))
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		k=w(a,b,c);
		printf("w(%d，%d, %d) = %ld\n",a,b,c,k);
	}
	return 0;
}
