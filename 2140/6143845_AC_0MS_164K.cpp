#include<iostream>

int n,len,tmp,sum;

int main()
{
    while(EOF!=scanf("%d",&n))
    {
        sum=0;
        for(len=1;len*len+len<=2*n;len++)
        {
             tmp=n-(len*len+len)/2;
             if(tmp%len==0)
                sum++;                               
        }
        printf("%d\n",sum);
    }
} 

