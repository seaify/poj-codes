#include<stdio.h>    
#include<string.h>
int f[1000][1000];
int main()
{  
	char a[1000],b[1000];
	int i,j,c,len1,len2;
	while(EOF!=scanf("%s%s",a,b))
	{  
		memset(f,0,sizeof(f));
		len1=strlen(a);
		len2=strlen(b);
	     	c=0;
		for(i=0;i<len1;i++)
		{
			if(a[i]==b[0])
				c=1;
			f[i][0]=c;
		}
		c=0;
		for(i=0;i<len2;i++)
		{
			if(b[i]==a[0])
				c=1;
			f[0][i]=c;
		}   
		for(i=1;i<len1;i++)
			for(j=1;j<len2;j++)
				if(a[i]==b[j])
					f[i][j]=f[i-1][j-1]+1;
				else if(f[i-1][j]>f[i][j-1])
					f[i][j]=f[i-1][j];
				else
					f[i][j]=f[i][j-1];
		printf("%d\n",f[len1-1][len2-1]);
	}
	return 0;


	
 }    


	


	
   