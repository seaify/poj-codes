#include<stdio.h>
int n,flag,p[200];
void dfs(int cnt,int depth)
{
   if(depth>100)
       return ;
   if(cnt==0)
   {
      flag=depth;
      return ;
   }
   p[depth+1]=0;
   dfs((cnt*10)%n,depth+1);
   if(flag!=-1)
      return ;
   p[depth+1]=1;
   dfs((cnt*10+1)%n,depth+1);
}
int main()
{
  int i;
  while(EOF!=scanf("%d",&n))
  {
     if(n==0)
         break;
     flag=-1,p[1]=1;
     dfs(1,1);
     for(i=1;i<=flag;++i)
        printf("%d",p[i]);
	 printf("\n");
  }
  return 0;
}
