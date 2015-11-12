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
			for(i=1;i<=5*k;i++)
				for(j=1;j<=5;j++)
					temp[i+j]+=z[i]*y[j];
			for(i=5*(k+1);i>=2;i--)
			{
				temp[i-1]+=temp[i]/10;
				temp[i]=temp[i]%10;
			}
			for(i=1;i<=5*(k+1);i++)
				z[i]=temp[i];
		}
		pos=n*pos+1;//小数点位置
		i=1;
		while(z[i]==0)
			i++;
		for(k=i;k<pos;k++)
			printf("%d",z[k]);
		j=5*n;
		while(z[j]==0)
			j--;
		if(pos<=j)
			printf(".");
		for(i=pos;i<=j;i++)
			printf("%d",z[i]);
		printf("\n");
                
	}
	return 0;
}