#include<stdio.h>
#include<string.h>
const int maxn=16000005;
const int M=99991;
char a[maxn],b[maxn];
int i,j,len,n,NC,sum,tot,p[200005],first[100000];
bool flag[100000];
struct node
{
   char ch[10000];
   int next;
};
node edge[100000];
void ELFhash(char *key)
{
  int k,temp;
  ++tot;
  memset(b,0,sizeof(b));
  strncpy(b,key,n);
  unsigned long h=0;
  temp=n;
  while(temp--)
  {
     h=(h<<4)+*key++;
     unsigned long g=h & 0xf0000000L;
     if(g)
        h^=g>>24;
     h&=~g;
  }
  k=h%M;
  temp=first[k];
  while(temp!=-1)
  {
    if(strcmp(edge[temp].ch,b)==0)
              return ;
    temp=edge[temp].next;
  }//说明是新的字符串。。。 
  edge[tot].next=first[k];
  strcpy(edge[tot].ch,b);
  first[k]=tot;
  ++sum;
}
void solve()
{
   tot=M;sum=0;
   memset(flag,false,sizeof(flag));
   memset(first,-1,sizeof(first));
   len=strlen(a);
   for(i=0;i<=len-n;++i)
       ELFhash(a+i);    
   printf("%d\n",sum);  
}
int main()
{
   while(EOF!=scanf("%d%d",&n,&NC))
   {
     scanf("%s",a);
     solve();
   }
}
