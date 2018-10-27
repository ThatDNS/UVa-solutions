// Problem: 11080 - Place the Guards
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
vector<int> color;
vector<vector<int> > g;
bool isBipartite = true;
int BFS_BipartiteCheck(int u);
int main(){
	int t, v, e;
	cin >> t;
	while(t--){
		cin >> v >> e;
		isBipartite = true;
		g.clear(); color.clear();
		g.assign(v+2, vector<int> ());
		color.assign(v+2, -100);
		int a, b;
		for(int i=0; i<e; i++){
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int ans=0;
		for(int i=0; i<v; i++){
			if(color[i] == -100){
				int abc = BFS_BipartiteCheck(i);
				if(abc==-1)
					isBipartite=false;
				else
					ans+=abc;
			}
		}
		if(isBipartite){
			cout << ans << endl;
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}

int BFS_BipartiteCheck(int u){
	queue<int> q;
	q.push(u);
	color[u] = 1;
	int total=0, black=0;
	while(!q.empty() && isBipartite){
		int v = q.front();
		q.pop();
		total++;
		if(color[v]==1) black++;
		for(int j: g[v]){
			if(color[j] == -100){
				color[j] = 1-color[v];
				q.push(j);
			}else if(color[j] == color[v]){
				isBipartite = false;
				return -1;
			}
		}
	}
	if(total==1)
		return 1;
	else
		return min(black, total-black);
}