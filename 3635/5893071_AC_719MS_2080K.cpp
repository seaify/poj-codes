#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
const int C = 100;

struct node
{
    int x,y;
    node(int a=0,int b=0):x(a),y(b){}
};

int p[N],n;
vector<node> map[N];
unsigned int h[N][C+1];

class Heap
{
  private:
       node  array[110000];
       int pos[1100][110];
       int size;
  public:
       Heap()
       {
           memset(pos,0,sizeof(pos));
           size=0;  
       }
       void Reset(int n,int C)
       {
            int i,j;
            for(i=0;i<n;i++)
               for(j=0;j<=C;j++)
                   pos[i][j]=0;
            size=0;
       }
       void Push(const node &r)
       {
            int i;
			i=pos[r.x][r.y];
            if(pos[r.x][r.y]==0)
                 i=++size;
            while(i>1&&h[array[i/2].x][array[i/2].y]>h[r.x][r.y])
            {
                  array[i]=array[i/2];
                  pos[array[i].x][array[i].y]=i;
                  i=i/2;
            }
            pos[r.x][r.y]=i;
            array[i]=r;
       }
       const node &Top()
       {
             return array[1];
       }
       void Pop()
       {
            int i,ls;
            node r;
            r=array[size--];
			if(size==0)
				return;
            i=1;
            while(2*i<=size)
            {
               ls=2*i;
               if(ls+1<=size&&h[array[ls+1].x][array[ls+1].y]<h[array[ls].x][array[ls].y])
                    ls++;
               if(h[r.x][r.y]<h[array[ls].x][array[ls].y])
                     break;
               array[i]=array[ls];
               pos[array[i].x][array[i].y]=i;
               i=ls;       
            }
            array[i]=r;
            pos[r.x][r.y]=i;
       }
       bool Empty()
       {
            return size==0;
       }
}heap;

int Bfs(int c,int s,int e)
{
	int i;
    memset(h,0xff,sizeof(h));
    heap.Reset(n,c);
    h[s][0] = 0;
    heap.Push(node(s,0));
    while(!heap.Empty())
    {
        int x = heap.Top().x, y = heap.Top().y;
        if(x == e) return h[x][y];
        heap.Pop();
        for( i=1;y+i<=c;++i)
        {
            int t = h[x][y] + i*p[x];
            if(t < h[x][y+i])
            {
                h[x][y+i] = t;
                heap.Push(node(x,y+i));
            }
        }
        for( i=0;i<map[x].size();++i)
        {
            if(y >= map[x][i].y && h[x][y] < h[map[x][i].x][y-map[x][i].y])
            {
                h[map[x][i].x][y-map[x][i].y] = h[x][y];
                heap.Push(node(map[x][i].x,y-map[x][i].y));
            }
        }
    }
    return -1;
}

int main()
{
    int i,m,u,v,d,q,c,s,e;
    scanf("%d%d",&n,&m);
    for( i=0;i<n;++i) scanf("%d",&p[i]);
    for( i=0;i<m;++i)
    {
        scanf("%d%d%d",&u,&v,&d);
        map[u].push_back(node(v,d));
        map[v].push_back(node(u,d));
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&c,&s,&e);
        int mincost = Bfs(c,s,e);
        if(mincost == -1) printf("impossible\n");
        else              printf("%d\n",mincost);
    }
    return 0;
}
