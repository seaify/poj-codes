#include<stdio.h>
#include<algorithm>
using namespace std;

int N,M,value,x[20000],y[20000],v[20000],a[50000],h[50000];
int key[50000],p[50000];

int ID(int x)
{
	int left=1,right=N,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]<x)
			left=mid+1;
		else
			right=mid-1;
	}
}

void init(int x)
{
	p[x]=-1;
	key[x]=0; //到父结点的距离..
}

int find(int x,int t)
{
	int r=x,c,t1,sum=0,tmp=0;
	while(p[r]!=-1)
	{
		sum+=key[r];
		r=p[r];
	}
	tmp=sum;
	while(p[x]!=-1)
	{
         c=p[x];
		 p[x]=r;
		 t1=key[x];
		 key[x]=sum;
		 sum-=t1;
		 x=c;
	}
	value+=t*tmp;
	return r;
}

void Union(int L,int R,int v)
{
     int t1,t2;
	 value=0;
	 t1=find(L,-1);
	 t2=find(R,1);
	 if(t1==t2)
		 return ;
	 p[t2]=t1;
	 key[t2]=v-value;
}



int main()
{
	int i,L,R;
	while(EOF!=scanf("%d",&M))
	{
         for(i=1;i<=M;i++)
		 {
			scanf("%d %d %d",&x[i],&y[i],&v[i]);
			if(x[i]>y[i])
				swap(x[i],y[i]);
			x[i]--;
            h[i]=x[i];
			h[i+M]=y[i];
		 }
		 sort(h+1,h+2*M+1);
		 h[2*M+1]=h[2*M]-1;
		 N=0;
		 for(i=2;i<=2*M+1;i++)
			 if(h[i]!=h[i-1])
                  a[++N]=h[i-1];
	/*	 for(i=1;i<=N;i++)
			 printf("%d ",a[i]);
		 printf("\n");*/
         for(i=1;i<=N;i++)
			 init(i);
         for(i=1;i<=M;i++)
		 {
			 L=ID(x[i]);
			 R=ID(y[i]);
			 value=0;
			 if(find(L,-1)!=find(R,1))
			 {
				 Union(L,R,v[i]);
			//	 puts("Accept");
				 printf("Accept\n");
			 }
			 else
			 {
                 if(value==v[i])
					 printf("Accept\n");
                 else
					 printf("Bug Detected %d\n",value);
			 }
		 }
	}
}