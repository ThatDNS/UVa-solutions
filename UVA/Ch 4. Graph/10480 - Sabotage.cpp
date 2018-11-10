// Problem: 10480 - Sabotage
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

long long res[55][55], res2[55][55], mf, f, s, t;
vi p; vi dist;
set<int> inS;
void Augment(int, long long);

int main(){
	int n, m, u, v;
	long long wt;
	while(cin >> n >> m && (n!=0 || m!=0)){
		memset(res, 0, sizeof(res));
		memset(res2, 0, sizeof(res2));
		inS.clear();
		for(int i=0; i<m; i++){
			cin >> u >> v >> wt;
			res[u][v] = wt;
			res[v][u] = wt;
			res2[u][v] = wt;
			res2[v][u] = wt;
		}
		mf = 0;
		s = 1; t = 2;
		while(1){
			f = 0;
			dist.clear();
			dist.assign(n+2, INF); dist[s] = 0;
			queue<int> q; q.push(s);
			p.assign(n+2, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int v=1; v<=n; v++){
					if(res[u][v]>0 && dist[v]==INF){
						dist[v] = dist[u]+1;
						q.push(v); p[v] = u;
					}
				}
			}
			Augment(t, INF);
			if(f==0) break;
			mf += f;
		}
		s = 1; t = 2;
		// BFS:
		vb visited;
		visited.assign(n+2, false);
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while(!q.empty()){
			int u = q.front(); q.pop();
			inS.insert(u);
			for(int v=1; v<=n; v++){
				if(res[u][v]>0 && !visited[v]){
					q.push(v); visited[v] = true;
				}
			}
		}
		for(auto it=inS.begin(); it!=inS.end(); ++it){
			int u = *it;
			for(int v=1; v<=n; v++){
				if(res2[u][v]>0 && inS.count(v)==0){
					cout << u << " " << v << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

void Augment(int v, long long minEdge){
	if(v==s){
		f = minEdge;
		return;
	}else if(p[v] != -1){
		Augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
