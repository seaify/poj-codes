#include<stdio.h>
#include<string.h>
int N,K,queue[200000];
bool flag[200000],time[100002];
int bfs()//如果知道数据范围，并且可以承受，可以开一个标记数组，否则应采用哈希表 
{
   int beg,end,i,j,x,step,last,max;
   if(N>=K)
       return N-K;
   memset(flag,false,(K+2)*sizeof(bool));
   memset(time,false,sizeof(time));
   queue[0]=N;flag[N]=true;
   beg=0;end=1;step=0;max=K-N;
   while(beg<end)
   {
      ++step;
      if(time[step])
          return step;
      last=end;
      for(i=beg;i<end;++i)//可能产生的结果小于大于K 
      {
         for(j=0;j<=2;++j)
           {
              if(j==2)
                 x=2*queue[i];
              else if(j==1)
                 x=queue[i]+1;
              else
                 x=queue[i]-1;
              if(x==K)
                  return step;
              if(x>K)
			  {
				  if(step+x-K<=max)
                    time[step+x-K]=true;
			  }
              else if(!flag[x])
                {
                  flag[x]=true;
                  queue[last]=x;
                  ++last;
                }
           }
      }
      beg=end;
      end=last;
   }
   return 0;
}
int main()
{
   while(EOF!=scanf("%d%d",&N,&K))
   {
       printf("%d\n",bfs());
   }
   return 0;
}
