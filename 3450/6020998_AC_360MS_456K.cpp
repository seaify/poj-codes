#include<stdio.h>
#include<string.h>
char tmp[300],ans[300];

struct node
{
	char c[300];
};
node a[5000];

int n;


int main()
{
	int i,j,k,len,flag,first;
	
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%s",a[i].c);

		len=strlen(a[0].c);
		first=0;
	    for(j=len;j>=1;j--)
		{
			first=0;
			for(i=0;i<=len-j;i++)
			{
				strncpy(tmp,&a[0].c[i],j);
				tmp[j]='\0';

				flag=1;

				for(k=1;k<n;k++)
					if(strstr(a[k].c,tmp)==NULL)
					{
						flag=0;
						break;
					}

			   if(flag)
			   {
				   if(first==0||strcmp(tmp,ans)<0)
				   {
					   first++;
					   strcpy(ans,tmp);
				   }
			   }
			}
			if(first)
			{
			       printf("%s\n",ans);
				   break;
			}
		}
		if(first==0)
		    printf("IDENTITY LOST\n");
	}
	return 0;
}