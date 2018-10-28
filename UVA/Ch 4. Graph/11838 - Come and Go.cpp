// Problem: 
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vb vector<bool>
#define EPS 1e-9
#define pb push_back
vi dfs_low, dfs_num, S;
vb visited;
int dfsCounter, numSSC=0;
vector<vector<int> > adjList;
void tarjanSSC(int u);
int main(){
	unsigned int n, m, a, b, c;
	while(cin >> n >> m && (n!=0 && m!=0)){
		dfsCounter=0; numSSC=0;
		dfs_num.clear(); dfs_low.clear(); visited.clear(); adjList.clear();
		dfs_num.assign(n+2, -1);
		dfs_low.assign(n+2, 0);
		visited.assign(n+2, false);
		adjList.assign(n+2, vector<int>());
		for(int i=0; i<m; i++){
			cin >> a >> b >> c;
			if(c==1){
				adjList[a].pb(b);
			}else if(c==2){
				adjList[a].pb(b);
				adjList[b].pb(a);
			}
		}
		for(int i=1; i<=n; i++){
			if(dfs_num[i] == -1)
				tarjanSSC(i);
		}
		if(numSSC==1)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}

void tarjanSSC(int u){
	dfs_low[u] = dfsCounter;
	dfs_num[u] = dfsCounter;
	S.pb(u);
	++dfsCounter;
	visited[u] = true;
	for(int v: adjList[u]){
		if(dfs_num[v] == -1)
			tarjanSSC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		++numSSC;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			if(u==v) break;
		}
	}
}
