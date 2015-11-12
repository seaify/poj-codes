#include<stdio.h>
int M,N,c[4]; 
int res[10],s[10];
void  mul(int *a,int *b,int t)
{
   c[0]=(a[0]*b[0]+a[1]*b[2])%10000;
   c[1]=(a[0]*b[1]+a[1]*b[3])%10000;
   c[2]=(a[2]*b[0]+a[3]*b[2])%10000;
   c[3]=(a[2]*b[1]+a[3]*b[3])%10000;
   if(t==1)
      res[0]=c[0],res[1]=c[1],res[2]=c[2],res[3]=c[3];
   else
      s[0]=c[0],s[1]=c[1],s[2]=c[2],s[3]=c[3];

}
void solve()
{ 
   res[0]=1,res[1]=0,res[2]=0,res[3]=1;
   s[0]=1,s[1]=1,s[2]=1,s[3]=0;
   while(N)//反复平方法求模
   {
     if(N&1)
       mul(res,s,1);
     mul(s,s,2);
     N>>=1;//cnt的二进制表示左移
   }
   printf("%d\n",res[1]);
}
int main()
{
  while(EOF!=scanf("%d",&N))
  {
	 if(N==-1)
		 break;
	 solve();
  }
  return 0;
}
