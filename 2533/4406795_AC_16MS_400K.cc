//第2种方法时间复杂度为O(nlogn)，用到了二分查找和贪心。
///其操作如下：
//这也是很好理解的，对x和y，如果x<y且E[y]<E[x],用E[x]替换E[y],此时的最长序列长度没有改变但序列Q的''潜力''增大。
//栈为1，5，8，此时读到3，则用3替换5，得到栈中元素为1，3，8，再读6，用6替换8，得到1，3，6，再读7，得到最终栈为1，3，6，7，最长递增子序列为长度4。
//代码如下：//

 

#include<iostream>
using namespace std;
int n;
int a[1001],b[1001];
int rear;
int solve(int t)
{   int l=1,r=rear;
    while(l<=r)
    {   int mid=(l+r)>>1;
        if(b[mid]>=t)//若为非递减序列，则为b[mid]>t
            r=mid-1;
        else 
            l=mid+1;
    }
    if(l>rear)
       rear=l;
    return l;
}
int main()
{   int i;
    scanf("%d",&n);
    rear=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[solve(a[i])]=a[i];
    }
    printf("%d\n",rear);
    return 0;
}




