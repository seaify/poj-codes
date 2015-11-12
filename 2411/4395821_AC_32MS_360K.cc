#include <stdio.h>
#include <string.h>

__int64 a[2][3000];
int t,n,m;

void dfs(int d,int mm) //d表示列数，mm表示状态
{
    if(d==m)
    {
        a[0][mm]++;
        return;
    }
    if(d+1<=m)
        dfs(d+1,mm<<1);
    if(d+2<=m)
        dfs(d+2,mm<<2|3);
}

void DFS(int d,int mm,int nn)//mm对应于上一行状态，nn对应于下一行状态
{
    if(d==m) //若全部的列都确定状态，就把此状态的放法数加到nn状态里
    {
        a[t][nn]+=a[(t+1)%2][mm];
        return;
    }
    if(d+1<=m) //如上所说
    {
        DFS(d+1,mm<<1,nn<<1|1);
        DFS(d+1,mm<<1|1,nn<<1);
    }
    if(d+2<=m)
        DFS(d+2,mm<<2|3,nn<<2|3);
}
int main()
{
    int i;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        if((n*m)%2) //根据面积
        {
            printf("0\n");
            continue;
        }
        if(n>m) 
            n^=m,m^=n,n^=m; //交换
        memset(a,0,sizeof(a));
        dfs(0,0);//初始化第一行
        for(i=2;i<=n;i++)
        {
            t=(i+1)%2; //滚动数组的第一个下标计算
            DFS(0,0,0);
            memset(a[(t+1)%2],0,sizeof(a[0]));//清空另一行
        }
        printf("%I64d\n",a[(n+1)%2][(1<<m)-1]); //输出最后一行全部放满的结果。
    }
    return 0;
}
