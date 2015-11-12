#include<stdio.h>
int N,m,x,y,k,flag,d[1100],i,j,top;
char ch[5];
struct node
{
  int x,y,value;
};
node edge[200005];
int main()
{
  while(EOF!=scanf("%d%d",&N,&m))
  {
	top=0;
	while(m--)
	{
	  scanf("%s%d%d",ch,&y,&x);
	  if(ch[0]=='P')
	  {
		scanf("%d",&k);
		edge[++top].x=x;
		edge[top].y=y;
		edge[top].value=k;
		edge[++top].x=y;
		edge[top].y=x;
		edge[top].value=-k;
	  }
	  else
	  {
		edge[++top].x=y;
		edge[top].y=x;
		edge[top].value=-1;
	  }
	}
	for(i=1;i<=N;++i)
	    d[i]=0;
	flag=1;m=top;
	for(i=1;i<N&&flag;++i)
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
        printf("Reliable\n");
	else 
	    printf("Unreliable\n");
  }
  return 0;
}
