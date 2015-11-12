#include<iostream>

int N,M,ans;
int map[500][500],flag[500][500];
int q[900000][2];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};


void bfs()
{
    int i,j,x,y,x1,y1,beg,end,tmp,step=0;
    
    if(map[0][0]==0)
    {
       printf("-1\n");
       continue; 
    }
    
    for(i=0;i<=400;i++)
       for(j=0;j<=400;j++)
             flag[i][j]=1;
    
    beg=end=1;
    q[1][0]=0;
    q[1][1]=0;
    flag[0][0]=0;
    
    while(beg<=end)
    {
        step++;
        tmp=end;
        for(;beg<=tmp;beg++)
        {
            x=q[beg][0];
            y=q[beg][1];
            for(j=0;j<4;j++)
            {
                x1=x+dir[j][0];
                y1=y+dir[j][1];
                if(x1<0||y1<0||flag[x1][y1]==0||map[x1][y1]<=step)
                     continue; 
                if(map[x1][y1]==2000)
                {
                     printf("%d\n",step);
                     return ; 
                }
              
                q[++end][0]=x1;
                q[end][1]=y1;
                flag[x1][y1]=0;
                
            }
        }
    }
    
    printf("-1\n");
    
}

int main()
{
    int i,j,x,y,t,x1,y1;
    
    while(EOF!=scanf("%d",&M))
    {
                              
          for(i=0;i<=400;i++)
             for(j=0;j<=400;j++)
                 map[i][j]=2000;
                 
          while(M--)
          {
              scanf("%d %d %d",&x,&y,&t); 
              map[x][y]<?=t;
              for(i=0;i<4;i++)
              {
                  x1=x+dir[i][0];
                  y1=y+dir[i][1];
                  if(x1>=0&&y1>=0)
                     map[x1][y1]<?=t;
              }
          }
          
          bfs();
              
              
    }
    return 0;
} 
