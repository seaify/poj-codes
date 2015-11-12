#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x[110000],y[110000],e[110000],n,i,j,k;
__int64 cost,sum,t1,t2,m,t;
bool flag[110000];

int main()
{

    while(EOF!=scanf("%d",&n))
    {
        for(i=0;i<n;++i)
        {
            scanf("%d",&x[i]);
            y[i]=x[i];
        }
        sort(y,y+n);
        for(i=0;i<n;++i)
            e[y[i]]=x[i];
        memset(flag,true,sizeof(flag));
        cost=0;m=y[0];
        for(i=0;i<n;++i)
        {
            if(flag[y[i]])
            {
                sum=0,k=0,j=t=y[i];
                while(1)
                {
                   ++k;
                   flag[j]=false;
                   sum+=j;
                   if(e[j]==t)
                        break;
                   j=e[j];
                }
                if(k==1)
                   continue;
                cost+=sum;
                t1=(k-2)*t;
                t2=t+(k+1)*m;
                if(t1<t2)
                   cost+=t1;
                else
                   cost+=t2;
            }
        }
        printf("%I64d\n",cost);
    }
    return 0;
}
