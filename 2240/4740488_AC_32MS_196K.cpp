#include<stdio.h>
#include<string.h>
const int maxn=35;
double d[maxn][maxn],f[maxn][maxn],value;
char map[maxn][50],temp[50];
bool flag;
int main()
{
 int i,j,k,m,n,t;
 t=0;
 while(EOF!=scanf("%d",&n)&&n)
 {
 for(i=1;i<=n;i++)
	 scanf("%s",map[i]);
 scanf("%d",&m);
 memset(d,0,sizeof(d));
 memset(f,0,sizeof(f));
 for(i=1;i<=n;i++)
	 f[i][i]=d[i][i]=1.0;
 while(m--)
 {
	scanf("%s",temp);
	for(k=1;k<=n;k++)
		if(strcmp(map[k],temp)==0)
		{
		   i=k;
		   break;
		}
    scanf("%lf",&value);
	scanf("%s",temp);
	for(k=1;k<=n;k++)
		if(strcmp(map[k],temp)==0)
		{
			j=k;
			break;
		}
  f[i][j]=d[i][j]=value;
 }
  for(k=1;k<=n;k++)
	 for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
			 if(d[i][j]<d[i][k]*d[k][j])
				 d[i][j]=d[i][k]*d[k][j];
  flag=false;
  for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
		 if(d[i][j]*f[j][i]>1.0)
		 {
			 flag=true;
			 break;
		 }
  if(flag)
	  printf("Case %d: Yes\n",++t);
  else
	  printf("Case %d: No\n",++t);
 }
  return 0;
}