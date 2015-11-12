#include<stdio.h>
#include<string.h>
char a[30],b[30];
void out(int left1,int right1,int left2,int right2)
{
  int i;
  if(left1>right1||left2>right2)
	  return ;
  i=left2;
  while(b[i]!=a[left1])
	  ++i;
  out(left1+1,i+left1-left2,left2,i-1);
  out(i+left1-left2+1,right1,i+1,right2);
  printf("%c",b[i]);
}
int main()
{
  int n;
  while(EOF!=scanf("%s%s",a,b))
  {
	n=strlen(a);
	out(0,n-1,0,n-1);
	printf("\n");
  }
  return 0;
}
