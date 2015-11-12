#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,begin,end,c,max,minx,maxx;
	int flag[100000];
	memset(flag,0,sizeof(flag));
	for(j=1;j<=10000;j++)
	{		
		c=1;i=j;
		while(i!=1)
		{
		  if(i%2==0)
			 i=i/2;
		  else 
			 i=3*i+1;
		  c++;
		}
		flag[j]=c;
	}
	while(EOF!=scanf("%d%d",&begin,&end))
	{
		minx=begin<end?begin:end;
        maxx=begin+end-minx;
		for(i=minx;i<=maxx;i++)
			if(i==minx||flag[i]>max)
				max=flag[i];
		printf("%d %d %d\n",begin,end,max);
	}
	return 0;
}