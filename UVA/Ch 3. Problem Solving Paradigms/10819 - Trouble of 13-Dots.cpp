// Problem: 10819 - Trouble of 13-Dots
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

int favour(int id, int money);
int m, n, fav, price[105][15000];
int p[105], f[105];

int main(){
	while(cin >> m >> n){
		for(int i=0; i<n; i++)
			scanf("%d %d", &p[i], &f[i]);
		memset(price, -1, sizeof(price));
		printf("%d\n", favour(0, 0));
	}
	return 0;
}

int favour(int id, int money){
	if(money > m && m < 1800)
		return INT_MIN;
	if(money > m + 200)
		return INT_MIN;
	if(id == n){
		if(money > m && money <= 2000)
			return INT_MIN;
		return 0;
	}
	if(price[id][money] != -1) return price[id][money];
	return price[id][money] = max(favour(id+1, money), f[id] + favour(id+1, money+p[id]));
}

