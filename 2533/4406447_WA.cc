#include<stdio.h>  
int main()  
{  
    int n,i,j,f[1001],max,c;  
    long a[1001];  
    scanf("%d",&n);    
        for(i=1;i<=n;i++)  
            scanf("%ld",&a[i]);  
        f[1]=1;c=0;  
        for(i=2;i<=n;i++)  
        {  
            max=0;  
            for(j=1;j<i;j++)  
            {  
                if(a[j]>=a[i])  
                    continue;  
                if(f[j]>max)  
                    max=f[j];  
            }  
            f[i]=max+1;  
            if(f[i]>c)  
                c=f[i];  
        }      
        printf("%d\n",c);  
    return 0;  
}  

              