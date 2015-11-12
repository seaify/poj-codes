#include<stdio.h>

int num[2][8000000];
int n,m,total;

void init(int x1,int y1,int x2,int y2)////求出的中间1段.. 
{
     if(x1+x2>n||y1+y2>n)
          return ;
          
     init(x1,y1,x1+x2,y1+y2);
     
     ++total;
     
     num[0][total]=x1+x2;
     num[1][total]=y1+y2;
     
     init(x1+x2,y1+y2,x2,y2);
          
} 

int main()
{
    int i,x;
    
    while(EOF!=scanf("%d %d",&n,&m))
    {
                         
       total=1;
       num[0][1]=0;
       num[1][1]=1;
                         
       init(0,1,1,1);
       
       total++;
       
       num[0][total]=1;
       num[1][total]=1;
       
       
       while(m--)
       {
           scanf("%d",&x);
           if(x>total)
                printf("No Solution\n");
           else
                printf("%d/%d\n",num[0][x],num[1][x]); 
       } 
       
    }
    return 0;
} 
