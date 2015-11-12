#include<iostream>

#include<cmath>

#include<queue>

using namespace std;

#define maxn 305


int n;

int used[maxn][maxn],g[maxn][maxn],f[maxn][maxn];

int d[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};


struct Point{

       int x,y;

       friend bool operator<(Point p1,Point p2)

       {

              return f[p1.x][p1.y]>f[p2.x][p2.y]; //从小到大

       }

}st,ed,tt;


int h(Point p)

{

       //return 0;

       return (abs(p.x-ed.x)+abs(p.y-ed.y)+2)/3;

}

int ok(int x,int y)

{

       return (x>=0 && x<n && y>=0 &&y<n);

}

int solve()

{

       int i,x,y,xx,yy;

       Point curkey,nextkey;

       priority_queue<Point> qu;


       memset(used,0,sizeof(used));

       g[st.x][st.y]=0;

       f[st.x][st.y]=0+h(st);

       used[st.x][st.y]=1;

       qu.push(st);


       tt.x=303;

       tt.y=303;

       f[tt.x][tt.y]=-1;


       while(!qu.empty())

       {

              curkey=qu.top();

              qu.pop();

              x=curkey.x;

              y=curkey.y;

              if(x==ed.x && y==ed.y)

                     return g[x][y];

              for(i=0;i<8;i++)

              {

                     xx=x+d[i][0];

                     yy=y+d[i][1];

                     if(!ok(xx,yy)) continue;

                     if( !used[xx][yy]|| (used[xx][yy]==1 && g[x][y]+1<g[xx]


[yy]))

                     {

                            g[xx][yy]=g[x][y]+1;

                            nextkey.x=xx;

                            nextkey.y=yy;

                            f[xx][yy]=g[xx][yy]+h(nextkey);

                            qu.push(nextkey);

                            if(!used[xx][yy]){

                                   used[xx][yy]=1;

                            }

                            else{

                                   qu.push(tt);

                                   qu.pop();

                            }

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

