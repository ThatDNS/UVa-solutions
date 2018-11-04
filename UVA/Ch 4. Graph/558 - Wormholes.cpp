// Problem: 558 - Wormholes
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

int main(){
	short int c, n, m, u, v, w;
	vector<vii> AdjList;
	vi dist;
	cin >> c;
	while(c--){
		cin >> n >> m;
		AdjList.clear(); dist.clear();
		AdjList.assign(n+2, vii());
		for(int i=0; i<m; i++){
			cin >> u >> v >> w;
			AdjList[u].pb(ii(v, w));
		}
		dist.assign(n+2, INF); dist[0] = 0;
		for(int i=0; i<n-1; i++){
			for(int u=0; u<n; u++){
				for(int j=0; j<(int)AdjList[u].size(); j++){
					ii v = AdjList[u][j];
					dist[v.first] = min(dist[v.first], dist[u]+v.second);
				}
			}
		}
		bool bigbang=false;
		for(int u=0; u<n; u++){
			for(int j=0; j<(int)AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				if(dist[v.first] > dist[u]+v.second){
					bigbang = true;
					j = (int)AdjList[u].size(); u = n;
				}
			}
		}
		if(bigbang)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}
