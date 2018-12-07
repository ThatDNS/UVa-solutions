// Problem: 10130 - SuperSale
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

int knap(int curr, int remW);
short int tc, n, g;
int P[1002], W[1002], Wt[102];
int price[1002][35];

int main(){
	int netVal;
	cin >> tc;
	while(tc--){
		netVal = 0;
		cin >> n;
		for(int i=0; i<n; i++)
			scanf("%d %d", &P[i], &W[i]);
		for(int i=0; i<n; i++)
			for(int j=0; j<32; j++)
				price[i][j] = -1;
		cin >> g;
		for(int i=0; i<g; i++){
			scanf("%d", &Wt[i]);
			netVal += knap(0, Wt[i]);
		}
		printf("%d\n", netVal);
	}
	return 0;
}

int knap(int curr, int remW){
	if(curr == n || remW == 0) return 0;
	if(price[curr][remW] != -1) return price[curr][remW];
	if(W[curr] > remW) return price[curr][remW]=knap(curr+1, remW);
	return price[curr][remW] = max(P[curr] + knap(curr+1, remW-W[curr]), knap(curr+1, remW));
}

