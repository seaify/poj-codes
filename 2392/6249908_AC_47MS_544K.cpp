#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct node
{
	int an,cn,limit;
}s[420];

bool a[42000];
int b[42000][2];
int n,m,sum;

int cmp(node a,node b)
{
    return (a.limit-a.an)<(b.limit-b.an);
}

int main()
{
	int i,j,all;
	
	while(EOF!=scanf("%d",&n))
	{
                              
		m=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",&s[i].an,&s[i].limit,&s[i].cn);
			if(s[i].limit>m)
			     m=s[i].limit;
        }
        
        memset(b,-1,sizeof(b));
			
  	    for(i=1;i<=m;i++)
			a[i]=false;
		a[0]=true;
	
		sort(s+1,s+n+1,cmp);
		
	    all=0;
	    
		for(j=1;j<=n;j++)
		{
			all+=s[j].an*s[j].cn;
			
			for(i=s[j].an;i<=s[j].limit&&i<=all;i++)
			{
				if(a[i])
					continue;
				int temp=i-s[j].an;
				if(temp<0)
					continue;
				if(!a[temp])
					continue;
				if(b[temp][0]==j&&b[temp][1]>=s[j].cn)
					continue;
				b[i][0]=j;
				if(b[temp][0]==j)
					b[i][1]=b[temp][1]+1;
				else
					b[i][1]=1;
					
	            a[i]=true;
	
			}
		}
		
		for(i=m;i>=0;i--)
		    if(a[i])
		    {
                 printf("%d\n",i);
                 break;
            }
	
	}
	return 0;
}
