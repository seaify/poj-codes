#include<stdio.h>
#include<string.h>
int a,b,c,t;
bool flag[110][110],tag[110];
struct node
{
   int x,y,flag,time;
};
node queue[200000],op[500000];
int bfs()//如果知道数据范围，并且可以承受，可以开一个标记数组，否则应采用哈希表 
{
   int beg,end,i,j,x,y,step,last,cnt,t1;
   memset(tag,false,sizeof(tag));
   memset(flag,false,sizeof(flag));
   queue[0].x=0,queue[0].y=0,queue[0].time=-1;
   tag[0]=true;
   flag[0][0]=true;
   beg=0;end=1;step=0;t=0;
   while(beg<end)
   {
      ++step;
      last=end;
      for(i=beg;i<end;++i)//可能产生的结果小于大于K 
      {
         for(j=0;j<=5;++j)
           {
			  x=y=-1;
		      if(j==0&&queue[i].x<a)
					 x=a,y=queue[i].y,t1=1;
			  else if(j==1&&queue[i].y<b)
					 x=queue[i].x,y=b,t1=1;
			  else if(j==2&&queue[i].x>0)
					 x=0,y=queue[i].y,t1=1;				
			 else if(j==3&&queue[i].y>0)
					 x=queue[i].x,y=0,t1=1;
			  else if(j==4&&queue[i].x>0&&queue[i].y<b)
			  {
					if(queue[i].x+queue[i].y>b)
						x=queue[i].x+queue[i].y-b,y=b;
					else
						x=0,y=queue[i].x+queue[i].y;
					t1=1;
			  }
			 else if(j==5&&queue[i].y>0&&queue[i].x<a)
			 {
					if(queue[i].x+queue[i].y>a)
						x=a,y=queue[i].y+queue[i].x-a;
					else
						x=queue[i].x+queue[i].y,y=0;
					t1=1;

			 }
			 if(x==-1)
				 continue; 
			 cnt=j/2;
			 if(cnt==0)
			    op[++t].x=j+1;
			  else if(cnt==1)
			    op[++t].x=j-1;
			  else if(cnt==2)
			  {
				if(j==4)
					op[++t].x=1,op[t].y=2;
				else 
					op[++t].x=2,op[t].y=1;
			  }
			  op[t].flag=cnt,op[t].time=queue[i].time;	  
			  tag[x]=true,tag[y]=true;
			  if(tag[c])
				  return step;	
			  if(!flag[x][y])
             {
				  flag[x][y]=true;
                  queue[last].x=x;
				  queue[last].y=y;
				  queue[last].time=t;
                  ++last;
              }
           }
      }
      beg=end;
      end=last;
   }
   return 0;
}
void output(int i)
{
    if(i==-1)
		return ;
	output(op[i].time);
	if(op[i].flag==0)
		printf("FILL(%d)\n",op[i].x);
	else if(op[i].flag==1)
		printf("DROP(%d)\n",op[i].x);
	else
    	printf("POUR(%d,%d)\n",op[i].x,op[i].y);
}
int main()
{
   int sum;
  while(EOF!=scanf("%d%d%d",&a,&b,&c))
   {
      sum=bfs();
	  if(sum==0)
		  printf("impossible\n");
	  else
	  {
		  printf("%d\n",sum);
	      output(t);
	  }
   }
   return 0;
}
