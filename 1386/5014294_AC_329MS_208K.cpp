#include<stdio.h>
#include<string.h>
bool map[30][30],flag[30];
int first,in[30];
char a[1100];
void dfs(int cur)
{
   int i;
   flag[cur]=true;
   ++first;
   for(i=0;i<26;++i)
      if(!flag[i]&&map[cur][i])
         dfs(i);
} 
int main()
{
   int i,T,x,y,tag,n,k,last,tot;
   scanf("%d",&T);
   while(T--)
   {
     scanf("%d",&n);
     memset(map,0,sizeof(map));
     memset(in,0,sizeof(in)); 
     memset(flag,false,sizeof(flag));
     tot=0;//顶点个数。。。。 
     while(n--)
     {
        scanf("%s",a);
        k=strlen(a);
        x=a[0]-'a';//下标从0出发。。。。 
        y=a[k-1]-'a';
        ++in[y],--in[x];//入度。。。。 
        map[x][y]=true;
        if(!flag[x])
        {
           ++tot;
           flag[x]=true;
        }
        if(!flag[y])
        {
           ++tot;
           flag[y]=true;
        }
     }
     for(i=0;i<26;++i)
     {
        memset(flag,false,sizeof(flag));
        first=0;
        dfs(i);
        if(first==tot)
           break;
     }
     if(i==26)
     {
        printf("The door cannot be opened.\n");
        continue;
     } 
     tag=1;first=0;last=0;
     for(i=0;i<26;++i)
        if(in[i]==0)
           continue;
        else if(in[i]==1)
           ++first;
        else if(in[i]==-1)
           ++last;
        else 
        {
           tag=0;
           break;
        }
     if(tag&&first==last&&first<=1)
         printf("Ordering is possible.\n");
     else
         printf("The door cannot be opened.\n");         
   }
   return 0;
}
