#include <stdio.h> 
#include <string.h> 
#define INF 100000000
int dis[1001], close[1001], flag[1001], map[1001][1001], n; 
int adj[1001][1001], ans; 
int prim() 
{ 
    int i; 
    for (i = 1; i < n; i++) 
        dis[i] = map[0][i], close[i] = 0, flag[i] = 0; 
    flag[0] = 1; 
    for (i = 1; i < n; i++) 
    { 
        int j, u, min = INF; 
        for (j = 1; j < n; j++) 
            if (!flag[j] && min > dis[j]) 
                u = j, min = dis[j]; 
        if (min == INF) return 0; 
        flag[u] = 1; 
        adj[close[u]][++adj[close[u]][0]] = u; 
        adj[u][++adj[u][0]] = close[u]; 
        ans += min; 
        for (j = 1; j < n; j++) 
            if (!flag[j] && dis[j] > map[u][j]) 
                dis[j] = map[u][j], close[j] = u; 
    } 
    return 1; 
} 
int dfs(int cur, int max, int root, int fa) 
{ 
    int i, v, res = INF; 
    flag[cur] = 1; 
    if (map[cur][root] != INF && root != fa) 
        res = map[cur][root] - max; 
    for (i = 1; i <= adj[cur][0]; i++) 
    { 
        v = adj[cur][i]; 
        if (!flag[v]) 
            res <?= dfs(v, map[cur][v] >? max, root, cur); 
    } 
    return res; 
} 
int main() 
{ 
    int i, j, m, beg, end, w,t; 
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &m); 
        for (i = 0; i < n; i++) 
            for (j = 0; j < n; j++) 
                map[i][j] = INF; 
        for (i = 0; i < m; i++) 
        { 
            scanf("%d%d%d", &beg, &end, &w); 
            map[beg - 1][end - 1] = w; 
            map[end - 1][beg - 1] = w; 
        } 
        for (i = 0; i < n; i++) 
            adj[i][0] = 0; 
        ans = 0; 
        prim();
        int min = INF; 
        for (i = 0; i < n; i++) 
        { 
            memset(flag, 0, sizeof(int) * n); 
            min <?= dfs(i, 0, i, i); 
        } 
        if (min == 0) 
            printf("Not Unique!\n"); 
        else 
            printf("%d\n", ans); 
    } 
}
    
