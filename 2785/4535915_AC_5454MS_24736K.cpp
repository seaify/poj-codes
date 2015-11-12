#include<stdio.h>  
#include<algorithm>  
using namespace std;  
int s[16000002];  
int a[4002],b[4002],c[4002],d[4002],sum,x;  
int main()  
{  
    int i,j,k,left,mid,right,len,n;  
    bool flag;  
    while(EOF!=scanf("%d",&n)&&n)  
    {  
        for(i=1;i<=n;i++)  
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);  
        k=1;  
        for(i=1;i<=n;i++)  
            for(j=1;j<=n;j++)  
                s[k++]=a[i]+b[j];  
        len=k-1;sum=0;  
        sort(s+1,s+k);  
        for(i=1;i<=n;i++)  
            for(j=1;j<=n;j++)  
            {  
                x=-(c[i]+d[j]);                  
                flag=false;  
                left=1;  
                right=len;  
                while(left<=right)  
                {    
                  mid=(left+right)/2;  
                  if(x==s[mid])  
                  {  
                      sum++;  
                      for(k=mid+1;k<=len;k++)  
                         if(s[k]!=x)  
                             break;  
                         else  
                             sum++;  
                      for(k=mid-1;k>=1;k--)  
                       if(s[k]!=x)  
                           break;  
                       else  
                           sum++;  
                       break;                       
                  }  
                  else if(x>s[mid])  
                        left=mid+1;  
                  else  
                        right=mid-1;  
                }                  
            }  
      printf("%d\n",sum);  
    }  
    return 0;  
}  