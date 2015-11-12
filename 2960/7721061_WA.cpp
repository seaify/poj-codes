#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int g[11000],t[200],h[200];
char ch[200];

void init()
{
	int i,j,k,c;
	 
	for(i=0;i<=10000;i++)
	{
		for(j=0,k=0;j<n;j++)
		   if(i-t[j]>=0)   //h互异,递增 
		   {
				h[k]=g[i-t[j]];
				++k;
		   }
	
	   
	   for(c=0;c<k;c++)
	   {
	       if(h[c]!=c)
		   {
	            g[i]=c;
				break;
		   }
	   }

	   if(c==k)
		   g[i]=c;
		    
	}
	
	
}

void debug()
{
	int i;
	printf("\n");
	for(i=0;i<=10;i++)
	    printf("%d ",g[i]);
	printf("\n\n");
}

int main()
{
	int i,c,m,x,s;
	
	while(EOF!=scanf("%d",&n)&&n)
	{
		  for(i=0;i<n;i++)
		      scanf("%d",&t[i]);
		
		  sort(t,t+n);
		      
		  //计算g[x] 
		  
		  init();
		  
	//	  debug();
		
		  scanf("%d",&m);
		  for(i=0;i<m;i++)
		  {
			   scanf("%d",&c);
			   s=0;
			   while(c--)
			   {
					scanf("%d",&x);
					s^=g[x];
			   }
			   if(s!=0)
			        ch[i]='W';
			   else
			        ch[i]='L';
		  }
		  
		  ch[m]='\0';
		  
		  printf("%s\n",ch);
	}

	return 0;
}
