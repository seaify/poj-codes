
#include<stdio.h>  
#include<string.h>  
int flag[120005];  
int count(int *a,long sum)  
{  
    int i,j,k;  
    long max;max=0;  
    for(i=1;i<=6;i++)  
    {  
        max+=a[i]*i;  
        for(j=max;j>=0;j--)  
            if(flag[j])  
            {  
                for(k=1;k<=a[i];k++)  
                {  
                    if(j+k*i==sum/2)return 1;  
                    if(j+k*i>sum/2||flag[j+k*i])  
                        break;  
                    flag[j+k*i]=1;  
                }  
            }  
    }  
    return 0;  
}  

int main()  
{  
    int a[10],c;  
    long sum;c=1;  
    while(EOF!=scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])&&(a[1]||a[2]||a[3]||a[4]||a[5]||a[6]))  
    {     
        memset(flag,0,sizeof(flag));flag[0]=1;  
        sum=a[1]+2*a[2]+3*a[3]+4*a[4]+5*a[5]+6*a[6];  
        printf("Collection #%d:\n",c);  
        c++;  
        if(sum%2==0) 
        { 
            if(count(a,sum))  
              printf("Can be divided.\n");  
            else  
              printf("Can't be divided.\n");  
        } 
        else 
           printf("Can't be divided.\n");  
        printf("\n");  
    }  
    return 0;  
}  

