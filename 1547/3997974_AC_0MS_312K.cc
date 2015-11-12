#include<stdio.h>
int main()
{  
	int a,b,c,v[10],n,i;char s[10][10];double av;
	while(EOF!=scanf("%d",&n)&&n!=-1)
	{   av=0;
		for(i=1;i<=n;i++)
		{    
			scanf("%d%d%d",&a,&b,&c);
			    v[i]=a*b*c;
				scanf("%s",s[i]);
				av+=v[i];
		}
		av/=n;
		for(i=1;i<=n;i++)
			if(v[i]>av)
				printf("%s ",s[i]);
		printf("took clay from ");
		for(i=1;i<=n;i++)
			if(v[i]<av)
			printf("%s.\n",s[i]);
	}
	return 0;
}



		
			



