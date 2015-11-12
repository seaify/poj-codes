#include<stdio.h>
int main()
{
	int data[40001],t[40001],len,i,p,left,right,mid,time;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d",&p);
		for(i=1;i<=p;i++)
			scanf("%d",&data[i]);
		len=1;
		t[len]=data[1];
		for(i=2;i<=p;i++)
			if(data[i]>t[len])
				t[++len]=data[i];
			else
			{
				left=1;
				right=len-1;
				while(left<=right)
				{
					mid=(left+right)/2;
					if(t[mid]>=data[i])
						right=mid-1;
					else
						left=mid+1;
				}
				t[left]=data[i];
			}
			printf("%d\n",len);
	}
	return 0 ;
}

