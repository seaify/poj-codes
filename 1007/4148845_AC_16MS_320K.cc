#include<stdio.h>
#include<string.h>
char a[102][52],h[52];
int len;
int f(char *x)
{
	int a,b,c,i,s;a=0;b=0;c=0;s=0;
	for(i=len-1;i>=0;i--)
		if(x[i]=='A')
			a++;
		else if(x[i]=='C')
		{b++;s+=a;}
		else if(x[i]=='G')
		{c++;s+=a+b;}
        else if(x[i]=='T')
		   s+=a+b+c;		
		return s;
}
int main()
{
	int n,i,j,y[102],t;
	scanf("%d%d",&len,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
        y[i]=f(a[i]);
	}
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(y[j]<y[i])
			{
				t=y[i];
				y[i]=y[j];
				y[j]=t;
				strcpy(h,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],h);
			}
	for(i=1;i<=n;i++)
		printf("%s\n",a[i]);
   return 0;
}