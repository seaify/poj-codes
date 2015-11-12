#include<stdio.h>
int N,m,si,ni,k,flag,d[110],i,j;
char ch[5];
struct node
{
  int x,y,value;
};
node edge[1000];
int main()
{
  while(EOF!=scanf("%d",&N))
  {
   if(N==0)
      break;
  scanf("%d",&m); 
  for(i=1;i<=m;++i)
  {
	scanf("%d%d%s%d",&si,&ni,ch,&k);
	if(ch[0]=='g')
	{
	  edge[i].x=si+ni;
	  edge[i].y=si-1;
	  edge[i].value=-(k+1);
	}
	else
	{
	  edge[i].x=si-1;
	  edge[i].y=si+ni;
	  edge[i].value=k-1;
	}
  }
	for(i=0;i<=N;++i)
	    d[i]=0;
	flag=1;
	for(i=1;i<=N&&flag;++i)
	{
	   flag=0;
	   for(j=1;j<=m;++j)
	      if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
	          d[edge[j].y]=d[edge[j].x]+edge[j].value,flag=1;
	}
	flag=1;
	for(j=1;j<=m;++j)
	     if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
	      {
			flag=0;
			break;
		  }
	if(flag)
	    printf("lamentable kingdom\n");
	else
	    printf("successful conspiracy \n");
  }
  return 0;
}
