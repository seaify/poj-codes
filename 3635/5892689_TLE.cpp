#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
const int C = 100;

struct Node
{
    int x,y;
    Node(int a=0,int b=0):x(a),y(b){}
};

int p[N];
vector<Node> map[N];
unsigned int h[N][C+1];

class Heap
{
private:
    Node arr[N*C+N];
    int pos[N][C+1];
    int Size;
public:
    Heap()
    {
        memset(pos,0,sizeof(pos));
        Size = 0;
    }
    void Reset()
    {
        memset(pos,0,sizeof(pos));
        Size = 0;
    }
    void Push(const Node &r)
    {
        int p = pos[r.x][r.y];
        if(pos[r.x][r.y] == 0) p = ++Size;
        while(p/2>0 && h[arr[p/2].x][arr[p/2].y] > h[r.x][r.y])
        {
            arr[p] = arr[p/2];
            pos[arr[p].x][arr[p].y] = p;
            p = p/2;
        }
        arr[p] = r;
        pos[arr[p].x][arr[p].y] = p;
    }
    const Node &Top()
    {
        return arr[1];
    }
    void Pop()
    {
        Node t = arr[Size--];
        int p = 1;
        for(int i=2*p;i<=Size;i=2*p)
        {
            if(i+1<=Size && h[arr[i].x][arr[i].y]>h[arr[i+1].x][arr[i+1].y]) ++i;
            if(h[t.x][t.y] < h[arr[i].x][arr[i].y]) break;
            arr[p] = arr[i];
            pos[arr[p].x][arr[p].y] = p;
            p = i;
        }
        arr[p] = t;
        pos[arr[p].x][arr[p].y] = p;
    }
    bool Empty()
    {
        return Size == 0;
    }
}heap;

int Bfs(int c,int s,int e)
{
    memset(h,0xff,sizeof(h));
    heap.Reset();
    h[s][0] = 0;
    heap.Push(Node(s,0));
    while(!heap.Empty())
    {
        int x = heap.Top().x, y = heap.Top().y;
        if(x == e) return h[x][y];
        heap.Pop();
        for(int i=1;y+i<=c;++i)
        {
            int t = h[x][y] + i*p[x];
            if(t < h[x][y+i])
            {
                h[x][y+i] = t;
                heap.Push(Node(x,y+i));
            }
        }
        for(int i=0;i<map[x].size();++i)
        {
            if(y >= map[x][i].y && h[x][y] < h[map[x][i].x][y-map[x][i].y])
            {
                h[map[x][i].x][y-map[x][i].y] = h[x][y];
                heap.Push(Node(map[x][i].x,y-map[x][i].y));
            }
        }
    }
    return -1;
}

int main()
{
    int n,m,u,v,d,q,c,s,e;
    while(1)
    {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d",&p[i]);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d",&u,&v,&d);
        map[u].push_back(Node(v,d));
        map[v].push_back(Node(u,d));
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&c,&s,&e);
        int mincost = Bfs(c,s,e);
        if(mincost == -1) printf("impossible\n");
        else              printf("%d\n",mincost);
    }
}
    return 0;
}
