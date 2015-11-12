#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[1010],r[1010];
int m,n,u[1100],g[1100],out[1100],flag[1100];

void init()
{
	int i,j,c,s,x,y;
	
	for(i=0;i<n;i++)
		   flag[i]=-1,out[i]=0,u[i]=1,v[i].clear(),r[i].clear();
				 
    for(i=0;i<n;i++)
	{
		   scanf("%d",&c);
		   out[i]=c;
		 
		   while(c--)
		   {
				scanf("%d",&x);
				v[i].push_back(x);
				r[x].push_back(i);
		   }
	}
	
	s=0;

	while(1)
	{
		
	    for(i=0;i<n;i++,s++)
	       if(u[i]==1&&out[i]==0)
	       {
			    for(j=0;j<v[i].size();j++)
			    {
					    y=v[i][j];
					    
					    flag[g[y]]=s;
				}
				
				
				for(j=0;j<n;j++)
				    if(flag[j]<s)
					{
				        g[i]=j;
						break;
					}
				
				for(j=0;j<r[i].size();j++)
				{
					    y=r[i][j];
					    out[y]--;
				}

				u[i]=0;
			
		   }
		   
		for(i=0;i<n;i++)
			if(u[i]!=0)
				break;

		if(i==n)
			  return ;
	}
}

int main()
{
	int x,s;
	
	while(EOF!=scanf("%d",&n))
	{
		  
		  //计算g[x]
		  
		  init(); 
		  
		  while(1)
		  {
				scanf("%d",&m);
				
				if(m==0)		
				    break;
				
				
				s=0;
				while(m--)
				{
					scanf("%d",&x);
					s^=g[x];
				}
				
				if(s!=0)
				     printf("WIN\n");
				else
				     printf("LOSE\n");
				
		  }
		  
	}
	return 0;
}
