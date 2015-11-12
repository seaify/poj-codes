#include<stdio.h>
#include<string.h>
char map[100][100][100];
int a,b,c,x0,y0,z0,N,K;
int dir[6][3]={{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
bool flag[100][100][100];
struct node 
{
  int x,y,z;
};
node queue[100000];
int bfs()//如果知道数据范围，并且可以承受，可以开一个标记数组，否则应采用哈希表 
{
   int beg,end,i,j,x,y,z,step,last,max;
   if(flag[z0][x0][y0])
        return 0;
   beg=0;end=1;step=0;
   while(beg<end)
   {
      ++step;
      last=end;
      for(i=beg;i<end;++i)//可能产生的结果小于大于K 
      {
         for(j=0;j<6;++j)
           {
             z=queue[i].z+dir[j][0];
             x=queue[i].x+dir[j][1];
             y=queue[i].y+dir[j][2];        
             if(z<0||z>=a||x<0||x>=b||y<0||y>=c)
                continue; 
             if(map[z][x][y]=='#')
                continue;
             if(!flag[z][x][y])
                {
                  flag[z][x][y]=true;
                  queue[last].x=x;
                  queue[last].y=y;
                  queue[last].z=z;
                  ++last;
                }
             if(flag[z0][x0][y0])
                   return step;
           }
      }
      beg=end;
      end=last;
   }
   return -1;
}
int main()
{
   int cnt,k,i,j;
   while(EOF!=scanf("%d%d%d",&a,&b,&c))
   {
       if(a==0&&b==0&&c==0)
            break; 
       memset(flag,false,sizeof(flag));
       for(i=0;i<a;++i)
         for(j=0;j<b;++j)
         {
             scanf("%s",&map[i][j]);
             for(k=0;k<c;++k)
             {
              if(map[i][j][k]=='S')
              {
                  queue[0].z=i;
                  queue[0].x=j;
                  queue[0].y=k;        
                  flag[i][j][k]=true;
               }
               if(map[i][j][k]=='E')
               {
                  z0=i,x0=j,y0=k;
               }
             }
      
        }
       cnt=bfs();
       if(cnt!=-1)
          printf("Escaped in %d minute(s).\n",cnt);
       else
          printf("Trapped!\n");
   }
   return 0;
}

