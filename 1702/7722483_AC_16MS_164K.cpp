#include<stdio.h>
#include<algorithm>
using namespace std;

int a[30],p[30],left[30],right[30];

void output(int x[30],int m)
{
	int i;
	
	if(m==0)
	{
	      printf("empty");
	      return ;
	}
	
	for(i=1;i<m;i++)
	      printf("%d,",x[i]);
	printf("%d",x[m]);
	      
}

void solve(int n)
{
	int i,m,s;
	
	for(i=0;i<20;i++)
	{
		  a[i]=n%3;
		  n/=3;
	}
	
	m=0,n=0,s=0;
	
	for(i=0;i<20;i++)
	{

		  a[i]=a[i]+s;
		  s=a[i]/3;  //新的进位.
		  a[i]%=3;

		  if(a[i]==2)
		  {
			    left[++m]=p[i];
			    a[i]=0;
			    //a[i+1]=(a[i+1]+1)%3;
				++s;  //进位.
		  }
		  else if(a[i]==1)
		        right[++n]=p[i];
	}
	
	output(left,m);
	printf(" ");
	output(right,n);
	printf("\n");
}

int main()
{
    int i,n,T;

    p[0]=1;
    for(i=1;i<=22;i++)
          p[i]=3*p[i-1];      
   
    scanf("%d",&T);
    
    while(T--)
    {
		  scanf("%d",&n);
		  solve(n);
	}
   
    return 0;
}
