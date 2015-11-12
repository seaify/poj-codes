#include<cstdio> 
#include<memory.h> 
typedef  long  Int64; 
Int64 a[510][510]; 
Int64 b[510][510]; 
Int64 c[510][510]; 
Int64 E[510] = {0}; 
Int64 e[510] = {0}; 
Int64 tmp1[510] = {0}; 
bool eq(int n) 

{ 
	int i,j;
       memset(tmp1,0,sizeof(tmp1));       
      for(i=0;i<n;i++) 
              for( j=0;j<n;j++) 
                     tmp1[i] += a[j][i] * (j+1);//关键部分： *（j+1）就是乘了一个递增的行向量X：{1,2,3,...,n} 
       for( i=0;i<n;i++) 
             for(j=0;j<n;j++) 
                     e[i] += tmp1[j]*b[j][i];//以上四个for用于求AB的行向量。 
       for(i=0;i<n;i++) 
              if(e[i] != E[i]) return false; 

       return true; 
} 
int main() 
{ 
       int n,i,j; 
       while(scanf("%d",&n) != EOF) 

       { 
              for( i=0;i<n;i++) 
                     for( j=0;j<n;j++) 
                            scanf("%I64d",&a[i][j]); 
              for(i=0;i<n;i++) 
                     for( j=0;j<n;j++) 
                            scanf("%I64d",&b[i][j]); 
             for( i=0;i<n;i++) 
                     for( j=0;j<n;j++) 
                            scanf("%I64d",&c[i][j]);               
              memset(e,0,sizeof(e)); 
             memset(E,0,sizeof(E));                       
              for(i=0;i<n;i++) 
                    for( j=0;j<n;j++) 

                           E[i] += c[j][i] * (j+1);//关键部分： *（j+1）就是乘了一个递增的行向量X：{1,2,3,...,n} 
                      
              if(eq(n)) printf("YES\n"); 

              else printf("NO\n"); 

       } 

       return 0; 

} 
