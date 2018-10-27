// Problem: 10004 - Bicoloring
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pb push_back
vector<int> color; // color works as check for visited as well
vector<vector<int> > g;
bool isBipartite = true;
void BFS_BipartiteCheck(int u);
int main(){
	int n, m;
	while(cin >> n && n!=0){
		isBipartite = true;
		g.clear(); color.clear();
		g.assign(n+2, vector<int> ());
		color.assign(n+2, -100);
		cin >> m;
		int u, v;
		for(int i=0; i<m; i++){
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		for(int i=0; i<n; i++){
			if(color[i] == -100)
				BFS_BipartiteCheck(i);
		}
		if(isBipartite){
			cout << "BICOLORABLE.\n";
		}else{
			cout << "NOT BICOLORABLE.\n";
		}
	}
	return 0;
}

void BFS_BipartiteCheck(int u){
	queue<int> q;
	q.push(u);
	color[u] = 0;
	while(!q.empty() && isBipartite){
		int v = q.front();
		q.pop();
		for(int j: g[v]){
			if(color[j] == -100){
				color[j] = 1-color[v]; // recording colors 0, 1 only
				q.push(j);
			}else if(color[j] == color[v]){
				isBipartite = false;
				break;
			}
		}
	}
}