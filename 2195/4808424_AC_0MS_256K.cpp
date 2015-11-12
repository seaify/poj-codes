#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define INF 100000000
struct point
{ 
    int x, y; 
} home[1000], man[1000]; 
int x[101], y[101], map[101][101], link[101], lx[101], ly[101], n; 
int can(int cur) 
{ 
    x[cur] = 1; 
    int i; 
    for (i = 0; i < n; i++) 
        if (!y[i] && lx[cur] + ly[i] == map[cur][i]) 
        { 
            y[i] = 1; 
            if (link[i] == -1 || can(link[i])) 
            { 
                link[i] = cur; 
                return 1; 
            } 
        } 
    return 0; 
} 
int KM() 
{ 
    memset(link, 0xff, sizeof(link)); 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        while (1) 
        { 
            memset(x, 0, sizeof(x)); 
            memset(y, 0, sizeof(y)); 
            if (can(i)) break; 
            int j, k, min = INF; 
            for (j = 0; j < n; j++) 
                if (x[j]) 
                    for (k = 0; k < n; k++) 
                        if (!y[k]) 
                            min= min< lx[j] + ly[k] - map[j][k]?min:lx[j] + ly[k] - map[j][k]; 
            if (!min) break; 
            for (j = 0; j < n; j++) 
            { 
                if (x[j]) lx[j] -= min; 
                if (y[j]) ly[j] += min; 
            } 
        } 
    } 
    int res = 0; 
    for (i = 0; i < n; i++) 
        if (link[i] != -1) 
            res += map[link[i]][i]; 
    return res; 
} 
int main() 
{ 
    int i, j, m; 
    char gra[101][101]; 
    while (scanf("%d%d", &n, &m), n) 
    { 
        int hN = 0, mN = 0; 
        for (i = 0; i < n; i++) 
        { 
            scanf("%s", gra[i]); 
            for (j = 0; j < m; j++) 
                if (gra[i][j] == 'H') 
                { 
                    home[hN].x = i; 
                    home[hN++].y = j; 
                } 
                else 
                    if (gra[i][j] == 'm') 
                    { 
                        man[mN].x = i; 
                        man[mN++].y = j; 
                    } 
        } 
        if (hN != mN) 
        { 
            printf("error\n"); 
            continue; 
        } 
        n = hN; 
        for (i = 0; i < n; i++) 
        { 
            lx[i] = -INF, ly[i] = 0; 
            for (j = 0; j < n; j++) 
            { 
                map[i][j] = -(abs(home[i].x - man[j].x) 
                            + abs(home[i].y - man[j].y)); 
                lx[i] = lx[i]>map[i][j]?lx[i]:map[i][j]; 
            } 
        } 
        printf("%d\n",-KM()); 
    } 
	return 0;
}
