#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char tmp[300];

struct node
{
	char c[300];
};
node a[5000],ans[100000];

int n;

int cmp(node a,node b)
{
	return strcmp(a.c,b.c);
}

void solve()
{
	   	int i,j,k,len,first,top,total;
    	len=strlen(a[0].c);
		first=0;
	    for(j=len;j>=1;j--)
		{
			top=0;
			for(i=0;i<=len-j;i++)
			{
				strncpy(tmp,&a[0].c[i],j);
				tmp[j]='\0';

				total=1;

				for(k=1;k<n;k++)
					if(strstr(a[k].c,tmp)!=NULL)
						total++;

				if(total>n/2)
				    strcpy(ans[top++].c,tmp);
					
			}
			if(top)
			{
			      sort(ans,ans+top,cmp);
				  for(k=0;k<top;k++)
					  printf("%s\n",ans[k].c);
				  printf("\n");
				  return ;
				 
			}
		}
		
		printf("?\n\n");
}

int main()
{
    int i;
	
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%s",a[i].c);
		solve();
	}
	return 0;
}