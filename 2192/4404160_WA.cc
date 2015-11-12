#include <stdio.h>
#include <string.h>
char x[500],y[500],z[1000];int f[2][1000];
int dp()
{ 
	int m,n,i,j,t;
    m=strlen(x+1);n=strlen(z+1);
	memset(f,0,sizeof(f));
	for(i=1,t=1;i<=m;i++)
	  {
		for(j=1;j<=n;j++)
		{
			if(x[i]==z[j])
				f[t][j]=f[1-t][j-1]+1;
			if(f[1-t][j]>f[t][j])
				f[t][j]=f[1-t][j];
			if(f[t][j-1]>f[t][j])
				f[t][j]=f[t][j-1];
		}	
		memset(f[1-t],0,m*sizeof(f[1][1]));
			t=1-t;
	}
	if(m==f[1-t][n])
     	return 0;
	return 1;
}
int main()
{
	int t=1,n;
    while(EOF!=scanf("%d",&n))
	{
		while(n--)
		{
	  scanf("%s%s%s",x+1,y+1,z+1);
	  if(dp())
	  {
		 printf("Data set %d: no\n",t++);
         continue;
	  }
	  strcpy(x+1,y+1);
	  if(dp())
	  { 
	  printf("Data set %d: no\n",t++);
	  continue;
	  }
      printf("Data set %d: yes\n",t++);		 
	} 
	}
	return 0;
}
