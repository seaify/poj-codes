#include <stdio.h>
#include <string.h>
int N;
bool map[502][502];
int match[502];
int chk[502];
int dfs(int p)
{
int i,t;
for(i=1;i<=N;i++)
{
   if(map[i][p]&&!chk[i])
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
for(i=1;i<=N;i++)
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
int i,j,k;
scanf("%d%d",&N,&k);
memset(map,false,sizeof(map));
while(k--)
{
	 scanf("%d%d",&i,&j);
     map[i][j]=true;
}
printf("%d\n",solve());
return 0;
}

