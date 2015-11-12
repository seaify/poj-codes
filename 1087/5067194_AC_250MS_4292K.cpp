#include<stdio.h>
#include<string.h>
char ch[400][400],a[100],b[100];
int map[1000][1000],pos[1000],tot,n,m;
int link[1000],first[1000];//link[M],first[N]
bool flag[1000];//flag[M]
struct node
{
  int x,y,next;
};
node g[50000];
int dfs(int p)
{
  int temp;
  temp=first[p];
  while(temp!=-1)
  {
	if(!flag[g[temp].y])
	{
	  flag[g[temp].y]=true;
	  if(link[g[temp].y]==-1||dfs(link[g[temp].y]))
	  {
		  link[g[temp].y]=p;
		  return 1;
	  }
	} 
	temp=g[temp].next;
  }
return 0;
}
void add(int x,int y)//加入
{
   ++tot;
   g[tot].x=x;
   g[tot].y=y;
   g[tot].next=first[x];
   first[x]=tot;
}
int solve()
{
  int i,res=0;
  for(i=1;i<=n;i++)
      link[i]=-1;
  for(i=1;i<=m;i++)
  {
   memset(flag,false,sizeof(flag));
   if(dfs(i))
      res++;
  }
  return res;
}
int Find(char a[])
{
  int i;
  for(i=1;i<=tot;++i)
      if(strcmp(a,ch[i])==0)
            return i;
  ++tot;
  strcpy(ch[tot],a);
  return tot;
}
int main()
{
  int i,j,k;
  while(EOF!=scanf("%d",&n))
  {
    for(i=1;i<=n;++i)
       scanf("%s",ch[i]);
    tot=n;
    scanf("%d",&m);
    for(i=1;i<=m;++i)
    {
      scanf("%s%s",a,b);
      pos[i]=Find(b);//记录其在结点中的位置。。。 
    }
    scanf("%d",&k);
    memset(map,0,sizeof(map));
    for(i=1;i<=k;++i)
    {
       scanf("%s%s",a,b);
       map[Find(a)][Find(b)]=1;
    }  
    for(i=1;i<=tot;++i)
       map[i][i]=1;
    for(k=1;k<=tot;++k)
      for(i=1;i<=tot;++i)
        for(j=1;j<=tot;++j)
            map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
    tot=0;
    for(i=1;i<=m;i++)
	   first[i]=-1;
    for(i=1;i<=m;++i)
      for(j=1;j<=n;++j)
         if(map[pos[i]][j])
           {
               add(i,j);
           }
   printf("%d\n",m-solve());
  }
}
