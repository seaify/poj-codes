#include<stdio.h>
#include<string.h>
int main()
{
	char x[8];
	int y[8],z[132],temp[132],i,j,k,pos,n;
	while(EOF!=scanf("%s%d",x+1,&n))
	{
	
		for(i=1,k=1;i<=6;i++)
			if(x[i]=='.')
				pos=i-1;//小数点前的数字个数
			else
			{
				y[k]=z[k]=x[i]-'0';
			    k++;
			}
		for(k=1;k<n;k++)
		{
			memset(temp,0,sizeof(temp));
			for(i=1;i<=5*k;i++)//每次的个数最多为5*k，表示有时会在数组的前面有多余的0，只是为方便处理
				for(j=1;j<=5;j++)
					temp[i+j]+=z[i]*y[j];//高精度处理，留出temp[1]处理最前面的进位
			for(i=5*(k+1);i>=2;i--)//处理进位
			{
				temp[i-1]+=temp[i]/10;//向前进位
				temp[i]=temp[i]%10;
			}
			for(i=1;i<=5*(k+1);i++)//重新赋值
				z[i]=temp[i];
		}
		pos=n*pos+1;//小数点位置
		i=1;
		while(z[i]==0)//去掉前面的0
			i++;
		for(k=i;k<pos;k++)
			printf("%d",z[k]);
		j=5*n;
		while(z[j]==0)//去掉后面的0
			j--;
		if(pos<=j)//判断是否输出小数点有时
			printf(".");
		for(i=pos;i<=j;i++)
			printf("%d",z[i]);
		printf("\n");
                
	}
	return 0;
}