#include<stdio.h>
#include<string.h>
#define N 51
int g[N][N], x[N];
int n, MAX,bestn, cn;

void backtrack(int i) {
    int ok = 1;
    if (i >= n) {// 到达叶结点
        bestn = cn;
        return;
    }
    // 检查顶点 i 与当前团的连接
    for (int j = 0; j < i; j++)
        if (x[j] == 1 && !g[i][j]) {// i与j不相连
            ok = 0;
            break;
        }
    if (ok) {// 进入左子树
        x[i] = 1;
        cn++;
        backtrack(i + 1);
        cn--;
    }
    if (cn + n - i > bestn) {// 进入右子树
        x[i] = 0;
        backtrack(i + 1);
    }
}

int main() {
    int i;
    unsigned int j;
    char str[100];
    while (scanf("%d\n", &n) && n) {
        memset(g, 0, sizeof(g));
        memset(x, 0, sizeof(x));
        for (i = 0; i < n; i++) {
            gets(str);
            for (j = 2; j < strlen(str); j++)
                g[i][str[j] - 'A'] = 1;
        }
        bestn = cn = 0;
        backtrack(0);
        if (bestn > 1)
            printf("%d channels needed.\n", bestn);
        else
            printf("%d channel needed.\n", bestn);
    }
    return 0;
}
 

