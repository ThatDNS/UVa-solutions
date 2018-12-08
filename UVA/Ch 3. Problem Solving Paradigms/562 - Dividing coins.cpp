// Problem: 562 - Dividing coins
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
#define INF 1e9 // 10^9

short int m, coins[120];
int sum, value[120][50000];
int val(int id, int remW);

int main(){
	int n, val1, val2;
	cin >> n;
	while(n--){
		cin >> m; sum=0;
		for(int i=0; i<m; i++){
			scanf("%hd", &coins[i]);
			sum += coins[i];
		}
		for(int i=0; i<m+2; i++)
			for(int j=0; j<sum; j++)
				value[i][j] = -1;
		val1 = val(0, sum/2);
		val2 = sum-val1;
		cout << abs(val2-val1) << endl;
	}
	return 0;
}

int val(int id, int remW){
	if(id==m || remW==0) return 0;
	if(coins[id] > remW) return value[id][remW] = val(id+1, remW);
	if(value[id][remW]!=-1)
		return value[id][remW];
	return value[id][remW] = max(val(id+1, remW), coins[id] + val(id+1, remW-coins[id]));
}
