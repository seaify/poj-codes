#include<iostream>

#include<cmath>

#include<queue>

using namespace std;

#define maxn 305


int n;

int used[maxn][maxn],g[maxn][maxn];

int d[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};


struct Point{

       int x,y;

}st,ed;

Point qu[1000000];

int head,end;

int ok(int x,int y)

{

       return (x>=0 && x<n && y>=0 &&y<n);

}

int solve()

{

       int i,x,y,xx,yy;

       Point curkey,nextkey;


       head=end=0;

       memset(used,0,sizeof(used));

       g[st.x][st.y]=0;

       used[st.x][st.y]=1;

       qu[end++]=st;


       g[ed.x][ed.y]=0;

       used[ed.x][ed.y]=2;

       qu[end++]=ed;


       while(head<end)

       {

              curkey=qu[head++];

              x=curkey.x;

              y=curkey.y;


              for(i=0;i<8;i++)

              {

                     xx=x+d[i][0];

                     yy=y+d[i][1];

                     if(!ok(xx,yy)) continue;

                     if(0==used[xx][yy])

                     {

                            g[xx][yy]=g[x][y]+1;

                            nextkey.x=xx;

                            nextkey.y=yy;

                            used[xx][yy]=used[x][y];

                            qu[end++]=nextkey;

                     }

                     else if(used[x][y]!=used[xx][yy])

                     {

                            return g[x][y]+g[xx][yy]+1;

                     }

              }

       }

       return 0;

}

int main()

{

       int cas;

       scanf("%d",&cas);

       while(cas--)

       {

              scanf("%d%d%d%d%d",&n,&st.x,&st.y,&ed.x,&ed.y);

              printf("%d\n",solve());

       }

       return 0;

}

