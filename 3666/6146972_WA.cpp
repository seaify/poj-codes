#include<iostream>

int a[2100],b[2100];
int n,top,sum,ans;

struct node
{
     int x[2100];
     int mid,size;
	 __int64  sum;
};

node q[2100];

void solve(int *a)
{
	 int i,j;
     top=0;
           
	 for(i=1;i<=n;i++)
	 {
		 q[top+1].sum=a[i];
		 q[top+1].mid=a[i];
		 q[top+1].x[1]=a[i];      
		 q[top+1].size=1;     
		 if(i==1||a[i]>=q[top].mid)
			 top++;   
		 else 
		 {
			 while(top>=1&&q[top].mid>q[top+1].mid)
			 {
				 for(j=q[top].size+1;j<=q[top].size+q[top+1].size;j++)
					 q[top].x[j]=q[top+1].x[j-q[top].size];                   
				 q[top].sum+=q[top+1].sum;					 
				 q[top].size+=q[top+1].size;
				 q[top].mid=q[top].sum/q[top].size;
				 top--;
			 }
			 top++;
			 
		 }
	 }
	 
	 sum=0;
	 for(i=1;i<=top;i++)
	 {
		 
		 for(j=1;j<=q[i].size;j++)
		 {
		
			 sum+=abs(q[i].mid-q[i].x[j]);
		 }
	 }
	 if(sum<ans)
		 ans=sum;
}

int main()
{
    int i,j;
    while(EOF!=scanf("%d",&n))
    {
        j=n;                     
        for(i=1;i<=n;i++)
		{
           scanf("%d",&a[i]);
		   b[j--]=a[i];
		}

		ans=(1<<30)-1+(1<<30);

		solve(a);
		solve(b);
           
       
        printf("%d\n",ans); 
           
    }
	return 0;
}
