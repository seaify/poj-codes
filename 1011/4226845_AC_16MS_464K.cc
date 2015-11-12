#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int stick[100];
bool used[100], ok;
int total, num, n, side;
void search(int tot, int tside, int k);

bool cmp(int a, int b)
{
	return a > b;
}


void check(int t){
 	 if(t > num) {
			ok = true;
			cout<<side<<endl;
	 		return ;
		}
 	 
 	 int i;
 	 for(i = 0; i < n ; i++)
 	 	if(!used[i]) break;
	 
	 used[i] = true;
	 search(t, stick[i], i+1); 
	 used[i] = false;
}

void search(int tot, int tside, int k)
{
	if(ok) return ;
	if(tside == side) {
		check(tot+1);
		return ;
		}
	if(k >= n) return ;
	for(int i = k; i < n; i++) {
		if(!used[i] && stick[i] + tside <= side) {
			used[i] = true;
			search(tot, (tside+stick[i]), i+1);
			if(ok) return ;
			used[i] = false;
			if(side - tside == stick[i]) return ;
			}
		}
		return ;
}

int main()
{ 	
	while(cin>>n && n) {
		int i;
		for(total = 0, i = 0; i < n; i++) {
			scanf("%d", &stick[i]);
			total += stick[i];
			}
		sort(stick, stick+n, cmp);
		ok = false;
		memset(used, false, sizeof(used));
		for( side = stick[0]; side <= total && !ok; side++) {
			if(total % side == 0) {
				num = total / side;
				check(1);
				if(ok) break;
				}
			}
		//cout<<side<<endl;
		}
 	return 0;
}

