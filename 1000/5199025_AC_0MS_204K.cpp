#include<stdio.h>
int main()
{
  int a,b,c;
  scanf("%d %d",&a,&b);
  __asm
  {
	 mov eax,a;
	 mov ebx,b;
	 add eax,ebx;
	 mov c,eax;
  }
  printf("%d\n",c);
  return 0;
}