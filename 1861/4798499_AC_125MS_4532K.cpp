#include<stdio.h>
const int INF=1100000;
int a[1100][1100],min[1100],p[1100];
bool flag[1100];
struct Node
{
  int x,y;
};
Node  node[1100]; 
int main()
{
	int m,n,i,j,k,c,max,top;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
	    flag[i]=true;
		for(j=1;j<=n;j++)
			a[i][j]=INF;
	}
    while(m--)
	{
	  scanf("%d%d%d",&i,&j,&c);
	  a[i][j]=c;
	  a[j][i]=c;
	}
    for(i=2;i<=n;i++)
	{
		min[i]=a[1][i];
		p[i]=1;
	}
	top=0;
	flag[1]=false;min[1]=0;max=0;
	for(i=1;i<n;i++)
	{
		c=INF;
		for(j=2;j<=n;j++)
			if(flag[j]&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
		max=max>c?max:c;
		node[++top].x=p[k];
		node[top].y=k;
		flag[k]=false;
		for(j=2;j<=n;j++)
           if(flag[j]&&a[k][j]<min[j])
		   {
			   min[j]=a[k][j];
			   p[j]=k;
		   }
	}
	printf("%d\n",max);
	printf("%d\n",top);
	for(i=1;i<=top;i++)
		printf("%d %d\n",node[i].x,node[i].y);
    return 0;
}

