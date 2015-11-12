#include<string.h>
#include<stdio.h>
int map[20][20];
int n;
int flag[20];
int Min;

void DFS( int u, int deep, int cost )
{
    if( deep >= n )
    {
        if( Min == -1 || Min > cost+map[u][0] )
        {
            Min = cost+map[u][0];
        }
        return;
    }
    int i;
    for( i = 1; i <= n; i++ )
    {
        if( flag[i] == 0 )
        {
            if( Min >=0 && cost+map[u][i]+map[i][0] >= Min )continue;
            flag[i] = 1;
            DFS( i, deep+1, cost+map[u][i]);
            flag[i] = 0;
        }
    }
}

int main()
{
    int i, j, k;
    while( scanf( "%d", &n ) != EOF && n )
    {
        for( i = 0; i <= n; i++ )
        {
            flag[i] = 0;
            for( j = 0; j <= n; j++ )
            {
                scanf( "%d", &map[i][j] );
            }
        }
        for( k = 0; k <= n; k++ )
        {
            for( j = 0; j <= n; j++ )
            {
                for( i = 0; i <= n; i++ )
                {
                    if( map[j][i] > map[j][k]+map[k][i] )
                    {
                        map[j][i] = map[j][k]+map[k][i];
                    }
                }
            }
        }
        flag[0] = 1;
        Min = -1;
        DFS( 0, 0, 0 );
        printf( "%d\n", Min );
    }
    return 0;
}


