#include<stdio.h>
#include<stdlib.h>


int cmp( const void *e1, const void *e2){
	return *(int *)e2-*(int *)e1;
};

int money[20001];


int main()
{
	int i;
	int n;
	int t,sum;

	while(scanf("%d",&t)!=EOF){
		while(t--){
	sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&money[i]);
	qsort(money,n,sizeof(money[0]),cmp);

	for(i=2;i<n;i+=3)
		sum+=money[i];
	printf("%d\n",sum);

	}

	}
    return 0;


}