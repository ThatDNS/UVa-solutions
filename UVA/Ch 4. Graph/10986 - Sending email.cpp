// Problem: 10986 - Sending email
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
#define INF 1000000000

int main(){
	int test, n, m, s, t, u, v, w, cur=0;
	cin >> test;
	vector<vii> AdjList;
	while(test--){
		cin >> n >> m >> s >> t;
		AdjList.clear();
		AdjList.assign(n+1, vii());
		for(int i=0; i<m; i++){
			cin >> u >> v >> w;
			AdjList[u].pb(ii(v, w));
			AdjList[v].pb(ii(u, w));
		}
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		vi dist(n+1, INF); dist[s] = 0;
		pq.push(ii(0, s));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int i=0; i<(int)AdjList[u].size(); i++){
				ii v = AdjList[u][i];
				if(dist[u]+v.second < dist[v.first]){
					dist[v.first] = dist[u]+v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		printf("Case #%d: ", ++cur);
		if(dist[t] == INF)
			cout << "unreachable\n";
		else
			cout << dist[t] << endl;
	}
	return 0;
}
