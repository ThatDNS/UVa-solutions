// Problem: 10305 - Ordering Tasks
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
stack<int> ans;
vector<vector<int> > graph;
vector<bool> visited;
void DFS(int u);
int main(){
	int n, m, a, b;
	while(cin >> n >> m && (n!=0)){
		visited.clear();
		graph.clear();
		visited.assign(n+2, false);
		graph.assign(n+2, vector<int> ());
		for(int i=0; i<m; i++){
			cin >> a >> b;
			graph[a].pb(b);
		}
		for(int i=1; i<=n; i++){
			if(!visited[i])
				DFS(i);
		}
		cout << endl;
		while(!ans.empty()){
			a = ans.top();
			if(ans.size()>1)
				cout << a << " ";
			else
				cout << a << "\n";
			ans.pop();
		}
	}
	return 0;
}

void DFS(int u){
	visited[u] = true;
	cout << u << " ";
	for(int v: graph[u]){
		if(!visited[v])
			DFS(v);
	}
	ans.push(u);
}