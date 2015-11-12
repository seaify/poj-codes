
#include<stdio.h>  
int main()  
{  
    int m,n,i,j;long c,a[101][101];  
    for(i=1;i<=100;i++)  
    {  
        a[0][i]=1;  
        a[1][i]=1;  
        a[i][1]=1;  
    }  
    while(EOF!=scanf("%d%d",&m,&n))  
    { for(i=2;i<=m;i++)  
        for(j=2;j<=n;j++)  
        {  
            if(i>=j)  
              a[i][j]=a[i-j][j]+a[i][j-1];  
            else  
              a[i][j]=a[i][j-1];  
        }  
         c=a[m][n];  
      printf("%ld\n",c);  
    }  
    return 0;  
}  

