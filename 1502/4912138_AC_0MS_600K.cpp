#include<stdio.h>
#include<string.h>
const int maxn=1010;
const int INF=1000000;
int map[maxn][maxn],d[maxn],i,j,k,sum,temp,min,x,n,last;
char a[20];
bool flag[maxn];
void input()
{
    scanf("%d",&n);
	for(i=1;i<=n;++i)
	      map[i][i]=0;
    for(i=2;i<=n;++i)
       for(j=1;j<i;++j)
        {
		   scanf("%s",a);
		   if(a[0]=='x')
		       map[i][j]=map[j][i]=INF;
		   else
		    {
			   k=strlen(a);sum=0;temp=1;
			   while(k--)
			   {
			     sum+=(a[k]-'0')*temp;
			     temp*=10;
			   }
			   map[i][j]=map[j][i]=sum;
			}
		}
}
int main()
{
    input();
	for(i=2;i<=n;i++)
	{
	 flag[i]=false;
	 d[i]=map[1][i];
	}
	for(i=1;i<n;i++)
	{
	  min=INF;
	  for(j=2;j<=n;j++)
		  if(!flag[j]&&d[j]<min)
		  {
			  x=j;
			  min=d[j];
		  }
	 flag[x]=true;
	 for(j=2;j<=n;j++)
		 if(!flag[j]&&d[j]>d[x]+map[x][j])
		 { 
			 d[j]=d[x]+map[x][j];
		 }	
	} 
	last=0;
	for(i=2;i<=n;++i)
	   if(d[i]>last)
	       last=d[i]; 
	printf("%d\n",last);
    return 0;
}
