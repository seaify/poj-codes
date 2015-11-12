#include <stdio.h>
#include <memory.h>


const int MAXN = 1010;
const int DX[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int DY[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


struct TNode
{
TNode()
{
   end = -1;
   memset( next, 0, sizeof( next ) );
}
int end;
TNode* next[ 26 ];
} *root;


int n, m, w;
int sx, sy;
char maze[ MAXN ][ MAXN ];
int r[ MAXN ][ 3 ];


void insert( TNode* crt, char* s, int id )
{
if ( *s == 0 ) crt->end = id;
else
{
   if ( crt->next[ *s - 'A' ] == NULL ) crt->next[ *s - 'A' ] = new TNode;
   insert( crt->next[ *s - 'A' ], s + 1, id );
}
}


void read()
{
scanf( "%d %d %d", &n, &m, &w );
int i, j;
char word[ MAXN ];
root = new TNode;
memset( maze, 0, sizeof( maze ) );
for ( i = 1; i <= n; i ++ )
   scanf( "%s", maze[ i ] + 1 );
for ( i = 1; i <= w; i ++ )
{
   scanf( "%s", word );
   insert( root, word, i );
}
}


void search( TNode* crt, int x, int y, int d )
{
if ( crt == NULL ) return;
if ( crt->end > -1 )
{
   r[ crt->end ][ 0 ] = sx;
   r[ crt->end ][ 1 ] = sy;
   r[ crt->end ][ 2 ] = d;
}
if ( !maze[ x ][ y ] ) return;
search( crt->next[ maze[ x ][ y ] - 'A' ], x + DX[ d ], y + DY[ d ], d );
}


void work()
{
int i, j, k;
for ( i = 1; i <= n; i ++ )
   for ( j = 1; j <= m; j ++ )
    for ( k = 0; k < 8; k ++ )
    {
     sx = i;
     sy = j;
     search( root, i, j, k );
    }
}


void output()
{
int i;
for ( i = 1; i <= w; i ++ )
   printf( "%d %d %c\n", r[ i ][ 0 ] - 1, r[ i ][ 1 ] - 1, r[ i ][ 2 ] + 'A' );
}


int main()
{
//freopen( "input.txt", "r", stdin );
read();
work();
output();
return 0; 
}