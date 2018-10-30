// Problem: 524 - Prime Ring Problem
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define EPS 1e-9
#define pb push_back

void find(int ind);
bool isPrime(int n);
short int n, ind=0;
vector<int> chosen;
bool visited[20];

int main(){
	short int cases=0;
	while(cin >> n){
		chosen.clear(); chosen.assign(n, -1);
		chosen[0] = 1; chosen.pb(1);
		if(cases>=1) cout << endl;
		printf("Case %d:\n", ++cases);
		find(0);
	}
	return 0;
}

void find(int ind){
	if(ind == n-1 && isPrime(chosen[n-1]+chosen[n])){
		for(int i=0; i<n; i++)
			printf(i==n-1?"%d":"%d ", chosen[i]);
		printf("\n");
		return;
	}
	for(int i=2; i<=n; i++){
		if(!visited[i] && isPrime(chosen[ind]+i)){
			visited[i] = true;
			chosen[ind+1] = i;
			find(ind+1);
			visited[i] = false;
		}
	}
}

bool isPrime(int n){
	for(int i=2; i<=sqrt(n); i++)
		if(n%i == 0) return false;
	return true;
}
