#include<stdio.h>
#include<algorithm>
using namespace std;
int m,n,a[110][2100],c[2100];
int heap[210000],size;

void push(int s) 
{
	int i,tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2]>heap[i])
	{
		tmp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=tmp;
		i=i/2;
	}
}

int del()
{
	int i,l,r,min,tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		min=i;
		if(l<=size&&heap[l]<heap[i]) //取出较小元素置为根。。。
			min=l;
		if(r<=size&&heap[r]<heap[min])
			min=r;
		if(min!=i)
		{
			vx=heap[i];
			heap[i]=heap[min];
			heap[min]=vx;
			i=min;
		}
		else
			break;
	}
    return tmp;
}


int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
        {
           for(j=0;j<n;j++)
              scanf("%d",&a[i][j]);
           sort(&a[i][0],&a[i][n]);
        }
        for(i=0;i<n;i++)
            c[i]=a[0][i];
        for(i=1;i<m;i++)
        {
             size=0;
             for(j=1;j<=n;j++)
             {
                for(k=1;k<=n;k++)
                    if(k*j<=n)
                         push(c[j-1]+a[i][k-1]);
                    else
                        break;
             }
             for(j=0;j<n;j++)
                 c[j]=del();               
        }
        for(i=0;i<n-1;i++)
            printf("%d ",c[i]);
        printf("%d\n",c[n-1]);
    }
    return 0;
}
