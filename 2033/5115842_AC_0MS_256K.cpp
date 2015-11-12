#include<stdio.h>
#include<string.h>
char a[100000];
int  b[100000],f[100000];
int i,n,cnt;
int main()
{
	while(EOF!=scanf("%s",a+1))
	{
		if(a[1]=='0')
			break;
		n=strlen(a+1);
		for(i=1;i<=n;i++)
			b[i]=a[i]-'0';
		f[0]=1;f[1]=1;
		for(i=2;i<=n;i++)
		{
           f[i]=0;
           if(b[i]!=0)
              f[i]=f[i-1];
           cnt=b[i-1]*10+b[i];
           if(cnt>=10&&cnt<=26)
              f[i]+=f[i-2];
		}
	//	for(i=1;i<n;++i)
      //    printf("%d ",f[i]);
        printf("%d\n",f[n]);
	}
	return 0;
}
