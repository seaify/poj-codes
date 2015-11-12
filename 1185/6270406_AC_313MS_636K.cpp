#include<iostream>

int a[60000][2],num[1100],p[20];
int m,n,x,ans,tmp;
char map[200][20];

void dfs(int last,int now ,int cur,int lastx,int lasty,int lastz,int depth)    //////last记录最新的， 
{
     int t1,t2;
     if(depth==n)
     {
         if(a[last][1-x]+num[cur]>a[now][x])
                a[now][x]=a[last][1-x]+num[cur];
         return ;
     }
     
     dfs(3*last,3*now,(cur<<1),lastx,lasty,lastz,depth+1);  ////均不选 
     

     if(tmp>=2&&map[tmp-2][depth]=='P'&&depth-lastx>2)  ////当前不选，以前选第一行 
              dfs(3*last+1,3*now,(cur<<1),depth,lasty,lastz,depth+1); 
              
     if(tmp>=1&&map[tmp-1][depth]=='P'&&depth-lasty>2)
              dfs(3*last+2,3*now+1,(cur<<1),lastx,depth,lastz,depth+1);
                 
     if(map[tmp][depth]=='P'&&depth-lastz>2) 
              dfs(3*last,3*now+2,(cur<<1)+1,lastx,lasty,depth,depth+1);                  //////当前选... 
                                           
}

int main()
{
    int i,j;
    
    for(i=0;i<(1<<10);i++)
    {
          num[i]=0;
          for(j=0;j<10;j++)
              if(i&(1<<j))
                  num[i]++;
    }
    
    p[0]=1;
    for(i=1;i<=10;i++)
          p[i]=3*p[i-1];
          
    
    while(EOF!=scanf("%d %d",&m,&n))
    {
         for(i=0;i<m;i++)
             scanf("%s",map+i);
             
         for(i=0;i<p[n];i++)
             a[i][0]=a[i][1]=0;
             
         for(i=0;i<m;i++)
         {
             tmp=i;
             x=(i&1);   ////求第x 
             dfs(0,0,0,-10,-10,-10,0);
             for(j=0;j<p[n];j++)
                 a[j][1-x]=0;
         }
         
         ans=0;
         for(j=0;j<p[n];j++)
             if(a[j][x]>ans)
                 ans=a[j][x];
             
         printf("%d\n",ans);
    }
    return 0;
}

