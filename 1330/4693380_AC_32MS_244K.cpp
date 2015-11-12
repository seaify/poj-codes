#include<stdio.h>
#include<string.h>
bool flag[10010];
int t,k,n,x,y,p[10010];
int main()
{
 scanf("%d",&t);
 while(t--)
 {
  memset(p,0,sizeof(p));
  memset(flag,false,sizeof(flag));
  scanf("%d",&n);
  k=n-1;
  while(k--)
  {
	scanf("%d%d",&x,&y);
	p[y]=x;
  }
  scanf("%d%d",&x,&y);
  while(p[x]!=0)
  {
	flag[x]=true;
	x=p[x];
  }
  while(p[y]!=0)
  {
	if(flag[y])
		break;
	y=p[y];
  }
  printf("%d\n",y);
 }
 return 0;
}