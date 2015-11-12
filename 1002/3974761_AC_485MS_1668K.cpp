#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[]="22233344455566677778889999";
char str[80],c[100001][15];
int cmp(const void *a,const void *b)
{
     return(strcmp((char *)a,(char *)b));
}


void st(int n)
{
	int j,k;
	j=k=-1;
	while(k<8)
	{
		j++;
		if(str[j]=='-')
			continue;
		k++;
		if(k==3)
		{
			c[n][k]='-';
			k++;
		}
		if(str[j]>='A'&&str[j]<='Z')
		{
			c[n][k]=map[str[j]-'A'];
			continue;
		}
	 c[n][k]=str[j];
	}
   

}
int main()
{
	int n,i,j,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str);
		st(i);
	}
	qsort(c,n,sizeof(c[0]),cmp);
     m=1;i=0;
	while(i<n)
	{
        j=i;
		i++;
		while(i<n&&strcmp(c[i],c[j])==0)
			i++;
		if(i-j>1)
		{
			printf("%s %d\n",c[j],i-j);
			 m=0;
		}
	}
	if(m)
		printf("No duplicates.\n");
	return 0;
}

	
   
