#include<iostream>

int N,ans;
int a[40000],b[40000],q[40000];

void solve(int *x)  ////最长上升子序列... 
{
    int i,left,right,mid,top;
    top=1;
    q[1]=x[1];
    for(i=2;i<=N;i++)
    {
        if(x[i]>=q[top])
             q[++top]=x[i];
        else
        {
             left=1;
             right=top;
             while(left<=right)
             {
                  mid=(left+right)>>1;
                  if(q[mid]<=x[i])
                       left=mid+1;
                  else
                       right=mid-1;
             }
             q[left]=x[i];
        }
    } 
    if(top>=ans)
        ans=top;
}

int main()
{
    int i,j;
    
    while(EOF!=scanf("%d",&N))
    {
                              
          j=N;
          for(i=1;i<=N;i++,j--)
          {
              scanf("%d",&a[i]);
              b[j]=a[i];
          }
          
          ans=-1;
          
          solve(a);
          
          solve(b);
          
          printf("%d\n",N-ans); 
              
              
    }
    return 0;
} 
