#include<stdio.h>
#include<string.h>
int p[25],f[1100][12];
int m,n,t;
int sum,c,temp,pos;char a[12][12];
int match(int minx,int maxx)
{
	int i,j,max,len1,len2;
	len1=strlen(a[minx]);
	len2=strlen(a[maxx]);
	max=0;
	for(i=0;i<len1;i++)
	{
		sum=0;
		for(j=0;i+j<len1&&j<len2;j++)
		     if(a[minx][i+j]==a[maxx][j])
		        sum++;
		if(max<sum)
		   max=sum;
	}
	for(i=0;i<len2;i++)
	{
		sum=0;
		for(j=0;i+j<len2&&j<len1;j++)
		     if(a[maxx][i+j]==a[minx][j])
		        sum++;
		if(max<sum)
		   max=sum;
	}
	return max;	   
}
int main()
{
int  i,j,k;
p[1]=1;
for(i=1;i<=11;i++)
    p[i+1]=(1<<i);
while(EOF!=scanf("%d",&n))
{
   if(n<=0)
      break;
   for(i=1;i<=n;i++)
      scanf("%s",a[i]);    
   for(i=1;i<=p[n+1]-1;i++)
    {
	 for(k=1;k<=n;k++)
         f[i][k]=0;
     for(j=1;j<=n;j++)
       if(i&p[j])
       {
         t=i-p[j];
         if(t==0)
            {
			 break;
			}
         for(k=1;k<=n;k++)
         {
        if(t&p[k])
          {  
          temp=match(k,j);
		  if(f[t][k]+temp>f[i][j])
             f[i][j]=f[t][k]+temp;
          }    
        }
       }
     }     
     j=0;
     for(i=1;i<=n;i++)
       if(f[p[n+1]-1][i]>j)
		    j=f[p[n+1]-1][i];
     printf("%d\n",j);
    }  
          
return 0;
}
 

