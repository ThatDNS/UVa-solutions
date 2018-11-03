// Problem: 12160 - Unlock the Lock
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

short int L, U, R;
vi rv; vi dist;
void DFS();

int main(){
	int temp, cases=0;
	while(cin >> L >> U >> R && (L!=0 || U!=0 || R!=0)){
		rv.clear(); dist.clear();
		for(int i=0; i<R; i++){
			cin >> temp;
			rv.pb(temp);
		}
		dist.assign(10000, 0);
		DFS();
		printf("Case %d: ", ++cases);
		if(dist[U] != 0)
			cout << dist[U] << endl;
		else
			cout << "Permanently Locked\n";
	}
	return 0;
}

void DFS(){
	int temp;
	queue<int> q;
	q.push(L);
	dist[L] = 0;
	while(!q.empty()){
		if(dist[U] != 0) break;
		L = q.front(); q.pop();
		for(int i: rv){
			temp = L+i;
			if(temp >= 10000) temp %= 10000;
			if(dist[temp] == 0){
				dist[temp] = dist[L] + 1;
				q.push(temp);
			}
		}
	}
}
