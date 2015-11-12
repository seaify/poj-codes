#include <stdio.h>
int res[21][21][21];
int main()
{
    int a,b,c;
    int i,j,k;
    for(i=0;i<21;i++)
    {
        for(j=0;j<21;j++)
            res[0][i][j]=res[i][0][j]=res[i][j][0]=1;   // 如果有任何一个数为0则结果为1
    }
    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
            for(k=1;k<=20;k++)                        // 自底向上计算结果
            {                    
                if( i<j && j<k )
                    res[i][j][k]=res[i][j][k-1]+res[i][j-1][k-1]-res[i][j-1][k];
                else
                    res[i][j][k]=res[i-1][j][k]+res[i-1][j-1][k]+res[i-1][j][k-1]-res[i-1][j-1][k-1];
            }
    }
    while( scanf("%d%d%d",&a,&b,&c) )
    {
        if(-1==a && -1==b && -1==c)
            break;        
        if( a<=0 || b<=0 || c<=0 )
            printf("w(%d, %d, %d) = %d\n",a,b,c,res[0][0][0]);     
        else if( a>20 || b>20 || c>20 )
            printf("w(%d, %d, %d) = %d\n",a,b,c,res[20][20][20]);
        else
            printf("w(%d, %d, %d) = %d\n",a,b,c,res[a][b][c]);
    }
    return 0;
}
