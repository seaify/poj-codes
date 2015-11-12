#include<stdio.h>
#include<string.h>
char left[3][7],right[3][7],result[3][5];
int l(char x)
{
	int i;
	for(i=0;i<3;i++)
		switch(result[i][0])
	{
		case 'u' :if(strchr(right[i],x)==NULL)
					  return 0;break;
		case 'e' :if(strchr(right[i],x)!=NULL||strchr(left[i],x)!=NULL)
					  return 0;break;
		case 'd' :if(strchr(left[i],x)==NULL)
					  return 0;break;
	}return 1;
}
int h(char x)
{
	int i;
	for(i=0;i<3;i++)
		switch(result[i][0])
	{
		case 'u' :if(strchr(left[i],x)==NULL)
					  return 0;break;
		case 'e' :if(strchr(right[i],x)!=NULL||strchr(left[i],x)!=NULL)
					  return 0;break;
		case 'd' :if(strchr(right[i],x)==NULL)
					  return 0;break;
	}
	return 1;
}
int main()
{
	int i,n;char c;
	scanf("%d",&n);
	while(n--)
	{
		for(i=0;i<3;i++)
			scanf("%s%s%s",left[i],right[i],result[i]);
		for(c='A';c<='L';c++)
		{
			if(l(c))
			{
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
			if(h(c))
			{
				printf("%c is the counterfeit coin and it is heavy.\n",c);
			}
		}
	}
	return 0;
}
