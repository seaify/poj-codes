#include<stdio.h>
#include<string.h>
bool flag[20000];
int count,top,p[20000],prime[10000];
int test()
{
  int last,i;
  if(count==0&&top==0)
	  return 1;
  if(count!=top-1)
	  return 0;
  last=0;
  for(i=1;i<=top;i++)
      if(p[prime[i]]>1)
		  return 0;
	  else if(p[prime[i]]==0)
		  ++last;
  if(last==1)
	  return 1;
  else
	  return 0;
}
int main()
{
  int time=0,a,b;
  memset(flag,false,sizeof(flag));
  memset(p,0,sizeof(p));
  top=0;count=0;
  while(EOF!=scanf("%d%d",&a,&b))
  {
	if(a==-1&&b==-1)
		break;
	if(a==0&&b==0)
	{
	   if(test())
		   printf("Case %d is a tree.\n",++time);
	   else
	       printf("Case %d is not a tree.\n",++time);
	   count=0;//边的计数
	   top=0;//点的计数
	   memset(flag,false,sizeof(flag));
	   memset(p,0,sizeof(p));
	   continue;
	}
	if(!flag[a])//a没出现过
	{
	   flag[a]=true;
	   prime[++top]=a;
	}
	if(!flag[b])
	{
	   flag[b]=true;
	   prime[++top]=b;
	}
	++p[b];
	++count;
  }
  return 0;
}