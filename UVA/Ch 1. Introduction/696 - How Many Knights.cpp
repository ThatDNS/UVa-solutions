// 696 - How Many Knights
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

bool board[505][505];
short int m, n;

int main(){
	int knights=0, maxx, minn;
	while(cin >> m >> n){
		if(m==0 && n==0)
			break;
		minn = min(m, n);
		maxx = max(m, n);
		knights = 0;
		if(minn == 1){
			knights = maxx;
		}else if(minn == 2){
			int count=0;
			if(m==2) maxx = n;
			else maxx = m;
			for(int i=0; i<maxx; i++){
				if(count == 4)
					count = 0;
				if(count < 2){
					++knights;
					++count;
				}else if(count < 4){
					++count;
				}
			}
			knights *= 2;
		}else{
			knights = (m*n + 1)/2;
		}
		printf("%d knights may be placed on a %d row %d column board.\n", knights, m, n);
	}
	return 0;
}
