#include<iostream>

__int64 n,ans;
__int64 a[30];
char ch[10];

void dfs(__int64 sum, __int64 op, __int64 last, __int64 depth)
{
    __int64 i,x,y;
    if(depth==n+1)
    {
         if(sum==0)
         {
            ans++;
            if(ans<=20)
            {
               for(i=1;i<n;i++)
                   printf("%I64d %c ",i,ch[a[i+1]]);  
               printf("%I64d\n",n);
            }
         
         }
         return ;
            
    }
    
    a[depth]=0;
    dfs(sum+depth,0,depth,depth+1);
    
    a[depth]=1;
    dfs(sum-depth,1,depth,depth+1);
    
    a[depth]=2;

	if(depth<10)
		 y=10*last+depth;
	else
		 y=100*last+depth;

    if(op==0)          //////当depth>=10,增加的是两位...	
         x=sum-last+y;
    else
         x=sum+last-y;
	
    dfs(x,op,y,depth+1);
      
        
}

int main()
{
    ch[0]='+';
    ch[1]='-';
    ch[2]='.';
    while(EOF!=scanf("%I64d",&n))
    {
          ans=0;
          dfs(1,0,1,2);    
          printf("%I64d\n",ans);               
    }
    return 0;
}
