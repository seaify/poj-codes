#include<cstdio> 
#include<iostream>
#include<vector> 
#include<string>
#include<sstream>
#include<algorithm> 
using namespace std; 
vector < int > e[1100],q; 
int n,m,tot,root,lab[1100],son[1100],d[1100],pos[1100],total; 
bool flag[1100][1100],tag[1100],answer[1100]; 
string ch;

int minx(int a,int b) 
{ 
    if(a<b) 
        return a; 
    return b; 
} 

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
            son[cur]=minx(son[cur],son[y]); 
            if(!tag[cur]) 
               continue; 
           if((cur==1&&sum>1)||(cur!=1&&son[y]>=lab[cur]))  ///???????????????2?????????... 
            { 
                 tag[cur]=false; 
                 ++total; 
           } 
        } 
        else if(y!=p) 
            son[cur]=minx(son[cur],lab[y]); 
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
        while(getline(cin,ch)) 
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
        memset(son,-1,sizeof(son)); 
        memset(tag,true,sizeof(tag)); 
        dfs(1,-1);
		printf("%d\n",total);
	//	getchar();
    } 
    return 0; 
} 


