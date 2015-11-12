#include <stdio.h>
#include <string.h>
int N,M;
bool map[502][502];
int match[502];
int chk[502];
int dfs(int p)
{
int i,t;
for(i=1;i<=M;i++)
{
   if(map[p][i]&&!chk[i])
   {
    chk[i]=1;
    t=match[i];
    match[i]=p;
    if(t==N+1||dfs(t))
     return 1;
    match[i]=t;
   }
}
return 0;
}
int solve()
{
int i,res=0;
for(i=1;i<=M;i++)
   match[i]=N+1;
for(i=1;i<=N;i++)
{
   memset(chk,false,sizeof(chk));
   if(dfs(i))
    res++;
}
  return res;
}
int main()
{
int i,j,k,t;
scanf("%d",&t);
while(t--)
{
  scanf("%d%d",&N,&M);
  memset(map,false,sizeof(map));
  //memset(match,0,sizeof(match));
  for(i=1;i<=N;i++)
  {
	 scanf("%d",&k);
	 while(k--)
	 {
	   scanf("%d",&j);
       map[i][j]=true;
	 }
  }
  if(solve()==N)
	  printf("YES\n");
  else
	  printf("NO\n");
}
return 0;
}


