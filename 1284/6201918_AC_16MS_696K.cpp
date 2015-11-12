#include<iostream>
using namespace std;
const int MAX=100000;
int pri[MAX/3],pn=0;
char notp[MAX]={0};
int phi[MAX];

void phif(void)
{
    for(int i=2;i<MAX;i++){
        if(notp[i]==0){
            pri[pn++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<pn&&MAX>pri[j]*i;j++){
            notp[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            else
                phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
}
int main(void)
{
    phif();
    int n;
    while(EOF!=scanf("%d",&n)){
        printf("%d\n",phi[n-1]);
    }
    return 0;
}
