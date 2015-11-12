#include<cstdio> 
#include<vector> 
#include<string>
#include<sstream>
#include<algorithm> 
using namespace std; 
vector < int > e[110],q; 
int n,m,tot,root,lab[110],son[110],d[110],pos[110],total; 
bool flag[110][110],tag[110],answer[110]; 
char ch[1000];

void dfs(int cur,int p) 
{ 
    int i,y,sum=0; 
    lab[cur]=son[cur]=++tot; 
    for(i=0;i<e[cur].size();++i) 
    { 
        y=e[cur][i]; 
        if(lab[y]==-1)   ////?????? 
        { 
            ++sum; 
            dfs(y,cur); 
			if(son[y]<son[cur])
				son[cur]=son[y];
            if(!tag[cur]) 
               continue; 
           if((cur==1&&sum>1)||(cur!=1&&son[y]>=lab[cur]))  ///???????????????2?????????... 
            { 
                 tag[cur]=false; 
                 ++total; 
           } 
        } 
        else if(y!=p&&lab[y]<son[cur]) 
            son[cur]=lab[y]; 
    } 
} 

void DFS(int cur) 
{ 
    int i,y; 
    answer[cur]=true; 
    for(i=0;i<e[cur].size();++i) 
    { 
        y=e[cur][i]; 
        if(!answer[y]) 
            DFS(y); 
    } 
} 

int main() 
{ 
    int i,first,t1,t2; 
    while(EOF!=scanf("%d",&n))    
    { 
		if(n==0)
			break;
        for(i=1;i<=n;++i) 
            e[i].clear(); 
        memset(flag,true,sizeof(flag)); 
        getchar();
        while(gets(ch)) 
        { 
           stringstream s(ch);
		   first=1;
		   while(s>>t2)
		   {
			   if(t2==0)
				   break;
               if(first)
			   {
				   t1=t2;
				   first=0;
				   continue;
			   }
			   if(t1==t2) 
                   continue;  
			   if(flag[t1][t2]) 
			   { 
                 e[t1].push_back(t2); 
                 e[t2].push_back(t1); 
                 flag[t1][t2]=flag[t2][t1]=false; 
			   } 
		   }
		   if(t2==0)
			   break;
        } 
        tot=0;
		total=0; 
        memset(lab,-1,sizeof(lab)); 
        memset(tag,true,sizeof(tag)); 
        dfs(1,-1);
		printf("%d\n",total);
    } 
    return 0; 
} 
