// Problem: 11450 - Wedding shopping
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

short int m, c;
int price[25][25];
int memo[220][25];
int calc(int money, int g);

int main(){
	int n, maxAmt;
	cin >> n;
	while(n--){
		cin >> m >> c;
		memset(memo, -1, sizeof(memo));
		for(int i=0; i<c; i++){
			scanf("%d", &price[i][0]);
			for(int j=1; j<=price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		maxAmt = calc(m, 0);
		if(maxAmt>=0)
			printf("%d\n", maxAmt);
		else
			printf("no solution\n");
	}
	return 0;
}

int calc(int money, int g){
	if(money<0) return INT_MIN;
	if(g == c) return m-money;
	if(memo[money][g] != -1)
		return memo[money][g];
	int ans = -1;
	for(int i=1; i<=price[g][0]; i++)
		ans = max(ans, calc(money-price[g][i], g+1));
	memo[money][g] = ans;
	return memo[money][g];
}


