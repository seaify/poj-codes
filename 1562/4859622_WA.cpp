#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct {
       int x, y;                    //定义这个结构体已便于存放元素值为'@'的下标 
       char pre;
}sq[500];

int fx[8] = {0, 0, -1, 1, -1, 1,-1, 1};
int fy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
char str[25][25];
int k, qh, qe, cnt;              //k用来模拟8个方向，qh， qe 分别代表队首和队尾 

void MakeWall(int, int);
void search(int i, int j);


int main()
{
    int i, j; 
    int m, n;          //m 代表行 n 代表列  
    char temp;
    
    while(scanf("%d%d", &m, &n) && m)
    {
            for (i=1; i<=m; i++)
                scanf("%s", str[i]+1);     
                      
            MakeWall(m, n);

            cnt = 0;
            for (i = 1; i <= m; i++) {
                for (j = 1; j <= n; j++) {
                      if(str[i][j] == '@') {
                         search(i, j);
                         cnt++;      //ccount自加1，说明有 
                      }
                }    
            } 
            printf("%d\n", cnt); 
        }
        
  //  system("pause");
    return 0;
}

void MakeWall(int m, int n)
{
     int i,j;
     
      for (j = 0; j <= n + 1; j++)
            str[m+1][j] = str[0][j] = '*';

      for (i = 0; i <= m + 1; i++)
                  str[i][0] = str[i][n + 1] = '*';
}
    
void search(int i, int j)
{
     int newi, newj; 
     
     qh = 0;      //队首 
     qe = 1;      //队尾 
     newi = i;
     newj = j;
     str[newi][newj] = '*';             //因为str[newi][newj] = '@' ,所以要将他的值赋为*表示这个位置已经搜索过 
     sq[1].x = newi; sq[1].y  = newj;   //将他的@的下标赋给sq[1],以便于后面对他进行搜索 
     while( qh != qe)
     {
            qh = qh +1;                 //出队
             
            for(k = 0; k < 8; k++)
            {            //每个出队的元素都要对他的8个方向进行搜索当搜索到的值为'@'时，进队 
                  newi = sq[qh].x + fx[k];
                  newj = sq[qh].y + fy[k];
                  if(str[newi][newj] == '@')
                  {
                       qe++;            //进队 
                       sq[qe].x = newi;
                       sq[qe].y = newj;
                       str[newi][newj] = '*';   //因为这个元素进队了所以将这个元素的值赋为*                        
                  }
            }
     } 
} 
