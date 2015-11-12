#include<stdio.h>
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool last;int n,x1,y1,h,w,minx,map[100][100];
void dfs(int x,int y,int depth)
{
   int i,j,a,b;bool flag;
   if(depth>=minx)
       return ;
   for(i=0;i<4;++i)
   {
     flag=false;
     for(j=1;;++j)
     {
        a=x+j*dir[i][0];
        b=y+j*dir[i][1];
        if(j==1&&map[a][b]==1)
           break;
        if(a<1||a>h||b<1||b>w)
           break;
        if(a==x1&&b==y1)
        {
           if(depth<minx)
              minx=depth;
           last=true;
           return ;
        }
        if(map[a][b]==1)
        {
          flag=true;
          break;
        }   
     }
     if(flag)
     {
        map[a][b]=0;
        dfs(a-dir[i][0],b-dir[i][1],depth+1);
        map[a][b]=1;
     }
   }
}
int main()
{
   int i,j,x0,y0;
   while(EOF!=scanf("%d%d",&w,&h))
   {
     if(h==0&&w==0)
        break;
     for(i=1;i<=h;++i)
       for(j=1;j<=w;++j)
        {
          scanf("%d",&map[i][j]);
          if(map[i][j]==2)
              x0=i,y0=j;
          if(map[i][j]==3)
              x1=i,y1=j;
        }
    last=false;minx=11;
    dfs(x0,y0,1);
    if(last)
       printf("%d\n",minx);
    else
       printf("-1\n");
   }
   return 0;
}
