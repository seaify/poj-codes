#include<iostream>

int a[2100];
int n,top,sum;

struct node
{
     int x[2100];
     int mid,size;
};

node q[2100];

int main()
{
    int i,j;
    while(EOF!=scanf("%d",&n))
    {
                              
        for(i=1;i<=n;i++)
           scanf("%d",&a[i]);
           
        top=0;
           
        for(i=1;i<=n;i++)
        {
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
                     q[top].mid=(q[top].size*q[top].mid+q[top+1].size*q[top+1].mid)/(q[top].size+q[top+1].size);
                     q[top].size+=q[top+1].size;
                     top--;
               }
               top++;
           
           }
        }
        
   //     printf("%d\n",top);
        
        sum=0;
        for(i=1;i<=top;i++)
        {
       //    printf("%d\n",q[i].size);
           for(j=1;j<=q[i].size;j++)
           {
        //      printf("%d ",q[i].x[j]); 
              sum+=abs(q[i].mid-q[i].x[j]);
           }
          // printf("\n");
        }
        printf("%d\n",sum); 
           
    }
}
