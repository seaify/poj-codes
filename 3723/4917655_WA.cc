#include <stdio.h>
#include <string.h>
int tot,first[51000];
struct node
{
  int x,y,next,value;
};
node edge[51000];
void add(int x,int y,int value)
{
  int temp;
  temp=first[x];
  while(temp!=-1)
  {
	 if(edge[temp].y==y)
	  {
		 edge[temp].value>?=value;
		 return ;
	  }
	temp=edge[temp].next;
  }
  tot++;
  edge[tot].x=x;
  edge[tot].y=y;
  edge[tot].value=value;
  edge[tot].next=first[x];
  first[x]=tot;
}
int main()
{
	int T,M,N,R,i,x,y,value,s;
	scanf("%d",&T);
	while(T--)
	{		
		scanf("%d%d%d",&M,&N,&R);
		for(i=0;i<=M;++i)
		    first[i]=-1;
		tot=0;
		for(i=0;i<R;i++)
		{
			scanf("%d%d%d",&x,&y,&value);
	        add(x,y,value);	            
		}
		s=(M+N)*10000;
		for(i=1;i<=tot;i++)
		     s-=edge[i].value;
		printf("%d\n",s);
	}
	return 0;
} 
