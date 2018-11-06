// 10449 - Traffic
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
#define INF 1e9 // 10^9xs
int gcd(int a, int b);
int main(){
	short int n;
	int temp, m, u, v, w, quer, dest, cases=0;
	vector<vii> AdjList;
	vi busyness, dist, distT;
	set<int> negaPeople;
	while(cin >> n){
		busyness.clear(); busyness.pb(-1); // 0th node
		AdjList.clear(); negaPeople.clear();
		for(int i=0; i<n; i++){
			cin >> temp; busyness.pb(temp);
		}
		AdjList.assign(n+2, vii());
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> u >> v;
			w = pow(busyness[v]-busyness[u], 3);
			AdjList[u].pb(ii(v, w));
		}
		dist.clear(); distT.clear();
		dist.assign(n+2, INF); dist[1] = 0;
		distT.assign(n+2, INF); distT[1] = 0;
		for(int i=1; i<=n-1; i++){
			for(int u=1; u<=n; u++){
				for(int j=0; j<(int)AdjList[u].size(); j++){
					ii v = AdjList[u][j];
					if(dist[u]+v.second < dist[v.first]){
						if(dist[u] != INF)
							dist[v.first] = dist[u]+v.second;
					}
					if(distT[u]+v.second < distT[v.first]){
						if(distT[u] != INF)
							distT[v.first] = distT[u]+v.second;
					}
				}
			}
		}

		bool negaCycle = false;
		for(int i=1; i<=n-1; i++){
			for(int u=1; u<=n; u++){
				for(ii v: AdjList[u]){
					if(dist[v.first] > dist[u]+v.second){
						negaCycle = true;
					}
				}
			}
		}

		if(negaCycle){
			for(int i=1; i<=n-1; i++){
				for(int u=1; u<=n; u++){
					for(int j=0; j<(int)AdjList[u].size(); j++){
						ii v = AdjList[u][j];
						distT[v.first] = min(distT[v.first], distT[u]+v.second);
					}
				}
			}
			for(int i=0; i<(int)dist.size(); i++){
				if(distT[i]!=dist[i])
					negaPeople.insert(i);
			}
		}
		cin >> quer;
		printf("Set #%d\n", ++cases);
		while(quer--){
			cin >> dest;
			if(negaCycle && negaPeople.count(dest)){
				cout << "?\n";
			}else if(dist[dest] < 3 || dist[dest]==INF){
				cout << "?\n";
			}else{
				cout << dist[dest] << endl;
			}
		}
	}
	return 0;
}