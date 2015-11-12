#include<stdio.h>
int N,m,x,y,k,flag,d[1100],i,j;
char ch[5];
struct node
{
  int x,y,value,tag;
};
node edge[100005];
int main()
{
  while(EOF!=scanf("%d%d",&N,&m))
  {
	for(i=1;i<=m;++i)
    {
	  scanf("%s%d%d",ch,&y,&x);
	  if(ch[0]=='P')
	  {
		scanf("%d",&k);
		edge[i].x=x;
		edge[i].y=y;
		edge[i].value=k;
		edge[i].tag=1;
	  }
	  else
	  {
		edge[i].x=y;
		edge[i].y=x;
		edge[i].value=-1;
		edge[i].tag=0;
	  }
	}
	for(i=1;i<=N;++i)
	    d[i]=0;
	flag=1;
	for(i=1;i<N&&flag;++i)
	{
	   flag=0;
	   for(j=1;j<=m;++j)
	      if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
	          d[edge[j].y]=d[edge[j].x]+edge[j].value,flag=1;
	}
	flag=1;
	for(j=1;j<=m;++j)
	     if(edge[j].tag&&d[edge[j].y]!=d[edge[j].x]+edge[j].value)
	      {
			flag=0;
			break;
		  }
		 else if(!edge[j].tag&&d[edge[j].y]>d[edge[j].x]+edge[j].value)
		 {
			flag=0;
			break;
		 }
    if(flag)
        printf("Reliable\n");
	else 
	    printf("Unreliable\n");
  }
  return 0;
}
