#include<stdio.h>
#include<string.h>
#define MAX 120
int x[MAX],y[MAX],max;
char temp[120];
void add()
{   
	int i,minx,maxx;
	for(i=0;i<MAX;i++)
	{
		x[i]+=y[i];
		if(x[i]>=10)
		{
			x[i]-=10;
			x[i+1]++;
		}
	}
//	for(i=0;i<MAX;i++)
//	    printf("%d",x[i]);
  //  printf("\n");
	for(i=0;i<MAX;i++)
	    if(x[i])
	       {
             minx=i;
             break;
           }
    for(i=MAX-1;i>=0;i--)
        if(x[i])
          {
             maxx=i;
             break;
          }
  //  printf("%d %d\n",minx,maxx);
    for(i=minx;i<=maxx;i++)
         printf("%d",x[i]);
    printf("\n");
}
int main()
{   
	int i,top,t,len,max;
	scanf("%d",&t);
	while(t--)
	{ 
	  memset(x,0,sizeof(x));
	  memset(y,0,sizeof(y));
	  memset(temp,0,sizeof(temp));
      scanf("%s",temp);
	  len=strlen(temp);
	  for(i=len-1;i>=0;i--)
		  if(temp[i]!='0')
		  {
			  max=i;
			  break;
		  }
	  top=-1;
	  for(i=0;i<=max;i++)
		  x[++top]=temp[i]-'0';
	  scanf("%s",temp);
	  len=strlen(temp);
	  for(i=len-1;i>=0;i--)
		  if(temp[i]!='0')
		  {
			  max=i;
			  break;
		  }
	  top=-1;
	  for(i=0;i<=max;i++)
		  y[++top]=temp[i]-'0';
	  add();
	}
	return 0;
}
