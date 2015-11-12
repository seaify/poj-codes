#include<cstdio>
#include<memory>
using namespace std;
 
const int maxnode = 1024;
const int infinity = 2100000000;
 
struct edge{
    int ver;    // vertex
    int cap;    // capacity
    int flow;   // current flow in this arc
    edge *next; // next arc
    edge *rev;  // reverse arc
    edge(){}
    edge(int Vertex, int Capacity, edge *Next)
        :ver(Vertex), cap(Capacity), flow(0), next(Next), rev((edge*)NULL){}
    void* operator new(size_t, void *p){
        return p;
    }
}*Net[maxnode];
int dist[maxnode]= {0}, numbs[maxnode] = {0}, src, des, n;
 
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
void rev_BFS(){
    int Q[maxnode], head = 0, tail = 0;
    for(int i=1; i<=n; ++i){
        dist[i] = maxnode;
        numbs[i] = 0;
    }
 
    Q[tail++] = des;
    dist[des] = 0;
    numbs[0] = 1;
    while(head != tail){
        int v = Q[head++];
        for(edge *e = Net[v]; e; e = e->next){
            if(e->rev->cap == 0 || dist[e->ver] < maxnode)continue;
            dist[e->ver] = dist[v] + 1;
            ++numbs[dist[e->ver]];
            Q[tail++] = e->ver;
        }
    }
}
 
int maxflow(){
    int u,i, totalflow = 0;
    edge *CurEdge[maxnode], *revpath[maxnode];
    for( i=1; i<=n; ++i)CurEdge[i] = Net[i];
    u = src;
    while(dist[src] < n){
        if(u == des){    // find an augmenting path
            int augflow = infinity;
            for( i = src; i != des; i = CurEdge[i]->ver)
                augflow = min(augflow, CurEdge[i]->cap);
            for(i = src; i != des; i = CurEdge[i]->ver){
                CurEdge[i]->cap -= augflow;
                CurEdge[i]->rev->cap += augflow;
                CurEdge[i]->flow += augflow;
                CurEdge[i]->rev->flow -= augflow;
            }
            totalflow += augflow;
            u = src;
        }
 
        edge *e;
        for(e = CurEdge[u]; e; e = e->next)
            if(e->cap > 0 && dist[u] == dist[e->ver] + 1)break;
        if(e){    // find an admissible arc, then Advance
            CurEdge[u] = e;
            revpath[e->ver] = e->rev;
            u = e->ver;
        } else {    // no admissible arc, then relabel this vertex
            if(0 == (--numbs[dist[u]]))break;    // GAP cut, Important!
            CurEdge[u] = Net[u];
            int mindist = n;
            for(edge *te = Net[u]; te; te = te->next)
                if(te->cap > 0)mindist = min(mindist, dist[te->ver]);
            dist[u] = mindist + 1;
            ++numbs[dist[u]];
            if(u != src)
                u = revpath[u]->ver;    // Backtrack
        }
    }
    return totalflow;
}
 
int main(){
    int m, u, v, w;
    //freopen("ditch.in", "r", stdin);
  //  freopen("ditch.out", "w", stdout);
    while(scanf("%d%d", &m, &n) != EOF){    // POJ 1273 need this while loop
        edge *buffer = new edge[2*m];
        edge *data = buffer;
        src = 1; des = n;
        while(m--){
            scanf("%d%d%d", &u, &v, &w);
            Net[u] = new((void*) data++) edge(v, w, Net[u]);
            Net[v] = new((void*) data++) edge(u, 0, Net[v]);
            Net[u]->rev = Net[v];
            Net[v]->rev = Net[u];
        }
        rev_BFS();
        printf("%d\n", maxflow());
        delete [] buffer;
    }
    return 0;
}
