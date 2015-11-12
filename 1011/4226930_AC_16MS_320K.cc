#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int all,find1,res,times,used[65],stick[65];
int maxlen,lenth,sum;
void dfs(int no, int curlen, int level);
void fit(int no)
{
    int i;
    if(find1==1 || no>res)
    {
        find1 = 1;
        return ;
    }
    for(i=0; i<all; i++)
    {
        if(!used[i])
            break;
    }
    used[i] = 1;
    times++;
    dfs(no, stick[i], i);
    times--;
    used[i] = 0;
}
void dfs(int no, int curlen, int level)
{
    if(curlen == lenth)
    {
        fit(no+1);
        return ;
    }
    if(find1==1)
        return ;
    int i,j;
    for(i=level+1; i<all; i++)
    {
        if(!used[i] && curlen+stick[i]<=lenth)
        {
            if(all-times+1<res-no)
                return ;
            used[i] = 1;
            times++;
            dfs(no, curlen+stick[i], i);
            times--;
            used[i] = 0;
            j=i;
            if(find1==1)
                return ;
            while(i<all && stick[j]==stick[i])
                i++;
            if(i==all)return ;
            if(i!=j)i--;
        }
    }
}
void work()
{
    if(sum%res!=0)
        return ;
    lenth = sum / res;
    if(maxlen > lenth)
        return ;
    times = 0;
    fit(1);
}
int main()
{
    int i;
    while(1)
    {
        sum = 0;
        maxlen = 0;
        scanf("%d", &all);
        if(all==0)
            break;
        for(i=0; i<all; i++)
        {
            scanf("%d", &stick[i]);
            if(maxlen<stick[i])
                maxlen = stick[i];
            sum += stick[i];
        }
        sort(stick, stick+all, greater<int>());
        memset(used, 0, sizeof(used));
        times = 0;
        for(res=all; res>0; res--)
        {
            find1 = 0;
            work();
            if(find1==1)
                break;
        }
        printf("%d\n",sum / res);
    }
    return 0;
}