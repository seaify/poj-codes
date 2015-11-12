#include<stdio.h>
#include<string.h>
int main()
{
   int i,j,k,R,C,a[102][102],max[102][102];
   scanf("%d%d",&R,&C); 
   memset(max,R*(-50),sizeof(max[1][1]));
   for(i=1;i<=R;i++)
    	for(j=1;j<=C;j++)
		   scanf("%d",&a[i][j]);
    for(i=1;i<=C;i++)
	    max[1][i]=a[1][i];
	for(i=2;i<=R;i++)
		for(j=i;j<=C;j++)
			for(k=i-1;k<j;k++)
				if(max[i][j]<max[i-1][k]+a[i][j])
					max[i][j]=max[i-1][k]+a[i][j];
	k=max[R][R];
	for(i=R+1;i<=C;i++)
		if(max[R][i]>k)
			k=max[R][i];
	printf("%d\n",k);
	return 0;
}

