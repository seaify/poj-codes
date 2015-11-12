#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x,y,c;
};
node e[60000];
int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return  bb->x-aa->x;
}
int main()
{
   int N,K,i;
   while(EOF!=scanf("%d%d",&N,&K))
   {
      for(i=1;i<=N;++i)
      {
         scanf("%d%d",&e[i].x,&e[i].y);
         e[i].c=i;
      }
      qsort(e+1,N,sizeof(e[1]),cmp);
      for(i=1;i<=K;++i)
         e[i].x=e[i].y;
      qsort(e+1,K,sizeof(e[1]),cmp);
      printf("%d\n",e[1].c);                      
   }
}
