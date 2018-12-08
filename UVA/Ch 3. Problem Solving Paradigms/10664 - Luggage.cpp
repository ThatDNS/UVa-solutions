// Problem: 10664 - Luggage
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

short int n, wt[25];
int sum, value[25][250];
int val(int id, int remW);

int main(){
	int m, val1;
	string s;
	cin >> m;
	getchar();
	while(m--){
		sum=0;
		getline(cin, s);
		istringstream is(s);
		int i=0;
		while(is >> wt[i]){
			sum += wt[i]; ++i;
		}
		n = i;
		for(int i=0; i<n+2; i++)
			for(int j=0; j<sum; j++)
				value[i][j] = -1;
		val1 = val(0, sum/2);
		if(val1 == sum-val1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int val(int id, int remW){
	if(id==n || remW==0) return 0;
	if(wt[id] > remW) return value[id][remW] = val(id+1, remW);
	if(value[id][remW]!=-1)
		return value[id][remW];
	return value[id][remW] = max(val(id+1, remW), wt[id] + val(id+1, remW-wt[id]));
}
